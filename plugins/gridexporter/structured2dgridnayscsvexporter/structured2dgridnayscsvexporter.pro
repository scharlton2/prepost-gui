#-------------------------------------------------
#
# Project created by QtCreator 2014-10-17T11:05:29
#
#-------------------------------------------------

TARGET  = $$qtLibraryTarget(structured2dgridnayscsvexporter)
QT       += widgets xml
TEMPLATE = lib
CONFIG += plugin

include( ../../../paths.pri )

# iricGuicore library

unix {
	LIBS += -L"../../../libs/guicore"
}
LIBS += -liricGuicore

# VTK

LIBS += \
	-lvtkCommonCore-6.1

win32 {
	DESTDIR = $(SolutionDir)/libdlls/$(Configuration)
	LIBS += -L$(SolutionDir)/libdlls/$(Configuration)
}

# Input
HEADERS += structured2dgridnayscsvexporter.h
SOURCES += structured2dgridnayscsvexporter.cpp
TRANSLATIONS += languages/structured2dgridnayscsvexporter_es_ES.ts \
                languages/structured2dgridnayscsvexporter_fr_FR.ts \
                languages/structured2dgridnayscsvexporter_id_ID.ts \
                languages/structured2dgridnayscsvexporter_ja_JP.ts \
                languages/structured2dgridnayscsvexporter_ko_KR.ts \
                languages/structured2dgridnayscsvexporter_ru_RU.ts \
                languages/structured2dgridnayscsvexporter_th_TH.ts \
                languages/structured2dgridnayscsvexporter_vi_VN.ts \
                languages/structured2dgridnayscsvexporter_zh_CN.ts
