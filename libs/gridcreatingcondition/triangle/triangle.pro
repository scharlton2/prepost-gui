######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGccTriangle
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GCC_TRIANGLE_LIBRARY

DEFINES += ANSI_DECLARATORS

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
	-lvtkCommonComputationalGeometry-6.1 \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingLabel-6.1

# Post-Build Event
win32 {
	QMAKE_POST_LINK += copy $(TargetPath) $(SolutionDir)\\libdlls\\$(Configuration)
}

# Input
HEADERS += gcc_triangle_global.h \
           gridcreatingconditioncreatortriangle.h \
           gridcreatingconditiontriangle.h \
           gridcreatingconditiontriangleabstractline.h \
           gridcreatingconditiontriangleabstractpolygon.h \
           gridcreatingconditiontriangledivisionline.h \
           gridcreatingconditiontrianglegridregionpolygon.h \
           gridcreatingconditiontriangleholepolygon.h \
           gridcreatingconditiontrianglepolygoncoordinateseditdialog.h \
           gridcreatingconditiontrianglepolylinecoordinateseditdialog.h \
           gridcreatingconditiontriangleremeshdialog.h \
           gridcreatingconditiontriangleremeshpolygon.h \
           gridcreatingconditiontrianglesettingdialog.h \
           private/gridcreatingconditiontriangle_addpolygonvertexcommand.h \
           private/gridcreatingconditiontriangle_addremeshpolygoncommand.h \
           private/gridcreatingconditiontriangle_definepolygonnewpointcommand.h \
           private/gridcreatingconditiontriangle_definepolylinenewpointcommand.h \
           private/gridcreatingconditiontriangle_finishpolygondefiningcommand.h \
           private/gridcreatingconditiontriangle_finishpolylinedefiningcommand.h \
           private/gridcreatingconditiontriangle_movepolygoncommand.h \
           private/gridcreatingconditiontriangle_movepolygonvertexcommand.h
FORMS += gridcreatingconditiontrianglepolygoncoordinateseditdialog.ui \
         gridcreatingconditiontrianglepolylinecoordinateseditdialog.ui \
         gridcreatingconditiontriangleremeshdialog.ui \
         gridcreatingconditiontrianglesettingdialog.ui
SOURCES += gridcreatingconditioncreatortriangle.cpp \
           gridcreatingconditiontriangle.cpp \
           gridcreatingconditiontriangleabstractline.cpp \
           gridcreatingconditiontriangleabstractpolygon.cpp \
           gridcreatingconditiontriangledivisionline.cpp \
           gridcreatingconditiontrianglegridregionpolygon.cpp \
           gridcreatingconditiontriangleholepolygon.cpp \
           gridcreatingconditiontrianglepolygoncoordinateseditdialog.cpp \
           gridcreatingconditiontrianglepolylinecoordinateseditdialog.cpp \
           gridcreatingconditiontriangleremeshdialog.cpp \
           gridcreatingconditiontriangleremeshpolygon.cpp \
           gridcreatingconditiontrianglesettingdialog.cpp \
           private/gridcreatingconditiontriangle_addpolygonvertexcommand.cpp \
           private/gridcreatingconditiontriangle_addremeshpolygoncommand.cpp \
           private/gridcreatingconditiontriangle_definepolygonnewpointcommand.cpp \
           private/gridcreatingconditiontriangle_definepolylinenewpointcommand.cpp \
           private/gridcreatingconditiontriangle_finishpolygondefiningcommand.cpp \
           private/gridcreatingconditiontriangle_finishpolylinedefiningcommand.cpp \
           private/gridcreatingconditiontriangle_movepolygoncommand.cpp \
           private/gridcreatingconditiontriangle_movepolygonvertexcommand.cpp
TRANSLATIONS += languages/iricGccTriangle_es_ES.ts \
                languages/iricGccTriangle_fr_FR.ts \
                languages/iricGccTriangle_id_ID.ts \
                languages/iricGccTriangle_ja_JP.ts \
                languages/iricGccTriangle_ko_KR.ts \
                languages/iricGccTriangle_ru_RU.ts \
                languages/iricGccTriangle_th_TH.ts \
                languages/iricGccTriangle_vi_VN.ts \
                languages/iricGccTriangle_zh_CN.ts
