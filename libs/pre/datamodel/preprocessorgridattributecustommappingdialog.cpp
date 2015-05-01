#include "preprocessorgridattributecustommappingdialog.h"
#include "ui_preprocessorgridattributecustommappingdialog.h"
#include "preprocessorgridattributemappingsettingdataitem.h"
#include "preprocessorbcsettingdataitem.h"
#include "preprocessorbcdataitem.h"
#include <guicore/solverdef/solverdefinitiongridrelatedcondition.h>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QGroupBox>

PreProcessorGridAttributeCustomMappingDialog::PreProcessorGridAttributeCustomMappingDialog(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::PreProcessorGridAttributeCustomMappingDialog)
{
	ui->setupUi(this);
	connect(ui->selectAllButton, SIGNAL(clicked()), this, SLOT(checkAll()));
}

PreProcessorGridAttributeCustomMappingDialog::~PreProcessorGridAttributeCustomMappingDialog()
{
	delete ui;
}

void PreProcessorGridAttributeCustomMappingDialog::setSettings(const QList<PreProcessorGridAttributeMappingSettingDataItem*>& atts, const QList<PreProcessorBCSettingDataItem*>& bcs, const PreProcessorCustomMappingSetting& setting)
{
	if (atts.size() != 0) {
		QGroupBox* gbox = new QGroupBox(tr("Geographic Data"), this);
		QVBoxLayout* glayout = new QVBoxLayout(gbox);
		for (int i = 0; i < atts.size(); ++i) {
			PreProcessorGridAttributeMappingSettingDataItem* item = atts.at(i);
			QCheckBox* checkBox = new QCheckBox(item->condition()->caption(), gbox);
			if (setting.attSettings.contains(item->condition()->name())) {
				checkBox->setChecked(setting.attSettings.value(item->condition()->name()));
			} else {
				checkBox->setChecked(true);
			}
			m_attMap.insert(item, checkBox);
			glayout->addWidget(checkBox);
		}
		glayout->addStretch(1);
		gbox->setLayout(glayout);
		ui->layout->addWidget(gbox);
	}

	if (bcs.size() != 0) {
		QGroupBox* bbox = new QGroupBox(tr("Boundary Condition Setting"), this);
		QVBoxLayout* blayout = new QVBoxLayout(bbox);
		for (int i = 0; i < bcs.size(); ++i) {
			PreProcessorBCSettingDataItem* item = bcs.at(i);
			QCheckBox* checkBox = new QCheckBox(item->bcDataItem()->caption(), bbox);
			if (setting.bcSettings.contains(item->bcDataItem()->uniqueName())) {
				checkBox->setChecked(setting.bcSettings.value(item->bcDataItem()->uniqueName()));
			} else {
				checkBox->setChecked(true);
			}
			m_bcMap.insert(item, checkBox);
			blayout->addWidget(checkBox);
		}
		blayout->addStretch(1);
		bbox->setLayout(blayout);
		ui->layout->addWidget(bbox);
	}
	ui->layout->addStretch(1);
	adjustSize();
}

PreProcessorCustomMappingSetting PreProcessorGridAttributeCustomMappingDialog::setting() const
{
	PreProcessorCustomMappingSetting ret;
	for (auto it = m_attMap.begin(); it != m_attMap.end(); ++it) {
		PreProcessorGridAttributeMappingSettingDataItem* item = it.key();
		QCheckBox* checkBox = it.value();
		ret.attSettings.insert(item->condition()->name(), checkBox->isChecked());
	}
	for (auto it = m_bcMap.begin(); it != m_bcMap.end(); ++it) {
		PreProcessorBCSettingDataItem* item = it.key();
		QCheckBox* checkBox = it.value();
		ret.bcSettings.insert(item->bcDataItem()->uniqueName(), checkBox->isChecked());
	}
	return ret;
}

void PreProcessorGridAttributeCustomMappingDialog::checkAll()
{
	for (auto it = m_attMap.begin(); it != m_attMap.end(); ++it) {
		QCheckBox* checkBox = it.value();
		checkBox->setChecked(true);
	}
	for (auto it = m_bcMap.begin(); it != m_bcMap.end(); ++it) {
		QCheckBox* checkBox = it.value();
		checkBox->setChecked(true);
	}
}
