#ifndef GEODATAPOLYGONGROUPNODEMAPPERT_DETAIL_H
#define GEODATAPOLYGONGROUPNODEMAPPERT_DETAIL_H

#include "../geodatapolygongroupnodemappert.h"
#include "../geodatapolygongrouppolygon.h"

namespace {

const double TINY_DOUBLE = 1.0E-8;

} // namespace

template <class V, class DA>
GeoDataPolygonGroupNodeMapperT<V, DA>::GeoDataPolygonGroupNodeMapperT(GeoDataCreator* parent) :
	GeoDataNodeMapperT<V, DA> ("PolygonGroup node mapper", parent)
{}

template <class V, class DA>
GeoDataMapperSettingI* GeoDataPolygonGroupNodeMapperT<V, DA>::initialize(bool* boolMap)
{
	auto s = new GeoDataPolygonGroupNodeMapperSetting();
	unsigned int count = GeoDataMapperT<V>::container()->dataCount();
	auto polygonGroup = dynamic_cast<GeoDataPolygonGroup*> (GeoDataMapper::geoData());
	polygonGroup->mergeEditTargetData();
	polygonGroup->updateOrder();

	for (unsigned int i = 0; i < count; ++i) {
		if (*(boolMap + i)) {
			s->ranges.add(nullptr);
			continue;
		}
		// not mapped yet.
		double point[3];
		GeoDataMapper::grid()->vtkGrid()->GetPoint(i, point);
		auto pols = polygonGroup->polygonsInBoundingBox(point[0] - TINY_DOUBLE, point[0] + TINY_DOUBLE, point[1] - TINY_DOUBLE, point[1] + TINY_DOUBLE);

		std::map<unsigned int, GeoDataPolygonGroupPolygon*> polsMap;
		for (GeoDataPolygonGroupPolygon* p : pols) {
			if (p->isInside(QPointF(point[0], point[1]))) {
				polsMap.insert({p->order(), p});
			}
		}
		if (polsMap.size() > 0) {
			s->ranges.add(polsMap.begin()->second);
			*(boolMap + i) = true;
		} else {
			s->ranges.add(nullptr);
		}
	}
	return s;
}

template <class V, class DA>
void GeoDataPolygonGroupNodeMapperT<V, DA>::map(bool* boolMap, GeoDataMapperSettingI* s)
{
	auto setting = dynamic_cast<GeoDataPolygonGroupNodeMapperSetting*> (s);
	DA* da = dynamic_cast<DA*> (GeoDataMapperT<V>::container()->dataArray());
	const auto& polys = setting->ranges.data();
	const auto& maxIndices = setting->ranges.maxIndices();
	int rangeId = 0;
	vtkIdType idx = 0;
	while (rangeId < maxIndices.size()) {
		GeoDataPolygonGroupPolygon* pol = polys.at(rangeId);
		vtkIdType maxIdx = maxIndices.at(rangeId);
		if (pol == nullptr) {
			idx = maxIdx + 1;
		} else {
			V value = GeoDataMapperT<V>::fromVariant(pol->value());
			while (idx <= maxIdx) {
				da->SetValue(idx, value);
				*(boolMap + idx) = true;
				++ idx;
			}
		}
		++ rangeId;
	}
}

template <class V, class DA>

void GeoDataPolygonGroupNodeMapperT<V, DA>::terminate(GeoDataMapperSettingI* setting)
{
	delete setting;
}

#endif // GEODATAPOLYGONGROUPNODEMAPPERT_DETAIL_H
