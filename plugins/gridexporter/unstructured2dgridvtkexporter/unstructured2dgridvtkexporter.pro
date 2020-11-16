#-------------------------------------------------
#
# Project created by QtCreator 2014-10-17T11:05:29
#
#-------------------------------------------------

TARGET  = $$qtLibraryTarget(unstructured2dgridvtkexporter)
QT       += widgets xml
TEMPLATE = lib
CONFIG += plugin

include( ../../../paths.pri )

# iricGuicore library

unix {
	LIBS += -L"../../../libs/guicore"
}
LIBS += -liricGuicore

# iricMisc library

unix {
	LIBS += -L"../../../libs/misc"
}
LIBS += -liricMisc

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkIOCore-6.1 \
	-lvtkIOLegacy-6.1

win32 {
	DESTDIR = $(SolutionDir)/libdlls/$(Configuration)
	LIBS += -L$(SolutionDir)/libdlls/$(Configuration)
}

# Input
HEADERS += unstructured2dgridvtkexporter.h
SOURCES += unstructured2dgridvtkexporter.cpp
TRANSLATIONS += languages/unstructured2dgridvtkexporter_es_ES.ts \
                languages/unstructured2dgridvtkexporter_fr_FR.ts \
                languages/unstructured2dgridvtkexporter_id_ID.ts \
                languages/unstructured2dgridvtkexporter_ja_JP.ts \
                languages/unstructured2dgridvtkexporter_ko_KR.ts \
                languages/unstructured2dgridvtkexporter_ru_RU.ts \
                languages/unstructured2dgridvtkexporter_th_TH.ts \
                languages/unstructured2dgridvtkexporter_vi_VN.ts \
                languages/unstructured2dgridvtkexporter_zh_CN.ts
