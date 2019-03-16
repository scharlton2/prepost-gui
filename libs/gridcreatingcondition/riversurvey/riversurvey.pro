######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGccRiversurvey
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GCC_RIVERSURVEY_LIBRARY

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

# iricGdRiversurvey

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../geodata/riversurvey/debug"
	} else {
		LIBS += -L"../../geodata/riversurvey/release"
	}
}
unix {
	LIBS += -L"../../geodata/riversurvey"
}
LIBS += -liricGdRiversurvey

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-8.2 \
	-lvtkCommonDataModel-8.2 \
	-lvtkCommonExecutionModel-8.2 \
	-lvtkFiltersCore-8.2 \
	-lvtkFiltersExtraction-8.2 \
	-lvtkFiltersGeometry-8.2 \
	-lvtkIOCore-8.2 \
	-lvtkIOLegacy-8.2 \
	-lvtkRenderingCore-8.2 \
	-lvtkRenderingLabel-8.2 \
	-lvtkRenderingLOD-8.2

# Post-Build Event
win32 {
	QMAKE_POST_LINK += copy $(TargetPath) $(SolutionDir)\\libdlls\\$(Configuration)
}

# Input
HEADERS += gcc_riversurvey_global.h \
           gridcreatingconditioncreatorriversurvey.h \
           gridcreatingconditionriversurvey.h \
           gridcreatingconditionriversurveypointadddialog.h \
           gridcreatingconditionriversurveypointmovedialog.h \
           gridcreatingconditionriversurveypointregionadddialog.h \
           gridcreatingconditionriversurveypointrepositiondialog.h \
           gridcreatingconditionriversurveyregiondialog.h
FORMS += gridcreatingconditionriversurveypointadddialog.ui \
         gridcreatingconditionriversurveypointmovedialog.ui \
         gridcreatingconditionriversurveypointregionadddialog.ui \
         gridcreatingconditionriversurveypointrepositiondialog.ui \
         gridcreatingconditionriversurveyregiondialog.ui
SOURCES += gridcreatingconditioncreatorriversurvey.cpp \
           gridcreatingconditionriversurvey.cpp \
           gridcreatingconditionriversurveypointadddialog.cpp \
           gridcreatingconditionriversurveypointmovedialog.cpp \
           gridcreatingconditionriversurveypointregionadddialog.cpp \
           gridcreatingconditionriversurveypointrepositiondialog.cpp \
           gridcreatingconditionriversurveyregiondialog.cpp
RESOURCES += riversurvey.qrc
TRANSLATIONS += languages/iricGccRiversurvey_ar_EG.ts \
                languages/iricGccRiversurvey_bg_BG.ts \
                languages/iricGccRiversurvey_bs_BA.ts \
                languages/iricGccRiversurvey_ca_ES.ts \
                languages/iricGccRiversurvey_cs_CZ.ts \
                languages/iricGccRiversurvey_da_DK.ts \
                languages/iricGccRiversurvey_de_DE.ts \
                languages/iricGccRiversurvey_el_GR.ts \
                languages/iricGccRiversurvey_es_ES.ts \
                languages/iricGccRiversurvey_et_EE.ts \
                languages/iricGccRiversurvey_eu_ES.ts \
                languages/iricGccRiversurvey_fi_FI.ts \
                languages/iricGccRiversurvey_fr_FR.ts \
                languages/iricGccRiversurvey_gl_ES.ts \
                languages/iricGccRiversurvey_hi_IN.ts \
                languages/iricGccRiversurvey_hu_HU.ts \
                languages/iricGccRiversurvey_id_ID.ts \
                languages/iricGccRiversurvey_is_IS.ts \
                languages/iricGccRiversurvey_it_IT.ts \
                languages/iricGccRiversurvey_ja_JP.ts \
                languages/iricGccRiversurvey_ko_KR.ts \
                languages/iricGccRiversurvey_ky_KG.ts \
                languages/iricGccRiversurvey_lt_LT.ts \
                languages/iricGccRiversurvey_lv_LV.ts \
                languages/iricGccRiversurvey_nb_NO.ts \
                languages/iricGccRiversurvey_nl_NL.ts \
                languages/iricGccRiversurvey_pl_PL.ts \
                languages/iricGccRiversurvey_pt_BR.ts \
                languages/iricGccRiversurvey_pt_PT.ts \
                languages/iricGccRiversurvey_ro_RO.ts \
                languages/iricGccRiversurvey_ru_RU.ts \
                languages/iricGccRiversurvey_sl_SI.ts \
                languages/iricGccRiversurvey_sv_SE.ts \
                languages/iricGccRiversurvey_th_TH.ts \
                languages/iricGccRiversurvey_tr_TR.ts \
                languages/iricGccRiversurvey_uk_UA.ts \
                languages/iricGccRiversurvey_vi_VN.ts \
                languages/iricGccRiversurvey_zh_CN.ts \
                languages/iricGccRiversurvey_zh_TW.ts
