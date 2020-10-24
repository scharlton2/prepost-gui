######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGccExternalprogram
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GCC_EXTERNALPROGRAM_LIBRARY

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

# iricMisc

unix {
	LIBS += -L"../../misc"
}
LIBS += -liricMisc

# iricGuibase

unix {
	LIBS += -L"../../guibase"
}
LIBS += -liricGuibase

# iricGuicore

unix {
	LIBS += -L"../../guicore"
}
LIBS += -liricGuicore

######################
# External libraries #
######################

# cgnslib
win32 {
	LIBS += -lcgnsdll
}
unix {
	LIBS += -lcgns
}

# iriclib

LIBS += -liriclib

# VTK

LIBS += \
	-lvtkCommonComputationalGeometry-6.1 \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingLabel-6.1

win32 {
	DESTDIR = $(SolutionDir)/libdlls/$(Configuration)
	LIBS += -L$(SolutionDir)/libdlls/$(Configuration)
}

# Input
HEADERS += gcc_externalprogram_global.h \
           gridcreatingconditioncreatorexternalprogram.h \
           gridcreatingconditionexternalprogram.h \
           gridcreatingconditionexternalprogramsettingdialog.h
FORMS += gridcreatingconditionexternalprogramsettingdialog.ui
SOURCES += gridcreatingconditioncreatorexternalprogram.cpp \
           gridcreatingconditionexternalprogram.cpp \
           gridcreatingconditionexternalprogramsettingdialog.cpp
TRANSLATIONS += languages/iricGccExternalprogram_es_ES.ts \
                languages/iricGccExternalprogram_fr_FR.ts \
                languages/iricGccExternalprogram_id_ID.ts \
                languages/iricGccExternalprogram_ja_JP.ts \
                languages/iricGccExternalprogram_ko_KR.ts \
                languages/iricGccExternalprogram_ru_RU.ts \
                languages/iricGccExternalprogram_th_TH.ts \
                languages/iricGccExternalprogram_vi_VN.ts \
                languages/iricGccExternalprogram_zh_CN.ts
