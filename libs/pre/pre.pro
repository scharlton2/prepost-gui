######################################################################
# Automatically generated by qmake (2.01a) ? 10 24 00:36:17 2014
######################################################################

TARGET = iricPre
TEMPLATE = lib


DEFINES += PRE_LIBRARY

include( ../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

# iricAxis2d

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../dataitem/axis2d/debug"
	} else {
		LIBS += -L"../dataitem/axis2d/release"
	}
}
unix {
	LIBS += -L"../../dataitem/axis2d"
}
LIBS += -liricAxis2d

# iricMisc

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../misc/debug"
	} else {
		LIBS += -L"../misc/release"
	}
}
unix {
	LIBS += -L"../misc"
}
LIBS += -liricMisc

# iricGuibase

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../guibase/debug"
	} else {
		LIBS += -L"../guibase/release"
	}
}
unix {
	LIBS += -L"../guibase"
}
LIBS += -liricGuibase

# iricGuicore

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../guicore/debug"
	} else {
		LIBS += -L"../guicore/release"
	}
}
unix {
	LIBS += -L"../guicore"
}

LIBS += -liricGuicore

# iricGdRiversurvey

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../geodata/riversurvey/debug"
	} else {
		LIBS += -L"../geodata/riversurvey/release"
	}
}
unix {
	LIBS += -L"../geodata/riversurvey"
}
LIBS += -liricGdRiversurvey

# iricGdPointmap

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../geodata/pointmap/debug"
	} else {
		LIBS += -L"../geodata/pointmap/release"
	}
}
unix {
	LIBS += -L"../geodata/pointmap"
}
LIBS += -liricGdPointmap

# iricGdPolygon

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../geodata/polygon/debug"
	} else {
		LIBS += -L"../geodata/polygon/release"
	}
}
unix {
	LIBS += -L"../geodata/polygon"
}
LIBS += -liricGdPolygon

# iricGdNetcdf
win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../geodata/netcdf/debug"
	} else {
		LIBS += -L"../geodata/netcdf/release"
	}
}
unix {
	LIBS += -L"../geodata/netcdf"
}
LIBS += -liricGdNetcdf

# iricGccCenterandwidth

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/centerandwidth/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/centerandwidth/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/centerandwidth"
}
LIBS += -liricGccCenterandwidth

# iricGccCompoundchannel

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/compoundchannel/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/compoundchannel/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/compoundchannel"
}
LIBS += -liricGccCompoundchannel

# iricGccExternalprogram

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/externalprogram/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/externalprogram/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/externalprogram"
}
LIBS += -liricGccExternalprogram

# iricGccGridcombine

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/gridcombine/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/gridcombine/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/gridcombine"
}
LIBS += -liricGccGridcombine

# iricGccGridgenerator

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/gridgenerator/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/gridgenerator/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/gridgenerator"
}
LIBS += -liricGccGridgenerator

# iricGccRectangularregion

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/rectangularregion/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/rectangularregion/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/rectangularregion"
}
LIBS += -liricGccRectangularregion

# iricGccRectangularregionlonlat

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/rectangularregionlonlat/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/rectangularregionlonlat/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/rectangularregionlonlat"
}
LIBS += -liricGccRectangularregionlonlat

# iricGccRiversurvey

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/riversurvey/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/riversurvey/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/riversurvey"
}
LIBS += -liricGccRiversurvey

# iricGccRiversurvey15d

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/riversurvey15d/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/riversurvey15d/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/riversurvey15d"
}
LIBS += -liricGccRiversurvey15d

# iricGccTriangle

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../gridcreatingcondition/triangle/debug"
	} else {
		LIBS += -L"../gridcreatingcondition/triangle/release"
	}
}
unix {
	LIBS += -L"../gridcreatingcondition/triangle"
}
LIBS += -liricGccTriangle

