TARGET = iricGdPolyLine
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GD_POLYLINE_LIBRARY

DEFINES += ANSI_DECLARATORS

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

# iricGeoio

unix {
	LIBS += -L"../../geoio"
}
LIBS += -liricGeoio

# iricMisc

unix {
	LIBS += -L"../../misc"
}
LIBS += -liricMisc

# iricTriangle

unix {
	LIBS += -L"../../triangle"
}
LIBS += -liricTriangle

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

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1

# iriclib

LIBS += -liriclib

# shapelib

win32{
LIBS += -lshapelib_i
}

# geos

LIBS += -lgeos

win32 {
	DESTDIR = $(SolutionDir)/libdlls/$(Configuration)
	LIBS += -L$(SolutionDir)/libdlls/$(Configuration)
}

# Input
HEADERS += gd_polyline_global.h \
           geodatapolyline.h \
           geodatapolylineabstractpolyline.h \
           geodatapolylinecellmappersetting.h \
           geodatapolylinecellmappert.h \
           geodatapolylinecolorsettingdialog.h \
           geodatapolylinecolorsimplesettingdialog.h \
           geodatapolylinecreator.h \
           geodatapolylinecreatort.h \
           geodatapolylineimplpolyline.h \
           geodatapolylineimporter.h \
           geodatapolylineimportersettingdialog.h \
           geodatapolylineintegercreator.h \
           geodatapolylinenodemappert.h \
           geodatapolylineproxy.h \
           geodatapolylinerealcreator.h \
           geodatapolylineshapeexporter.h \
           private/geodatapolyline_addvertexcommand.h \
           private/geodatapolyline_coordinateseditor.h \
           private/geodatapolyline_editcoordinatescommand.h \
           private/geodatapolyline_editpropertycommand.h \
           private/geodatapolyline_editvaluecommand.h \
           private/geodatapolyline_finishpolylinedefinitioncommand.h \
           private/geodatapolyline_impl.h \
           private/geodatapolyline_modifyabstractpolylinecommand.h \
           private/geodatapolyline_movepolylinecommand.h \
           private/geodatapolyline_movevertexcommand.h \
           private/geodatapolyline_pushnewpointcommand.h \
           private/geodatapolyline_removevertexcommand.h \
           private/geodatapolylineabstractpolyline_impl.h \
           private/geodatapolylinecellmappert_detail.h \
           private/geodatapolylinecreatort_detail.h \
           private/geodatapolylinenodemappert_detail.h
FORMS += geodatapolylinecolorsettingdialog.ui \
         geodatapolylinecolorsimplesettingdialog.ui \
         geodatapolylineimportersettingdialog.ui
SOURCES += geodatapolyline.cpp \
           geodatapolylineabstractpolyline.cpp \
           geodatapolylinecellmappersetting.cpp \
           geodatapolylinecolorsettingdialog.cpp \
           geodatapolylinecolorsimplesettingdialog.cpp \
           geodatapolylinecreator.cpp \
           geodatapolylineimplpolyline.cpp \
           geodatapolylineimporter.cpp \
           geodatapolylineimportersettingdialog.cpp \
           geodatapolylineintegercreator.cpp \
           geodatapolylineproxy.cpp \
           geodatapolylinerealcreator.cpp \
           geodatapolylineshapeexporter.cpp \
           private/geodatapolyline_addvertexcommand.cpp \
           private/geodatapolyline_coordinateseditor.cpp \
           private/geodatapolyline_editcoordinatescommand.cpp \
           private/geodatapolyline_editpropertycommand.cpp \
           private/geodatapolyline_editvaluecommand.cpp \
           private/geodatapolyline_finishpolylinedefinitioncommand.cpp \
           private/geodatapolyline_modifyabstractpolylinecommand.cpp \
           private/geodatapolyline_movepolylinecommand.cpp \
           private/geodatapolyline_movevertexcommand.cpp \
           private/geodatapolyline_pushnewpointcommand.cpp \
           private/geodatapolyline_removevertexcommand.cpp
TRANSLATIONS += languages/iricGdPolyLine_es_ES.ts \
                languages/iricGdPolyLine_fr_FR.ts \
                languages/iricGdPolyLine_id_ID.ts \
                languages/iricGdPolyLine_ja_JP.ts \
                languages/iricGdPolyLine_ko_KR.ts \
                languages/iricGdPolyLine_ru_RU.ts \
                languages/iricGdPolyLine_th_TH.ts \
                languages/iricGdPolyLine_vi_VN.ts \
                languages/iricGdPolyLine_zh_CN.ts
