#include "ui_cgnsfileinputconditiondialog.h"

#include "../../solverdef/solverdefinition.h"
#include "../../solverdef/solverdefinitiontranslator.h"
#include "../projectcgnsfile.h"
#include "cgnsfileinputconditioncontainerset.h"
#include "cgnsfileinputconditiondialog.h"
#include "cgnsfileinputconditionwidgetset.h"
#include "cgnsfileinputconditionwidgetset.h"

#include <misc/filesystemfunction.h>
#include <misc/stringtool.h>
#include <misc/xmlsupport.h>

#include <QDomDocument>
#include <QDomNode>
#include <QMessageBox>
#include <QPushButton>

#include <cgnslib.h>
#include <iriclib.h>

CgnsFileInputConditionDialog::CgnsFileInputConditionDialog(SolverDefinition* solverDef, const QLocale& locale, QWidget* parent) :
	QDialog(parent),
	ui(new Ui::CgnsFileInputConditionDialog)
{
	m_modified = false;
	m_readonly = false;
	m_solverDefinition = solverDef;

	ui->setupUi(this);
	m_containerSet = new CgnsFileInputConditionContainerSet(parent);
	connect(m_containerSet, SIGNAL(modified()), this, SLOT(setModified()));
	m_widgetSet = new CgnsFileInputConditionWidgetSet();
	// create connections.
	connect(ui->m_pageList, SIGNAL(selectChanged(QString)),
					ui->m_pageContainer, SLOT(pageSelected(QString)));
	connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)),
					this, SLOT(handleButtonClick(QAbstractButton*)));

	setup(*solverDef, locale);

	ui->buttonBox->button(QDialogButtonBox::Save)->setText(tr("&Save and Close"));
}

CgnsFileInputConditionDialog::~CgnsFileInputConditionDialog()
{
	delete ui;
	m_containerSet->clear();
	delete m_containerSet;
	m_widgetSet->clear();
	delete m_widgetSet;
}

