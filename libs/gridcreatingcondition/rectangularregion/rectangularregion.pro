######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGccRectangularregion
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GCC_RECTANGULARREGION_LIBRARY

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
HEADERS += gcc_rectangularregion_global.h \
           gridcreatingconditioncreatorrectangularregion.h \
           gridcreatingconditionrectangularregion.h \
           gridcreatingconditionrectangularregionsettingdialog.h
FORMS += gridcreatingconditionrectangularregionsettingdialog.ui
SOURCES += gridcreatingconditioncreatorrectangularregion.cpp \
           gridcreatingconditionrectangularregion.cpp \
           gridcreatingconditionrectangularregionsettingdialog.cpp
RESOURCES += rectangularregion.qrc
TRANSLATIONS += languages/iricGccRectangularregion_es_ES.ts \
                languages/iricGccRectangularregion_fr_FR.ts \
                languages/iricGccRectangularregion_id_ID.ts \
                languages/iricGccRectangularregion_ja_JP.ts \
                languages/iricGccRectangularregion_ko_KR.ts \
                languages/iricGccRectangularregion_ru_RU.ts \
                languages/iricGccRectangularregion_th_TH.ts \
                languages/iricGccRectangularregion_vi_VN.ts \
                languages/iricGccRectangularregion_zh_CN.ts
