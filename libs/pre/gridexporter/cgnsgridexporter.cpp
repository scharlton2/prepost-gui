#include "cgnsgridexporter.h"

#include <guicore/pre/grid/grid.h>
#include <guicore/project/projectcgnsfile.h>
#include <guicore/project/projectdata.h>
#include <guicore/solverdef/solverdefinition.h>
#include <misc/stringtool.h>

#include <cgnslib.h>
#include <iriclib.h>

CgnsGridExporter::CgnsGridExporter()
	: GridInternalExporter()
{
}

QString CgnsGridExporter::caption() const
{
	return tr("CGNS file");
}

const QStringList CgnsGridExporter::fileDialogFilters()
{
	QStringList ret;
	ret << QObject::tr("CGNS files (*.cgn)");
	return ret;
}

bool CgnsGridExporter::doExport(Grid* grid, const QString& filename, const QString& /*selectedFilter*/, QWidget* /*parent*/)
{
	QString tmpname;
	int fn, B;
	// create temporary CGNS file.
	bool ret = createTempCgns(grid, tmpname, fn, B);
	if (! ret) {return false;}

	// write to the iRICZone.
	ret = grid->saveToCgnsFile(fn, B, "iRICZone");

	ret = closeAndMoveCgns(tmpname, fn, filename);
	return ret;
}

bool CgnsGridExporter::createTempCgns(Grid* grid, QString& tmpname, int& fn, int& B)
{
	tmpname = getProjectData(grid)->tmpFileName();
	ProjectCgnsFile::createNewFile(tmpname, 2, 2);
	const SolverDefinitionAbstract* solverDef = &(getProjectData(grid)->solverDefinition()->abstract());
	ProjectCgnsFile::writeSolverInfo(tmpname, solverDef);

	int iret;
	iret = cg_open(iRIC::toStr(tmpname).c_str(), CG_MODE_MODIFY, &fn);
	if (iret != 0) {return false;}
	iret = cg_iRIC_GotoBase(fn, &B);
	if (iret != 0) {
		cg_close(fn);
		return false;
	}
	return true;
}

bool CgnsGridExporter::closeAndMoveCgns(const QString& tmpname, int fn, const QString& cgnsname)
{
	cg_close(fn);

	// if it already exists, remove it first.
	QFile cgnsfile(cgnsname);
	if (cgnsfile.exists()) {
		cgnsfile.remove();
	}
	// copy to the specified file.
	bool ret = QFile::copy(tmpname, cgnsname);
	if (! ret) {return false;}
	// Delete the temporary file
	QFile::remove(tmpname);

	return true;
}
