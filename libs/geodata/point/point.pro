TARGET = iricGdPoint
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GD_POINT_LIBRARY

DEFINES += ANSI_DECLARATORS

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

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

# iriclib

LIBS += -liriclib

# shapelib

win32{
LIBS += -lshapelib_i
}

# geos

LIBS += -lgeos

# Post-Build Event
win32 {
	QMAKE_POST_LINK += IF NOT EXIST $(SolutionDir)\\libdlls\\$(Configuration) mkdir $(SolutionDir)\\libdlls\\$(Configuration) && copy $(TargetPath) $(SolutionDir)\\libdlls\\$(Configuration)
}

# Input
HEADERS += gd_point_global.h \
           geodatapoint.h \
           geodatapointcellmappert.h \
           geodatapointcreator.h \
           geodatapointcreatort.h \
           geodatapointnodemappert.h \
           geodatapointrealcreator.h \
           ui_geodatapointcolorsimplesettingdialog.h \
           private/geodatapoint_finishpointdefinitioncommand.h \
           private/geodatapoint_impl.h \
           private/geodatapointcellmappert_detail.h \
           private/geodatapointcreatort_detail.h \
           private/geodatapointnodemappert_detail.h
FORMS += geodatapointcolorsimplesettingdialog.ui
SOURCES += geodatapoint.cpp \
           geodatapointcreator.cpp \
           geodatapointrealcreator.cpp \
           private/geodatapoint_finishpointdefinitioncommand.cpp
           private/geodatapolyline_removevertexcommand.cpp
TRANSLATIONS += languages/iricGdPoint_ar_EG.ts \
                languages/iricGdPoint_bg_BG.ts \
                languages/iricGdPoint_bs_BA.ts \
                languages/iricGdPoint_ca_ES.ts \
                languages/iricGdPoint_cs_CZ.ts \
                languages/iricGdPoint_da_DK.ts \
                languages/iricGdPoint_de_DE.ts \
                languages/iricGdPoint_el_GR.ts \
                languages/iricGdPoint_es_ES.ts \
                languages/iricGdPoint_et_EE.ts \
                languages/iricGdPoint_eu_ES.ts \
                languages/iricGdPoint_fi_FI.ts \
                languages/iricGdPoint_fr_FR.ts \
                languages/iricGdPoint_gl_ES.ts \
                languages/iricGdPoint_hi_IN.ts \
                languages/iricGdPoint_hu_HU.ts \
                languages/iricGdPoint_id_ID.ts \
                languages/iricGdPoint_is_IS.ts \
                languages/iricGdPoint_it_IT.ts \
                languages/iricGdPoint_ja_JP.ts \
                languages/iricGdPoint_ko_KR.ts \
                languages/iricGdPoint_ky_KG.ts \
                languages/iricGdPoint_lt_LT.ts \
                languages/iricGdPoint_lv_LV.ts \
                languages/iricGdPoint_nb_NO.ts \
                languages/iricGdPoint_nl_NL.ts \
                languages/iricGdPoint_pl_PL.ts \
                languages/iricGdPoint_pt_BR.ts \
                languages/iricGdPoint_pt_PT.ts \
                languages/iricGdPoint_ro_RO.ts \
                languages/iricGdPoint_ru_RU.ts \
                languages/iricGdPoint_sl_SI.ts \
                languages/iricGdPoint_sv_SE.ts \
                languages/iricGdPoint_th_TH.ts \
                languages/iricGdPoint_tr_TR.ts \
                languages/iricGdPoint_uk_UA.ts \
                languages/iricGdPoint_vi_VN.ts \
                languages/iricGdPoint_zh_CN.ts \
                languages/iricGdPoint_zh_TW.ts
