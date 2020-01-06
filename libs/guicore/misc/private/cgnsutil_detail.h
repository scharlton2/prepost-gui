#ifndef CGNSUTIL_DETAIL_H
#define CGNSUTIL_DETAIL_H

#include "../cgnsutil.h"

#include <cgnslib.h>

template<typename V>
int CgnsUtil::loadArrayWithName(const std::string& name, std::vector<V>* vals)
{
	int id = arrayIdWithName(name);
	if (id == 0) {return 1;}

	char n[ProjectCgnsFile::BUFFERLEN];
	DataType_t dataType;
	int dim;
	cgsize_t dimVec;
	int ier;

	ier = cg_array_info(id, n, &dataType, &dim, &dimVec);
	if (ier != 0) {return ier;}

	vals->assign(dimVec, 0);
	return cg_array_read(id, vals->data());
}

template<typename V>
int CgnsUtil::loadArrayWithName(const std::string& name, const std::string& suffix, std::vector<V>* vals)
{
	std::string tmpname = name;
	tmpname.append("_");
	tmpname.append(suffix);

	return loadArrayWithName(tmpname, vals);
}

template<class T, class DA>
void CgnsUtil::loadScalarDataT(const QString& name, vtkDataSetAttributes* atts, int index, int datalen, const QString& IBCName)
{
	std::vector<T> data(datalen, 0);
	cg_array_read(index, data.data());
	vtkSmartPointer<DA> tmpArray = vtkSmartPointer<DA>::New();
	tmpArray->SetName(iRIC::toStr(name).c_str());
	tmpArray->Allocate(datalen);
	if (IBCName == name) {
		// for IBC values, special handling is done: 0 is inactive the others are all active.
		for (int i = 0; i < datalen; ++i) {
			int val = static_cast<int>(data[i]);
			if (val != 0) {data[i] = 1;}
			tmpArray->InsertNextValue(data[i]);
		}
	} else {
		for (int i = 0; i < datalen; ++i) {
			tmpArray->InsertNextValue(data[i]);
		}
	}
	atts->AddArray(tmpArray);
}

template<class T, class DA>
void CgnsUtil::loadVectorDataT(const QString& name, vtkDataSetAttributes* atts, int iX, int iY, int iZ, int datalen)
{
	std::vector<T> dataX(datalen, 0);
	std::vector<T> dataY(datalen, 0);
	std::vector<T> dataZ(datalen, 0);
	std::vector<double> dataMag(datalen, 0);
	// read x.
	cg_array_read(iX, dataX.data());
	// read y.
	if (iY != 0) {
		cg_array_read(iY, dataY.data());
	}
	// read z
	if (iZ != 0){
		cg_array_read(iZ, dataZ.data());
	}
	for (int i = 0; i < datalen; ++i) {
		double sum = 0;
		sum += dataX[i] * dataX[i];
		sum += dataY[i] * dataY[i];
		sum += dataZ[i] * dataZ[i];
		dataMag[i] = std::sqrt(sum);
	}
	vtkSmartPointer<DA> tmpArray = vtkSmartPointer<DA>::New();
	tmpArray->SetName(iRIC::toStr(name).c_str());
	tmpArray->SetNumberOfComponents(3);
	tmpArray->Allocate(datalen);
	for (int i = 0; i < datalen; ++i) {
		tmpArray->InsertNextTuple3(dataX[i], dataY[i], dataZ[i]);
	}
	atts->AddArray(tmpArray);

	vtkSmartPointer<vtkDoubleArray> magArray = vtkSmartPointer<vtkDoubleArray>::New();
	QString magName = name;
	magName.append(" (magnitude)");
	magArray->SetName(iRIC::toStr(magName).c_str());
	magArray->Allocate(datalen);
	for (int i = 0; i < datalen; ++i) {
		magArray->InsertNextValue(dataMag[i]);
	}
	atts->AddArray(magArray);
}

#endif // CGNSUTIL_DETAIL_H

