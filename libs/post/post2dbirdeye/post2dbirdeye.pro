######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricPost2dbirdeye
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += POST2DBIRDEYE_LIBRARY

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

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

# iricPostbase

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../postbase/debug"
	} else {
		LIBS += -L"../../postbase/release"
	}
}
unix {
	LIBS += -L"../../postbase"
}
LIBS += -liricPostbase


# iricPost2d

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../post2d/debug"
	} else {
		LIBS += -L"../post2d/release"
	}
}
unix {
	LIBS += -L"../post2d"
}
LIBS += -liricPost2d

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-8.2 \
	-lvtkCommonDataModel-8.2 \
	-lvtkCommonExecutionModel-8.2 \
	-lvtkCommonMath-8.2 \
	-lvtkCommonMisc-8.2 \
	-lvtkCommonTransforms-8.2 \
	-lvtkFiltersCore-8.2 \
	-lvtkFiltersGeometry-8.2 \
	-lvtkFiltersGeneral-8.2 \
	-lvtkFiltersExtraction-8.2 \
	-lvtkFiltersFlowPaths-8.2 \
	-lvtkFiltersSources-8.2 \
	-lvtkFiltersTexture-8.2 \
	-lvtkGUISupportQt-8.2 \
	-lvtkInteractionWidgets-8.2 \
	-lvtkIOImage-8.2 \
	-lvtkIOCore-8.2 \
	-lvtkIOLegacy-8.2 \
	-lvtkRenderingAnnotation-8.2 \
	-lvtkRenderingCore-8.2 \
	-lvtkRenderingFreeType-8.2 \
	-lvtkRenderingLabel-8.2 \
	-lvtkRenderingLOD-8.2

# Post-Build Event
win32 {
	QMAKE_POST_LINK += copy $(TargetPath) $(SolutionDir)\\libdlls\\$(Configuration)
}

# Input
HEADERS += post2dbirdeye_global.h \
           post2dbirdeyeobjectbrowser.h \
           post2dbirdeyeobjectbrowserview.h \
           post2dbirdeyewindow.h \
           post2dbirdeyewindowactionmanager.h \
           post2dbirdeyewindowdataitem.h \
           post2dbirdeyewindowdatamodel.h \
           post2dbirdeyewindowgraphicsview.h \
           post2dbirdeyewindowprojectdataitem.h \
           datamodel/post2dbirdeyewindowaxesdataitem.h \
           datamodel/post2dbirdeyewindowgridshapedataitem.h \
           datamodel/post2dbirdeyewindowgridtypedataitem.h \
           datamodel/post2dbirdeyewindowcellscalargroupdataitem.h \
           datamodel/post2dbirdeyewindowcellscalargrouptopdataitem.h \
           datamodel/post2dbirdeyewindownodescalargroupdataitem.h \
           datamodel/post2dbirdeyewindownodescalargrouptopdataitem.h \
           datamodel/post2dbirdeyewindowrootdataitem.h \
           datamodel/post2dbirdeyewindowzonedataitem.h \
           datamodel/private/post2dbirdeyewindowcellscalargroupdataitem_setsettingcommand.h \
           datamodel/private/post2dbirdeyewindownodescalargroupdataitem_setsettingcommand.h
SOURCES += post2dbirdeyeobjectbrowser.cpp \
           post2dbirdeyeobjectbrowserview.cpp \
           post2dbirdeyewindow.cpp \
           post2dbirdeyewindowactionmanager.cpp \
           post2dbirdeyewindowdataitem.cpp \
           post2dbirdeyewindowdatamodel.cpp \
           post2dbirdeyewindowgraphicsview.cpp \
           post2dbirdeyewindowprojectdataitem.cpp \
           datamodel/post2dbirdeyewindowaxesdataitem.cpp \
           datamodel/post2dbirdeyewindowgridshapedataitem.cpp \
           datamodel/post2dbirdeyewindowgridtypedataitem.cpp \
           datamodel/post2dbirdeyewindowcellscalargroupdataitem.cpp \
           datamodel/post2dbirdeyewindowcellscalargrouptopdataitem.cpp \
           datamodel/post2dbirdeyewindownodescalargroupdataitem.cpp \
           datamodel/post2dbirdeyewindownodescalargrouptopdataitem.cpp \
           datamodel/post2dbirdeyewindowrootdataitem.cpp \
           datamodel/post2dbirdeyewindowzonedataitem.cpp \
           datamodel/private/post2dbirdeyewindowcellscalargroupdataitem_setsettingcommand.cpp \
           datamodel/private/post2dbirdeyewindownodescalargroupdataitem_setsettingcommand.cpp
RESOURCES += post2dbirdeye.qrc
TRANSLATIONS += languages/iricPost2dbirdeye_ar_EG.ts \
                languages/iricPost2dbirdeye_bg_BG.ts \
                languages/iricPost2dbirdeye_bs_BA.ts \
                languages/iricPost2dbirdeye_ca_ES.ts \
                languages/iricPost2dbirdeye_cs_CZ.ts \
                languages/iricPost2dbirdeye_da_DK.ts \
                languages/iricPost2dbirdeye_de_DE.ts \
                languages/iricPost2dbirdeye_el_GR.ts \
                languages/iricPost2dbirdeye_es_ES.ts \
                languages/iricPost2dbirdeye_et_EE.ts \
                languages/iricPost2dbirdeye_eu_ES.ts \
                languages/iricPost2dbirdeye_fi_FI.ts \
                languages/iricPost2dbirdeye_fr_FR.ts \
                languages/iricPost2dbirdeye_gl_ES.ts \
                languages/iricPost2dbirdeye_hi_IN.ts \
                languages/iricPost2dbirdeye_hu_HU.ts \
                languages/iricPost2dbirdeye_id_ID.ts \
                languages/iricPost2dbirdeye_is_IS.ts \
                languages/iricPost2dbirdeye_it_IT.ts \
                languages/iricPost2dbirdeye_ja_JP.ts \
                languages/iricPost2dbirdeye_ko_KR.ts \
                languages/iricPost2dbirdeye_ky_KG.ts \
                languages/iricPost2dbirdeye_lt_LT.ts \
                languages/iricPost2dbirdeye_lv_LV.ts \
                languages/iricPost2dbirdeye_nb_NO.ts \
                languages/iricPost2dbirdeye_nl_NL.ts \
                languages/iricPost2dbirdeye_pl_PL.ts \
                languages/iricPost2dbirdeye_pt_BR.ts \
                languages/iricPost2dbirdeye_pt_PT.ts \
                languages/iricPost2dbirdeye_ro_RO.ts \
                languages/iricPost2dbirdeye_ru_RU.ts \
                languages/iricPost2dbirdeye_sl_SI.ts \
                languages/iricPost2dbirdeye_sv_SE.ts \
                languages/iricPost2dbirdeye_th_TH.ts \
                languages/iricPost2dbirdeye_tr_TR.ts \
                languages/iricPost2dbirdeye_uk_UA.ts \
                languages/iricPost2dbirdeye_vi_VN.ts \
                languages/iricPost2dbirdeye_zh_CN.ts \
                languages/iricPost2dbirdeye_zh_TW.ts
