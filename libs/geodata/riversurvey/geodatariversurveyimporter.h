#ifndef GEODATARIVERSURVEYIMPORTER_H
#define GEODATARIVERSURVEYIMPORTER_H

#include "geodatariversurveyimportersettingdialog.h"

#include <guicore/pre/geodata/geodataimporter.h>

#include <vector>

class GeoDataRiverSurvey;

class GeoDataRiverSurveyImporter : public GeoDataImporter
{
	Q_OBJECT

public:
	class Alt {
	public:
		Alt();
		Alt(int originalOrder, double dis, double e);

		bool operator==(const Alt& other) const;

		int originalOrder;
		double distance;
		double elevation;
	};

	class RivPathPoint {
	public:
		QPointF banksCenter() const;
		double banksDistance() const;
		QPointF leftToRight() const;

		std::string strKP; // name in string
		double realKP;     // name in real

		bool banksIsSet;
		QPointF leftBank;
		QPointF rightBank;

		QString crossSectionFileName;
		std::vector<Alt> altitudes;
		std::vector<double> uniquedDistances;
		bool shifted;
		bool sorted;
		int divIndices[4];
	};

	GeoDataRiverSurveyImporter(GeoDataCreator* creator);

	bool importData(GeoData* data, int index, QWidget* w) override;
	const QStringList fileDialogFilters() override;
	const QStringList acceptableExtensions() override;

	static bool importData(GeoDataRiverSurvey* data, std::vector<RivPathPoint*>* inputData, GeoDataRiverSurveyImporterSettingDialog::CenterPointSetting cpSetting, bool with4Points, const QString& csvFileName, QWidget* w);
	static void removePointsWithoutBanks(std::vector<RivPathPoint*>* points);
	static void removePointsWithoutAltitudes(std::vector<RivPathPoint*>* points);
	static void clearPoints(std::vector<RivPathPoint*>* points);

	static void sortReverse(std::vector<GeoDataRiverSurveyImporter::RivPathPoint*>* points);
	static void sortByKP(std::vector<GeoDataRiverSurveyImporter::RivPathPoint*>* points);

	static void shiftUniqueAlts(std::vector<Alt>* altitudes, bool* shifted);
	static void sortAlts(std::vector<Alt>* altitudes, bool* sorted);
	static QString distListString(const std::vector<double>& distlist);

private:
	bool doInit(const QString& filename, const QString& selectedFilter, int* count, SolverDefinitionGridAttribute* condition, PreProcessorGeoDataGroupDataItemInterface* item, QWidget* w) override;

	std::vector<RivPathPoint*> m_points;
	bool m_with4Points;
	bool m_allNamesAreNumber;
	bool m_reverseOrder;
	GeoDataRiverSurveyImporterSettingDialog::CenterPointSetting m_cpSetting;
	QString m_csvFilename;

public:
	class ProblemsDialog;
};

#endif // GEODATARIVERSURVEYIMPORTER_H
