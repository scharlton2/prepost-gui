#include "rawdatanetcdfgdalimporter.h"
#include "rawdatanetcdf.h"
#include <guicore/pre/gridcond/base/gridrelatedconditiondimensionscontainer.h>
#include <guicore/pre/gridcond/base/gridrelatedconditiondimensioncontainer.h>
#include <guicore/solverdef/solverdefinitiongridrelatedconditiondimension.h>
#include <guicore/pre/base/preprocessorrawdatagroupdataiteminterface.h>
#include <misc/stringtool.h>
#include <misc/filesystemfunction.h>
#include <guibase/coordinatesystem.h>
#include <guibase/coordinatesystembuilder.h>
#include <guicore/base/iricmainwindowinterface.h>

#include <gdal_priv.h>
#include <ogr_spatialref.h>

#include <QMessageBox>
#include <QApplication>
#include <QProcess>
#include <QList>
#include <QFileInfo>

const QStringList RawDataNetcdfGdalImporter::fileDialogFilters()
{
	QStringList ret;
	ret.append(tr("GeoTiff files(*.tif)"));
	return ret;
}

const QStringList RawDataNetcdfGdalImporter::acceptableExtensions()
{
	QStringList ret;
	ret.append("tif");
	return ret;
}

bool RawDataNetcdfGdalImporter::doInit(const QString& filename, const QString& /*selectedFilter*/, int* count, SolverDefinitionGridRelatedCondition* condition, PreProcessorRawDataGroupDataItemInterface* item, QWidget* w)
{
	// investigate the condition.
	const QList<SolverDefinitionGridRelatedConditionDimension*>& dims = condition->dimensions();
	if (dims.size() != 0) {
		QMessageBox::warning(w, tr("Warning"), tr("GDAL data files can be imported for grid conditions without dimensions."));
		return false;
	}

	GDALAllRegister();

	m_dataset = (GDALDataset*)(GDALOpen(iRIC::toStr(filename).c_str(), GA_ReadOnly));
	if (m_dataset == NULL) {
		// failed opening.
		return false;
	}

	*count = m_dataset->GetRasterCount();
	m_count = *count;

	m_sr = new OGRSpatialReference();
	char* geoRef;
	geoRef = const_cast<char*>(m_dataset->GetProjectionRef());
	OGRErr err = m_sr->importFromWkt(&geoRef);
	if (err != OGRERR_NONE) {return false;}

	char* projDef;

	m_sr->exportToProj4(&projDef);
	m_coordinateSystem = item->iricMainWindow()->coordinateSystemBuilder()->buildFromProj4String(projDef);
	m_coordinateSystem->setName(projDef);
	if (m_coordinateSystem == nullptr) {return false;}

	CPLFree(projDef);

	err = m_dataset->GetGeoTransform(m_transform);
	if (err != CE_None) {
		return false;
	}

	return true;
}

bool RawDataNetcdfGdalImporter::importData(RawData* data, int index, QWidget* w)
{
	RawDataNetcdf* netcdf = dynamic_cast<RawDataNetcdf*>(data);

	GDALRasterBand* band = m_dataset->GetRasterBand(index + 1);
	int xsize, ysize;
	int gotMin, gotMax;
	double minmax[2];
	xsize = band->GetXSize();
	ysize = band->GetYSize();
	netcdf->m_coordinateSystemType = RawDataNetcdf::XY;
	netcdf->m_coordinateSystemName = m_coordinateSystem->name();
	netcdf->m_xValues.clear();
	for (int i = 0; i < xsize; ++i) {
		netcdf->m_xValues.append(m_transform[0] + m_transform[1] * i);
	}
	netcdf->m_yValues.clear();
	for (int i = 0; i < ysize; ++i) {
		netcdf->m_yValues.append(m_transform[3] + m_transform[5] * (ysize - 1 - i));
	}

	netcdf->m_lonValues.clear();
	for (int j = 0; j < netcdf->m_yValues.size(); ++j) {
		double y = netcdf->m_yValues.at(j);
		for (int i = 0; i < netcdf->m_xValues.size(); ++i) {
			double x = netcdf->m_xValues.at(i);
			double lon, lat;
			m_coordinateSystem->mapGridToGeo(x, y, &lon, &lat);
			netcdf->m_lonValues.append(lon);
			netcdf->m_latValues.append(lat);
		}
	}

	int ncid_out;
	int ret;

	QFileInfo finfo(netcdf->filename());
	iRIC::mkdirRecursively(finfo.absolutePath());

	// delete the file if it already exists.
	QFile f(netcdf->filename());
	f.remove();

	ret = nc_create(iRIC::toStr(netcdf->filename()).c_str(), NC_NETCDF4, &ncid_out);

	// save coordinates and dimensions to the netcdf file.
	int out_xDimId, out_yDimId, out_lonDimId, out_latDimId;
	int out_xVarId, out_yVarId, out_lonVarId, out_latVarId;
	QList<int> dimIds;

	int varOutId;

	ret = nc_redef(ncid_out);
	netcdf->defineCoords(ncid_out, &out_xDimId, &out_yDimId, &out_lonDimId, &out_latDimId, &out_xVarId, &out_yVarId, &out_lonVarId, &out_latVarId);
	netcdf->defineValue(ncid_out, out_xDimId, out_yDimId, dimIds, &varOutId);

	ret = nc_enddef(ncid_out);
	netcdf->outputCoords(ncid_out, out_xVarId, out_yVarId, out_lonVarId, out_latVarId);

	outputValues(ncid_out, varOutId, band, netcdf);

	nc_close(ncid_out);

	if (index == m_count - 1) {
		GDALClose(m_dataset);
	}
	netcdf->updateShapeData();
	netcdf->handleDimensionCurrentIndexChange(0, 0);

	return true;
}
