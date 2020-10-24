#-------------------------------------------------
#
# Project created by QtCreator 2014-10-17T11:05:29
#
#-------------------------------------------------

TARGET  = $$qtLibraryTarget(structured2dgridnaysgridimporter)
TEMPLATE = lib
CONFIG += plugin
QT       += widgets xml

include( ../../../paths.pri )

# iricGuicore library

LIBS += -liricGuicore

# VTK

LIBS += \
	-lvtkCommonCore-6.1

win32 {
	DESTDIR = $(SolutionDir)/libdlls/$(Configuration)
	LIBS += -L$(SolutionDir)/libdlls/$(Configuration)
}

# Input
HEADERS += structured2dgridnaysgridimporter.h
SOURCES += structured2dgridnaysgridimporter.cpp
TRANSLATIONS += languages/structured2dgridnaysgridimporter_es_ES.ts \
                languages/structured2dgridnaysgridimporter_fr_FR.ts \
                languages/structured2dgridnaysgridimporter_id_ID.ts \
                languages/structured2dgridnaysgridimporter_ja_JP.ts \
                languages/structured2dgridnaysgridimporter_ko_KR.ts \
                languages/structured2dgridnaysgridimporter_ru_RU.ts \
                languages/structured2dgridnaysgridimporter_th_TH.ts \
                languages/structured2dgridnaysgridimporter_vi_VN.ts \
                languages/structured2dgridnaysgridimporter_zh_CN.ts