# iricHdRiversurveywaterelevation

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../hydraulicdata/riversurveywaterelevation/debug"
	} else {
		LIBS += -L"../hydraulicdata/riversurveywaterelevation/release"
	}
}
unix {
	LIBS += -L"../hydraulicdata/riversurveywaterelevation"
}
LIBS += -liricHdRiversurveywaterelevation

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkCommonExecutionModel-6.1 \
	-lvtkCommonMisc-6.1 \
	-lvtkFiltersCore-6.1 \
	-lvtkFiltersGeometry-6.1 \
	-lvtkFiltersGeneral-6.1 \
	-lvtkFiltersExtraction-6.1 \
	-lvtkFiltersSources-6.1 \
	-lvtkFiltersTexture-6.1 \
	-lvtkGUISupportQt-6.1 \
	-lvtkInteractionWidgets-6.1 \
	-lvtkIOImage-6.1 \
	-lvtkIOCore-6.1 \
	-lvtkIOLegacy-6.1 \
	-lvtkRenderingAnnotation-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingFreeType-6.1 \
	-lvtkRenderingLabel-6.1 \
	-lvtkRenderingLOD-6.1

# cgnslib
win32 {
	LIBS += -lcgnsdll
}
unix {
	LIBS += -lcgns
}

# iriclib

LIBS += -liriclib

# shapelib

win32 {
	LIBS += -lshapelib_i
}

# Input
HEADERS += pre_global.h \
           preobjectbrowser.h \
           preobjectbrowserview.h \
           preprocessordatamodel.h \
           preprocessorgraphicsview.h \
           preprocessorwindow.h \
           preprocessorwindowactionmanager.h \
           preprocessorwindowprojectdataitem.h \
           prepropertybrowser.h \
           bc/boundaryconditiondialog.h \
           datamodel/graphicssupport.h \
           datamodel/preprocessorbackgroundimagedataitem.h \
           datamodel/preprocessorbackgroundimagesdataitem.h \
           datamodel/preprocessorbcdataitem.h \
           datamodel/preprocessorbcgroupdataitem.h \
           datamodel/preprocessorbcsettingdataitem.h \
           datamodel/preprocessorbcsettinggroupdataitem.h \
           datamodel/preprocessorcustommappingsetting.h \
           datamodel/preprocessorgeodatacomplexgroupdataitem.h \
           datamodel/preprocessorgeodatadataitem.h \
           datamodel/preprocessorgeodatagroupdataitem.h \
           datamodel/preprocessorgeodatatopdataitem.h \
           datamodel/preprocessorgridandgridcreatingconditiondataitem.h \
           datamodel/preprocessorgridattributecelldataitem.h \
           datamodel/preprocessorgridattributecelldisplaysettingdialog.h \
           datamodel/preprocessorgridattributecellgroupdataitem.h \
           datamodel/preprocessorgridattributecustommappingdialog.h \
           datamodel/preprocessorgridattributemappingsettingdataitem.h \
           datamodel/preprocessorgridattributemappingsettingtopdataitem.h \
           datamodel/preprocessorgridattributemappingsettingtopeditdialog.h \
           datamodel/preprocessorgridattributenodedataitem.h \
           datamodel/preprocessorgridattributenodegroupdataitem.h \
           datamodel/preprocessorgridattributetemplatemappingsettingdialog.h \
           datamodel/preprocessorgridcreatingconditionalgorithmselectdialog.h \
           datamodel/preprocessorgridcreatingconditiondataitem.h \
           datamodel/preprocessorgriddataitem.h \
           datamodel/preprocessorgridshapedataitem.h \
           datamodel/preprocessorgridtypedataitem.h \
           datamodel/preprocessorinputconditiondataitem.h \
           datamodel/preprocessormeasureddatatopdataitem.h \
           datamodel/preprocessornormal15dgridwithcrosssectiondataitem.h \
           datamodel/preprocessornormal15dgridwithcrosssectionshapedataitem.h \
           datamodel/preprocessorrootdataitem.h \
           datamodel/preprocessorstructured2dgriddataitem.h \
           datamodel/preprocessorstructured2dgridshapedataitem.h \
           datamodel/preprocessorunstructured2dgriddataitem.h \
           datamodel/preprocessorunstructured2dgridshapedataitem.h \
           factory/geodatafactory.h \
           factory/gridcreatingconditionfactory.h \
           factory/gridexporterfactory.h \
           factory/gridimporterfactory.h \
           factory/hydraulicdataimporterfactory.h \
           factory/preprocessorgriddataitemfactory.h \
           gridexporter/cgnsgridexporter.h \
           gridimporter/cgnsgridimporter.h \
           gridimporter/projectgridimporter.h \
           gridimporter/structured15dgridwithcrosssectioncgnsimporter.h \
           gridimporter/structured15dgridwithcrosssectionprojectimporter.h \
           gridimporter/structured2dgridcgnsimporter.h \
           gridimporter/structured2dgridprojectimporter.h \
           gridimporter/unstructured2dgridcgnsimporter.h \
           gridimporter/unstructured2dgridprojectimporter.h \
           misc/preprocessorgridattributemappingmode.h \
           misc/preprocessorlegendboxeditdialog.h \
           misc/preprocessorscalarbareditdialog.h \
           misc/preprocessorscalarbarlegendboxsettingdialog.h \
           misc/preprocessorwindowscalarbarsettingwidget.h \
           datamodel/gridshape/preprocessorgridshapedeltadialog.h \
           datamodel/gridshape/preprocessorgridshapenewpositiondialog.h \
           subwindow/gridbirdeyewindow/gridbirdeyewindow.h \
           subwindow/gridbirdeyewindow/gridbirdeyewindowactionmanager.h \
           subwindow/gridbirdeyewindow/gridbirdeyewindowaxessettingdialog.h \
           subwindow/gridbirdeyewindow/gridbirdeyewindowcolorsettingdialog.h \
           subwindow/gridbirdeyewindow/gridbirdeyewindowdatamodel.h \
           subwindow/gridbirdeyewindow/gridbirdeyewindowgraphicsview.h \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindow.h \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowdelegate.h \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowgraphicsview.h \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowprojectdataitem.h \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowtableview.h \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionaltitudemovedialog.h \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindow.h \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowdelegate.h \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowgraphicsview.h \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowprojectdataitem.h \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowtableview.h
