TARGET = iricGdPolygonGroup
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GD_POLYGONGROUP_LIBRARY

DEFINES += ANSI_DECLARATORS

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

# iricGdPolydata

win32 {
        CONFIG(debug, debug|release) {
                LIBS += -L"../polydata/debug"
        } else {
                LIBS += -L"../polydata/release"
        }
}
unix {
        LIBS += -L"../polydata"
}
LIBS += -liricGdPolydata

# iricGdPolygon

win32 {
        CONFIG(debug, debug|release) {
                LIBS += -L"../polygon/debug"
        } else {
                LIBS += -L"../polygon/release"
        }
}
unix {
        LIBS += -L"../polygon"
}
LIBS += -liricGdPolygon

# iricGeoio

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../geoio/debug"
	} else {
		LIBS += -L"../../geoio/release"
	}
}
unix {
	LIBS += -L"../../geoio"
}
LIBS += -liricGeoio

# iricMisc

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../misc/debug"
	} else {
		LIBS += -L"../../misc/release"
	}
}
unix {
	LIBS += -L"../../misc"
}
LIBS += -liricMisc

# iricTriangle

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../triangle/debug"
	} else {
		LIBS += -L"../../triangle/release"
	}
}
unix {
	LIBS += -L"../../triangle"
}
LIBS += -liricTriangle

# iricGuibase

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../guibase/debug"
	} else {
		LIBS += -L"../../guibase/release"
	}
}
unix {
	LIBS += -L"../../guibase"
}
LIBS += -liricGuibase

# iricGuicore

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../guicore/debug"
	} else {
		LIBS += -L"../../guicore/release"
	}
}
unix {
	LIBS += -L"../../guicore"
}
LIBS += -liricGuicore

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1

# shapelib

win32{
LIBS += -lshapelib_i
}

# geos

LIBS += -lgeos

# Post-Build Event
win32 {
	QMAKE_POST_LINK += copy $(TargetPath) $(SolutionDir)\\libdlls\\$(Configuration)
}

# Input
HEADERS += gd_polygongroup_global.h \
           geodatapolygongroup.h \
           geodatapolygongroupattributebrowser.h \
           geodatapolygongroupcellmappert.h \
           geodatapolygongroupcolorsettingdialog.h \
           geodatapolygongroupcreator.h \
           geodatapolygongroupcreatort.h \
           geodatapolygongroupintegercreator.h \
           geodatapolygongroupmergesettingdialog.h \
           geodatapolygongroupnodemappert.h \
           geodatapolygongrouppolygon.h \
           geodatapolygongrouprangecontainer.h \
           geodatapolygongrouprealcreator.h \
           geodatapolygongroupshpexporter.h \
           geodatapolygongroupshpimporter.h \
           geodatapolygongroupshpimportersettingdialog.h \
           private/geodatapolygongroup_editnameandvaluecommand.h \
           private/geodatapolygongroup_editpropertycommand.h \
           private/geodatapolygongroup_impl.h \
           private/geodatapolygongroup_sortcommand.h \
           private/geodatapolygongroup_sortedittargetpolygoncommand.h \
           private/geodatapolygongroupattributebrowser_tableitemdelegate.h \
           private/geodatapolygongroupcellmappert_detail.h \
           private/geodatapolygongroupcreatort_detail.h \
           private/geodatapolygongroupnodemappert_detail.h \
           private/geodatapolygongrouppolygon_impl.h \
           private/geodatapolygongrouppolygon_triangulatori.h \
           private/geodatapolygongrouppolygon_triangulatortriangle.h \
           private/geodatapolygongrouppolygon_triangulatorvtk.h
FORMS += geodatapolygongroupcolorsettingdialog.ui \
         geodatapolygongroupmergesettingdialog.ui \
         geodatapolygongroupshpimportersettingdialog.ui
SOURCES += geodatapolygongroup.cpp \
           geodatapolygongroupattributebrowser.cpp \
           geodatapolygongroupcolorsettingdialog.cpp \
           geodatapolygongroupcreator.cpp \
           geodatapolygongroupintegercreator.cpp \
           geodatapolygongroupmergesettingdialog.cpp \
           geodatapolygongrouppolygon.cpp \
           geodatapolygongrouprangecontainer.cpp \
           geodatapolygongrouprealcreator.cpp \
           geodatapolygongroupshpexporter.cpp \
           geodatapolygongroupshpimporter.cpp \
           geodatapolygongroupshpimportersettingdialog.cpp \
           private/geodatapolygongroup_editnameandvaluecommand.cpp \
           private/geodatapolygongroup_editpropertycommand.cpp \
           private/geodatapolygongroup_impl.cpp \
           private/geodatapolygongroup_sortcommand.cpp \
           private/geodatapolygongroup_sortedittargetpolygoncommand.cpp \
           private/geodatapolygongroupattributebrowser_tableitemdelegate.cpp \
           private/geodatapolygongrouppolygon_triangulatortriangle.cpp \
           private/geodatapolygongrouppolygon_triangulatorvtk.cpp
TRANSLATIONS += languages/iricGdPolygonGroup_ar_EG.ts \
                languages/iricGdPolygonGroup_bg_BG.ts \
                languages/iricGdPolygonGroup_bs_BA.ts \
                languages/iricGdPolygonGroup_ca_ES.ts \
                languages/iricGdPolygonGroup_cs_CZ.ts \
                languages/iricGdPolygonGroup_da_DK.ts \
                languages/iricGdPolygonGroup_de_DE.ts \
                languages/iricGdPolygonGroup_el_GR.ts \
                languages/iricGdPolygonGroup_es_ES.ts \
                languages/iricGdPolygonGroup_et_EE.ts \
                languages/iricGdPolygonGroup_eu_ES.ts \
                languages/iricGdPolygonGroup_fi_FI.ts \
                languages/iricGdPolygonGroup_fr_FR.ts \
                languages/iricGdPolygonGroup_gl_ES.ts \
                languages/iricGdPolygonGroup_hi_IN.ts \
                languages/iricGdPolygonGroup_hu_HU.ts \
                languages/iricGdPolygonGroup_id_ID.ts \
                languages/iricGdPolygonGroup_is_IS.ts \
                languages/iricGdPolygonGroup_it_IT.ts \
                languages/iricGdPolygonGroup_ja_JP.ts \
                languages/iricGdPolygonGroup_ko_KR.ts \
                languages/iricGdPolygonGroup_ky_KG.ts \
                languages/iricGdPolygonGroup_lt_LT.ts \
                languages/iricGdPolygonGroup_lv_LV.ts \
                languages/iricGdPolygonGroup_nb_NO.ts \
                languages/iricGdPolygonGroup_nl_NL.ts \
                languages/iricGdPolygonGroup_pl_PL.ts \
                languages/iricGdPolygonGroup_pt_BR.ts \
                languages/iricGdPolygonGroup_pt_PT.ts \
                languages/iricGdPolygonGroup_ro_RO.ts \
                languages/iricGdPolygonGroup_ru_RU.ts \
                languages/iricGdPolygonGroup_sl_SI.ts \
                languages/iricGdPolygonGroup_sv_SE.ts \
                languages/iricGdPolygonGroup_th_TH.ts \
                languages/iricGdPolygonGroup_tr_TR.ts \
                languages/iricGdPolygonGroup_uk_UA.ts \
                languages/iricGdPolygonGroup_vi_VN.ts \
                languages/iricGdPolygonGroup_zh_CN.ts \
                languages/iricGdPolygonGroup_zh_TW.ts