void CgnsFileInputConditionDialog::changeEvent(QEvent* e)
{
	QDialog::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
void CgnsFileInputConditionDialog::setup(const SolverDefinition& def, const QLocale& locale)
{
	// open solve definition file
	SolverDefinitionTranslator t(def.folder().absolutePath(), locale);
	QDomNode condNode = iRIC::getChildNode(def.document().documentElement(), "CalculationCondition");
	// setup ContainerSet first.
	m_containerSet->setup(condNode);
	// setup WidgetSet.
	m_widgetSet->setup(condNode, *m_containerSet, t);
	// setup PageList.
	ui->m_pageList->setup(condNode.toElement(), t);
	// setup PageContainer.
	ui->m_pageContainer->setup(condNode.toElement(), m_widgetSet, t);
	// select the first page.
	ui->m_pageList->selectFirstItem();
}

void CgnsFileInputConditionDialog::load(const int fn)
{
	cg_iRIC_GotoCC(fn);
	m_containerSet->load();

	// select the first page.
	ui->m_pageList->selectFirstItem();
	m_modified = false;
}

void CgnsFileInputConditionDialog::save(const int fn)
{
	/*
		if (! m_modified){
			// not modified. do nothing.
			return;
		}
	 */
	cg_iRIC_GotoCC(fn);
	m_containerSet->save();
	m_modified = false;
}

bool CgnsFileInputConditionDialog::import(const QString& filename)
{
	// load from the specified file.
	int fn, ret;
	QString tmpname = iRIC::getTempFileName(m_workFolder);
	// Copy to a temporary file.
	bool bret = QFile::copy(filename, tmpname);
	if (! bret) {return false;}

	// Check the compatibility.
	QString solverName;
	VersionNumber versionNumber;
	bret = ProjectCgnsFile::readSolverInfo(tmpname, solverName, versionNumber);

	if (bret == true) {
		if (m_solverDefinition->name() != solverName || (! m_solverDefinition->version().compatibleWith(versionNumber))) {
			QMessageBox::critical(parentWidget(), tr("Error"),
														tr("This CGNS file is created for %1 version %2. It is not compatible with the current solver.").arg(solverName).arg(versionNumber.toString()));
			return false;
		}
	} else {
		// error occured reading solver information.
		int ret = QMessageBox::warning(parentWidget(), tr("Warning"),
																	 tr("This CGNS file does not have solver information. "
																			"We can not check whether this CGNS file is compatible with the solver. If it is not compatible, maybe only some part of the conditions will be imported.\nDo you really want to import this file?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
		if (ret == QMessageBox::No) {return false;}
	}

	// open cgns file
	ret = cg_open(iRIC::toStr(tmpname).c_str(), CG_MODE_READ, &fn);
	if (ret != 0) {return false;}

	ret = cg_iRIC_GotoCC(fn);
	if (ret != 0) {goto ERROR_BEFORE_CLOSE;}
	// check the number of user defined data items under the CalculationConditions node.
	int nuser_data;
	ret = cg_nuser_data(&nuser_data);
	if (ret != 0) {goto ERROR_BEFORE_CLOSE;}
	if (nuser_data == 0) {
		// there is no calculation data in this CGNS file.
		QMessageBox::critical(parentWidget(), tr("Error"),
													tr("This CGNS file does not contain calculation condition data."));
		goto ERROR_BEFORE_CLOSE;
	}
	ret = m_containerSet->load();
	if (ret != 0) {goto ERROR_BEFORE_CLOSE;}

	ret = cg_close(fn);
	if (ret != 0) {return false;}

	// now save the loaded data to the current CGNS file.
	ret = cg_open(iRIC::toStr(m_fileName).c_str(), CG_MODE_MODIFY, &fn);
	if (ret != 0) {return false;}
	ret = cg_iRIC_GotoCC(fn);
	if (ret != 0) {goto ERROR_BEFORE_CLOSE;}
	ret = m_containerSet->save();
	if (ret != 0) {goto ERROR_BEFORE_CLOSE;}
	ret = cg_close(fn);
	if (ret != 0) {return false;}

	m_modified = false;
	// Delete the temporary file.
	bret = QFile::remove(tmpname);
	if (! bret) {return false;}

	return true;

ERROR_BEFORE_CLOSE:
	cg_close(fn);
	return false;
}

bool CgnsFileInputConditionDialog::doExport(const QString& filename)
{
	// Create an empty CGNS file first. Use temporary name,
	// because cg_open() does not supports file names with Non-ASCII characters.
	QString tmpname = iRIC::getTempFileName(m_workFolder);

	bool bret = ProjectCgnsFile::createNewFile(tmpname, 2, 2);
	if (! bret) {return false;}
	bret = ProjectCgnsFile::writeSolverInfo(tmpname, &(m_solverDefinition->abstract()));
	if (! bret) {return false;}
	// Save into the specified file.
	int fn, ret;
	// Open cgns file
	ret = cg_open(iRIC::toStr(tmpname).c_str(), CG_MODE_MODIFY, &fn);
	if (ret != 0) {return false;}
	ret = cg_iRIC_GotoCC(fn);
	if (ret != 0) {return false;}
	// Save calculation condition.
	m_containerSet->save();
	ret = cg_close(fn);
	if (ret != 0) {return false;}

	// Saved into temporary file.
	// Copy into the specified file.
	if (QFile::exists(filename)) {
		// this file already exists. remove it first.
		bret = QFile::remove(filename);
		if (! bret) {return false;}
	}
	bret = QFile::copy(tmpname, filename);
	if (! bret) {return false;}
	// Delete the temporary file.
	bret = QFile::remove(tmpname);
	if (! bret) {return false;}
	return true;
}

void CgnsFileInputConditionDialog::handleButtonClick(QAbstractButton* button)
{
	if (ui->buttonBox->buttonRole(button) == QDialogButtonBox::ResetRole) {
		reset();
	}
}

void CgnsFileInputConditionDialog::reset()
{
	int ret = QMessageBox::warning(this, tr("Warning"), tr("Are you sure you want to reset all calculation conditions to default values?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (ret == QMessageBox::No) {return;}
	m_containerSet->reset();
}

void CgnsFileInputConditionDialog::accept()
{
	if (m_readonly) {
		QMessageBox::critical(parentWidget(), tr("Error"), tr("The solver is running currently, so you can not save calculation condition. Please press Cancel button."));
		return;
	}

	int fn, ier;
	ier = cg_open(iRIC::toStr(m_fileName).c_str(), CG_MODE_MODIFY, &fn);
	if (ier != 0) {
		QMessageBox::critical(parentWidget(), tr("Error"), tr("Error occured while saving."));
		return;
	}
	save(fn);
	cg_close(fn);
	QDialog::accept();
}

void CgnsFileInputConditionDialog::reject()
{
	if (m_modified && (QMessageBox::Cancel == QMessageBox::warning(this, tr("Warning"), tr("Modifications you made will be discarded."), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel))) {
		return;
	}
	// reload.
	int fn;
	cg_open(iRIC::toStr(m_fileName).c_str(), CG_MODE_READ, &fn);
	load(fn);
	cg_close(fn);
	m_modified = false;
	QDialog::reject();
}

void CgnsFileInputConditionDialog::setModified()
{
	m_modified = true;
}

void CgnsFileInputConditionDialog::setReadOnly(bool readonly)
{
	m_readonly = readonly;
	if (readonly) {
		m_widgetSet->disableWidgets();
		ui->buttonBox->button(QDialogButtonBox::Save)->setDisabled(true);
		ui->buttonBox->button(QDialogButtonBox::Reset)->setDisabled(true);
	} else {
		m_widgetSet->enableWidgets();
		ui->buttonBox->button(QDialogButtonBox::Save)->setEnabled(true);
		ui->buttonBox->button(QDialogButtonBox::Reset)->setEnabled(true);
	}
}