FORMS += bc/boundaryconditiondialog.ui \
         datamodel/preprocessorgridattributecelldisplaysettingdialog.ui \
         datamodel/preprocessorgridattributecustommappingdialog.ui \
         datamodel/preprocessorgridattributemappingsettingtopeditdialog.ui \
         datamodel/preprocessorgridattributetemplatemappingsettingdialog.ui \
         datamodel/preprocessorgridcreatingconditionalgorithmselectdialog.ui \
         misc/preprocessorlegendboxeditdialog.ui \
         misc/preprocessorscalarbareditdialog.ui \
         misc/preprocessorscalarbarlegendboxsettingdialog.ui \
         misc/preprocessorwindowscalarbarsettingwidget.ui \
         datamodel/gridshape/preprocessorgridshapedeltadialog.ui \
         datamodel/gridshape/preprocessorgridshapenewpositiondialog.ui \
         subwindow/gridbirdeyewindow/gridbirdeyewindowaxessettingdialog.ui \
         subwindow/gridbirdeyewindow/gridbirdeyewindowcolorsettingdialog.ui \
         subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindow.ui \
         subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionaltitudemovedialog.ui \
         subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindow.ui
SOURCES += preobjectbrowser.cpp \
           preobjectbrowserview.cpp \
           preprocessordatamodel.cpp \
           preprocessorgraphicsview.cpp \
           preprocessorwindow.cpp \
           preprocessorwindowactionmanager.cpp \
           preprocessorwindowprojectdataitem.cpp \
           prepropertybrowser.cpp \
           bc/boundaryconditiondialog.cpp \
           datamodel/graphicssupport.cpp \
           datamodel/preprocessorbackgroundimagedataitem.cpp \
           datamodel/preprocessorbackgroundimagesdataitem.cpp \
           datamodel/preprocessorbcdataitem.cpp \
           datamodel/preprocessorbcgroupdataitem.cpp \
           datamodel/preprocessorbcsettingdataitem.cpp \
           datamodel/preprocessorbcsettinggroupdataitem.cpp \
           datamodel/preprocessorcustommappingsetting.cpp \
           datamodel/preprocessorgeodatacomplexgroupdataitem.cpp \
           datamodel/preprocessorgeodatadataitem.cpp \
           datamodel/preprocessorgeodatagroupdataitem.cpp \
           datamodel/preprocessorgeodatatopdataitem.cpp \
           datamodel/preprocessorgridandgridcreatingconditiondataitem.cpp \
           datamodel/preprocessorgridattributecelldataitem.cpp \
           datamodel/preprocessorgridattributecelldisplaysettingdialog.cpp \
           datamodel/preprocessorgridattributecellgroupdataitem.cpp \
           datamodel/preprocessorgridattributecustommappingdialog.cpp \
           datamodel/preprocessorgridattributemappingsettingdataitem.cpp \
           datamodel/preprocessorgridattributemappingsettingtopdataitem.cpp \
           datamodel/preprocessorgridattributemappingsettingtopeditdialog.cpp \
           datamodel/preprocessorgridattributenodedataitem.cpp \
           datamodel/preprocessorgridattributenodegroupdataitem.cpp \
           datamodel/preprocessorgridattributetemplatemappingsettingdialog.cpp \
           datamodel/preprocessorgridcreatingconditionalgorithmselectdialog.cpp \
           datamodel/preprocessorgridcreatingconditiondataitem.cpp \
           datamodel/preprocessorgriddataitem.cpp \
           datamodel/preprocessorgridshapedataitem.cpp \
           datamodel/preprocessorgridtypedataitem.cpp \
           datamodel/preprocessorinputconditiondataitem.cpp \
           datamodel/preprocessormeasureddatatopdataitem.cpp \
           datamodel/preprocessornormal15dgridwithcrosssectiondataitem.cpp \
           datamodel/preprocessornormal15dgridwithcrosssectionshapedataitem.cpp \
           datamodel/preprocessorrootdataitem.cpp \
           datamodel/preprocessorstructured2dgriddataitem.cpp \
           datamodel/preprocessorstructured2dgridshapedataitem.cpp \
           datamodel/preprocessorunstructured2dgriddataitem.cpp \
           datamodel/preprocessorunstructured2dgridshapedataitem.cpp \
           factory/geodatafactory.cpp \
           factory/gridcreatingconditionfactory.cpp \
           factory/gridexporterfactory.cpp \
           factory/gridimporterfactory.cpp \
           factory/hydraulicdataimporterfactory.cpp \
           factory/preprocessorgriddataitemfactory.cpp \
           gridexporter/cgnsgridexporter.cpp \
           gridimporter/cgnsgridimporter.cpp \
           gridimporter/projectgridimporter.cpp \
           gridimporter/structured15dgridwithcrosssectioncgnsimporter.cpp \
           gridimporter/structured15dgridwithcrosssectionprojectimporter.cpp \
           gridimporter/structured2dgridcgnsimporter.cpp \
           gridimporter/structured2dgridprojectimporter.cpp \
           gridimporter/unstructured2dgridcgnsimporter.cpp \
           gridimporter/unstructured2dgridprojectimporter.cpp \
           misc/preprocessorgridattributemappingmode.cpp \
           misc/preprocessorlegendboxeditdialog.cpp \
           misc/preprocessorscalarbareditdialog.cpp \
           misc/preprocessorscalarbarlegendboxsettingdialog.cpp \
           misc/preprocessorwindowscalarbarsettingwidget.cpp \
           datamodel/gridshape/preprocessorgridshapedeltadialog.cpp \
           datamodel/gridshape/preprocessorgridshapenewpositiondialog.cpp \
           subwindow/gridbirdeyewindow/gridbirdeyewindow.cpp \
           subwindow/gridbirdeyewindow/gridbirdeyewindowactionmanager.cpp \
           subwindow/gridbirdeyewindow/gridbirdeyewindowaxessettingdialog.cpp \
           subwindow/gridbirdeyewindow/gridbirdeyewindowcolorsettingdialog.cpp \
           subwindow/gridbirdeyewindow/gridbirdeyewindowdatamodel.cpp \
           subwindow/gridbirdeyewindow/gridbirdeyewindowgraphicsview.cpp \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindow.cpp \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowdelegate.cpp \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowgraphicsview.cpp \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowprojectdataitem.cpp \
           subwindow/gridcrosssectionwindow/preprocessorgridcrosssectionwindowtableview.cpp \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionaltitudemovedialog.cpp \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindow.cpp \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowdelegate.cpp \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowgraphicsview.cpp \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowprojectdataitem.cpp \
           subwindow/structured15dgridwithcrosssectioncrosssectionwindow/structured15dgridwithcrosssectioncrosssectionwindowtableview.cpp
TRANSLATIONS += languages/iricPre_es_ES.ts \
                languages/iricPre_fr_FR.ts \
                languages/iricPre_id_ID.ts \
                languages/iricPre_ja_JP.ts \
                languages/iricPre_ko_KR.ts \
                languages/iricPre_ru_RU.ts \
                languages/iricPre_th_TH.ts \
                languages/iricPre_vi_VN.ts \
                languages/iricPre_zh_CN.ts
