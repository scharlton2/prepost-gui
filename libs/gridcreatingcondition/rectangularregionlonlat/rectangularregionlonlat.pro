######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGccRectangularregionlonlat
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GCC_RECTANGULARREGIONLONLAT_LIBRARY

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

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonComputationalGeometry-6.1 \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingLabel-6.1

# Post-Build Event
win32 {
	DESTDIR = $(SolutionDir)\\libdlls\\$(Configuration)
	LIBS += -L$(SolutionDir)\\libdlls\\$(Configuration)
}

# Input
HEADERS += gcc_rectangularregionlonlat_global.h \
           gridcreatingconditioncreatorrectangularregionlonlat.h \
           gridcreatingconditionrectangularregionlonlat.h \
           gridcreatingconditionrectangularregionlonlatsettingdialog.h
FORMS += gridcreatingconditionrectangularregionlonlatsettingdialog.ui
SOURCES += gridcreatingconditioncreatorrectangularregionlonlat.cpp \
           gridcreatingconditionrectangularregionlonlat.cpp \
           gridcreatingconditionrectangularregionlonlatsettingdialog.cpp
RESOURCES += rectangularregionlonlat.qrc
TRANSLATIONS += languages/iricGccRectangularregionlonlat_es_ES.ts \
                languages/iricGccRectangularregionlonlat_fr_FR.ts \
                languages/iricGccRectangularregionlonlat_id_ID.ts \
                languages/iricGccRectangularregionlonlat_ja_JP.ts \
                languages/iricGccRectangularregionlonlat_ko_KR.ts \
                languages/iricGccRectangularregionlonlat_ru_RU.ts \
                languages/iricGccRectangularregionlonlat_th_TH.ts \
                languages/iricGccRectangularregionlonlat_vi_VN.ts \
                languages/iricGccRectangularregionlonlat_zh_CN.ts
