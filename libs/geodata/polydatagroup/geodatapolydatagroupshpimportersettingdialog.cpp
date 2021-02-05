#include "ui_geodatapolydatagroupshpimportersettingdialog.h"

#include "geodatapolydatagroupshpimportersettingdialog.h"

#include <misc/stringtool.h>

#include <QMessageBox>
#include <QTextCodec>

#include <shapefil.h>

GeoDataPolyDataGroupShpImporterSettingDialog::GeoDataPolyDataGroupShpImporterSettingDialog(const QString& filename, GridAttributeEditWidget* widget, QWidget* parent) :
	QDialog {parent},
	ui {new Ui::GeoDataPolyDataGroupShpImporterSettingDialog}
{
	ui->setupUi(this);
	m_filename = filename;

	QList<QByteArray> codecs = QTextCodec::availableCodecs();
	qSort(codecs);
	for (const QByteArray& name : codecs) {
		ui->encodingComboBox->addItem(QString(name));
	}
	QTextCodec* defaultCodec = QTextCodec::codecForLocale();
	int index = codecs.indexOf(defaultCodec->name());
	ui->encodingComboBox->setCurrentIndex(index);
	ui->valueWidget->setWidget(widget);

	connect(ui->encodingComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateTable()));

	updateTable();
}

GeoDataPolyDataGroupShpImporterSettingDialog::~GeoDataPolyDataGroupShpImporterSettingDialog()
{
	delete ui;
}

void GeoDataPolyDataGroupShpImporterSettingDialog::setLabels(const QStringList& labels)
{
	ui->nameComboBox->clear();
	ui->valueComboBox->clear();
	for (int i = 0; i < labels.count(); ++i) {
		QString label = labels.at(i);
		ui->nameComboBox->addItem(label);
		ui->valueComboBox->addItem(label);
	}

	ui->tableWidget->clear();
	ui->tableWidget->setColumnCount(labels.count());
	ui->tableWidget->setHorizontalHeaderLabels(labels);
}

void GeoDataPolyDataGroupShpImporterSettingDialog::setData(const std::vector<std::vector<QVariant> >& data)
{
	ui->tableWidget->setRowCount(data.size());
	for (int i = 0; i < data.size(); ++i) {
		const auto& d2 = data.at(i);
		for (int j = 0; j < d2.size(); ++j) {
			QVariant v = d2.at(j);
			QTableWidgetItem* item = new QTableWidgetItem(v.toString());
			ui->tableWidget->setItem(i, j, item);
		}
	}
}

int GeoDataPolyDataGroupShpImporterSettingDialog::nameIndex() const
{
	return ui->nameComboBox->currentIndex();
}

int GeoDataPolyDataGroupShpImporterSettingDialog::valueIndex() const
{
	return ui->valueComboBox->currentIndex();
}

void GeoDataPolyDataGroupShpImporterSettingDialog::accept()
{
	if (nameSetting() == nsLoadFromDBF && valueSetting() == vsLoadFromDBF && nameIndex() == valueIndex()) {
		QMessageBox::warning(this, tr("Warning"), tr("You cannot specify the same column for both Name and Value."));
		return;
	}
	QDialog::accept();
}

void GeoDataPolyDataGroupShpImporterSettingDialog::updateTable()
{
	std::string fname = iRIC::toStr(m_filename);
	SHPHandle shph = SHPOpen(fname.c_str(), "rb");

	int numEntities;
	int shapeType;
	double minBound[4];
	double maxBound[4];

	QByteArray codecName = ui->encodingComboBox->currentText().toLatin1();
	QTextCodec* codec = QTextCodec::codecForName(codecName);

	SHPGetInfo(shph, &numEntities, &shapeType, minBound, maxBound);

	QString dbfFilename = m_filename;
	dbfFilename.replace(QRegExp(".shp$"), ".dbf");
	std::string dbfname = iRIC::toStr(dbfFilename);
	DBFHandle dbfh = DBFOpen(dbfname.c_str(), "rb");

	int fieldCount = DBFGetFieldCount(dbfh);
	int recordCount = DBFGetRecordCount(dbfh);

	QStringList labels;
	QList<DBFFieldType> types;
	for (int i = 0; i < fieldCount; ++i) {
		DBFFieldType type;
		char fieldName[12];
		type = DBFGetFieldInfo(dbfh, i, fieldName, NULL, NULL);
		labels.append(codec->toUnicode(fieldName));
		types.append(type);
	}
	std::vector<std::vector<QVariant> > valArr;
	for (int i = 0; i < recordCount; ++i) {
		std::vector<QVariant> vals;
		for (int j = 0; j < fieldCount; ++j) {
			DBFFieldType type = types.at(j);
			QVariant val;
			if (type == FTString) {
				QString strval = codec->toUnicode(DBFReadStringAttribute(dbfh, i, j));
				val = strval;
			} else if (type == FTInteger) {
				int intval = DBFReadIntegerAttribute(dbfh, i, j);
				val = intval;
			} else if (type == FTDouble) {
				double doubleval = DBFReadDoubleAttribute(dbfh, i, j);
				val = doubleval;
			} else if (type == FTLogical) {
				QString logval = DBFReadLogicalAttribute(dbfh, i, j);
				val = logval;
			}
			vals.push_back(val);
		}
		valArr.push_back(vals);
	}
	DBFClose(dbfh);
	setLabels(labels);
	setData(valArr);
}

void GeoDataPolyDataGroupShpImporterSettingDialog::hideValueWidgets()
{
	ui->valueGroupBox->hide();
	ui->valueCustomRadioButton->setChecked(true);
}

GeoDataPolyDataGroupShpImporterSettingDialog::NameSetting GeoDataPolyDataGroupShpImporterSettingDialog::nameSetting() const
{
	if (ui->nameAttributeRadioButton->isChecked()) {
		return nsLoadFromDBF;
	} else {
		return nsAuto;
	}
}

GeoDataPolyDataGroupShpImporterSettingDialog::ValueSetting GeoDataPolyDataGroupShpImporterSettingDialog::valueSetting() const
{
	if (ui->valueAttributeRadioButton->isChecked()) {
		return vsLoadFromDBF;
	} else {
		return vsSpecify;
	}
}

QVariant GeoDataPolyDataGroupShpImporterSettingDialog::specifiedValue() const
{
	return ui->valueWidget->widget()->variantValue();
}

QString GeoDataPolyDataGroupShpImporterSettingDialog::codecName() const
{
	return ui->encodingComboBox->currentText();
}