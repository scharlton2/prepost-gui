#include "scalarsettingcontainer.h"

#include <guicore/scalarstocolors/lookuptablecontainer.h>
#include <misc/stringtool.h>

#include <vtkCellData.h>
#include <vtkClipPolyData.h>
#include <vtkExtractCells.h>
#include <vtkIdList.h>
#include <vtkPointData.h>
#include <vtkPointSet.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>

const int ScalarSettingContainer::DEFAULT_NUMOFDIV = 15;

ScalarSettingContainer::ScalarSettingContainer() :
	CompositeContainer({&target, &contour, &numberOfDivisions,
			&fillUpper, &fillLower, &opacity, &scalarBarSetting}),
	target {"solution"},
	contour {"contour", ContourSettingWidget::ColorFringe},
	numberOfDivisions {"numberOfDivisions", DEFAULT_NUMOFDIV},
	fillUpper {"fillUpper", true},
	fillLower {"fillLower", true},
	opacity {},
	scalarBarSetting {}
{
	opacity = 50;
	scalarBarSetting.addPrefix("scalarBar");
}

ScalarSettingContainer::ScalarSettingContainer(const ScalarSettingContainer &c) :
	ScalarSettingContainer()
{
	copyValue(c);
}

ScalarSettingContainer::~ScalarSettingContainer()
{}


ScalarSettingContainer& ScalarSettingContainer::operator=(const ScalarSettingContainer& c)
{
	CompositeContainer::copyValue(c);
	return *this;
}

XmlAttributeContainer& ScalarSettingContainer::operator=(const XmlAttributeContainer& c)
{
	return operator=(dynamic_cast<const ScalarSettingContainer&>(c));
}


vtkPolyData* ScalarSettingContainer::filterPolyDataWithUpperLower(vtkPolyData* pd, const LookupTableContainer& lut) const
{
	if (fillUpper & fillLower) {
		// no filtering.
		pd->Register(nullptr);
		return pd;
	}

	double min, max;
	lut.getValueRange(&min, &max);

	vtkSmartPointer<vtkPolyData> upperClipped;
	vtkSmartPointer<vtkPolyData> lowerClipped;

	if (fillLower) {
		lowerClipped = pd;
	} else {
		auto lowerClipper = vtkSmartPointer<vtkClipPolyData>::New();
		lowerClipper->SetValue(min);
		lowerClipper->SetInputData(pd);
		lowerClipper->InsideOutOff();
		pd->GetPointData()->SetActiveScalars(iRIC::toStr(target).c_str());
		lowerClipper->Update();
		lowerClipped = lowerClipper->GetOutput();
		pd->GetPointData()->SetActiveScalars("");
	}

	if (fillUpper) {
		upperClipped = lowerClipped;
	} else {
		auto upperClipper = vtkSmartPointer<vtkClipPolyData>::New();
		upperClipper->SetValue(max);
		upperClipper->SetInputData(lowerClipped);
		upperClipper->InsideOutOn();
		lowerClipped->GetPointData()->SetActiveScalars(iRIC::toStr(target).c_str());
		upperClipper->Update();
		upperClipped = upperClipper->GetOutput();
		lowerClipped->GetPointData()->SetActiveScalars("");
	}

	upperClipped->Register(nullptr);
	return upperClipped;
}

vtkPointSet* ScalarSettingContainer::filterCellsWithUpperLower(vtkPointSet* ps, const LookupTableContainer& lut) const
{
	if (fillUpper && fillLower) {
		// no filtering.
		ps->Register(nullptr);
		return ps;
	}

	double min, max;
	lut.getValueRange(&min, &max);

	auto idList = vtkSmartPointer<vtkIdList>::New();

	auto vals = ps->GetCellData()->GetArray(iRIC::toStr(target).c_str());
	for (int i = 0; i < ps->GetNumberOfCells(); ++i) {
		double v = *(vals->GetTuple(i));
		if ((! fillUpper) && v > max) {continue;}
		if ((! fillLower) && v < min) {continue;}

		idList->InsertNextId(i);
	}
	auto eCells = vtkSmartPointer<vtkExtractCells>::New();
	eCells->SetCellList(idList);
	eCells->SetInputData(ps);
	eCells->Update();
	vtkPointSet* ret = eCells->GetOutput();
	ret->Register(nullptr);

	return ret;
}
