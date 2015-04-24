######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGccRiversurvey15d
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GCC_RIVERSURVEY15D_LIBRARY

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

win32{
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

# iricRdRiversurvey

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../rawdata/riversurvey/debug"
	} else {
		LIBS += -L"../../rawdata/riversurvey/release"
	}
}
unix {
	LIBS += -L"../../rawdata/riversurvey"
}
LIBS += -liricRdRiversurvey

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkCommonExecutionModel-6.1 \
	-lvtkFiltersCore-6.1 \
	-lvtkFiltersExtraction-6.1 \
	-lvtkFiltersGeometry-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingLOD-6.1

# Input
HEADERS += gcc_riversurvey15d_global.h \
           gridcreatingconditioncreatorriversurvey15d.h \
           gridcreatingconditionriversurvey15d.h \
           gridcreatingconditionriversurvey15dpointadddialog.h \
           gridcreatingconditionriversurvey15dpointmovedialog.h \
           gridcreatingconditionriversurvey15dpointregionadddialog.h \
           gridcreatingconditionriversurvey15dpointrepositiondialog.h \
           gridcreatingconditionriversurvey15dregiondialog.h
FORMS += gridcreatingconditionriversurvey15dpointadddialog.ui \
         gridcreatingconditionriversurvey15dpointmovedialog.ui \
         gridcreatingconditionriversurvey15dpointregionadddialog.ui \
         gridcreatingconditionriversurvey15dpointrepositiondialog.ui \
         gridcreatingconditionriversurvey15dregiondialog.ui
SOURCES += gridcreatingconditioncreatorriversurvey15d.cpp \
           gridcreatingconditionriversurvey15d.cpp \
           gridcreatingconditionriversurvey15dpointadddialog.cpp \
           gridcreatingconditionriversurvey15dpointmovedialog.cpp \
           gridcreatingconditionriversurvey15dpointregionadddialog.cpp \
           gridcreatingconditionriversurvey15dpointrepositiondialog.cpp \
           gridcreatingconditionriversurvey15dregiondialog.cpp
TRANSLATIONS += languages/iricGccRiversurvey15d_es_ES.ts \
                languages/iricGccRiversurvey15d_fr_FR.ts \
                languages/iricGccRiversurvey15d_id_ID.ts \
                languages/iricGccRiversurvey15d_ja_JP.ts \
                languages/iricGccRiversurvey15d_ko_KR.ts \
                languages/iricGccRiversurvey15d_ru_RU.ts \
                languages/iricGccRiversurvey15d_th_TH.ts \
                languages/iricGccRiversurvey15d_vi_VN.ts \
                languages/iricGccRiversurvey15d_zh_CN.ts
