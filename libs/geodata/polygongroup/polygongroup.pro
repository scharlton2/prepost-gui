TARGET = iricGdPolygonGroup
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GD_POLYGONGROUP_LIBRARY

DEFINES += ANSI_DECLARATORS

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

# iricGdPolydata

unix {
        LIBS += -L"../polydata"
}
LIBS += -liricGdPolydata

# iricGdPolygon

unix {
        LIBS += -L"../polygon"
}
LIBS += -liricGdPolygon

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

# iricPolydataGroup

unix {
	LIBS += -L"../polydatagroup"
}
LIBS += -liricGdPolydataGroup

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1

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
HEADERS += gd_polygongroup_global.h \
           geodatapolygongroup.h \
           geodatapolygongroupattributebrowser.h \
           geodatapolygongroupcellmappert.h \
           geodatapolygongroupcolorsettingdialog.h \
           geodatapolygongroupcreator.h \
           geodatapolygongroupcreatort.h \
           geodatapolygongroupintegercreator.h \
           geodatapolygongroupmergesettingdialog.h \
           geodatapolygongroupnodemappert.h \
           geodatapolygongrouppolygon.h \
           geodatapolygongrouprangecontainer.h \
           geodatapolygongrouprealcreator.h \
           geodatapolygongroupshpexporter.h \
           geodatapolygongroupshpimporter.h \
           geodatapolygongroupshpimportersettingdialog.h \
           private/geodatapolygongroup_editnameandvaluecommand.h \
           private/geodatapolygongroup_editpropertycommand.h \
           private/geodatapolygongroup_impl.h \
           private/geodatapolygongroup_sortcommand.h \
           private/geodatapolygongroup_sortedittargetpolygoncommand.h \
           private/geodatapolygongroupattributebrowser_tableitemdelegate.h \
           private/geodatapolygongroupcellmappert_detail.h \
           private/geodatapolygongroupcreatort_detail.h \
           private/geodatapolygongroupnodemappert_detail.h \
           private/geodatapolygongrouppolygon_impl.h \
           private/geodatapolygongrouppolygon_triangulatori.h \
           private/geodatapolygongrouppolygon_triangulatortriangle.h \
           private/geodatapolygongrouppolygon_triangulatorvtk.h
FORMS += geodatapolygongroupcolorsettingdialog.ui \
         geodatapolygongroupmergesettingdialog.ui \
         geodatapolygongroupshpimportersettingdialog.ui
SOURCES += geodatapolygongroup.cpp \
           geodatapolygongroupattributebrowser.cpp \
           geodatapolygongroupcolorsettingdialog.cpp \
           geodatapolygongroupcreator.cpp \
           geodatapolygongroupintegercreator.cpp \
           geodatapolygongroupmergesettingdialog.cpp \
           geodatapolygongrouppolygon.cpp \
           geodatapolygongrouprangecontainer.cpp \
           geodatapolygongrouprealcreator.cpp \
           geodatapolygongroupshpexporter.cpp \
           geodatapolygongroupshpimporter.cpp \
           geodatapolygongroupshpimportersettingdialog.cpp \
           private/geodatapolygongroup_editnameandvaluecommand.cpp \
           private/geodatapolygongroup_editpropertycommand.cpp \
           private/geodatapolygongroup_impl.cpp \
           private/geodatapolygongroup_sortcommand.cpp \
           private/geodatapolygongroup_sortedittargetpolygoncommand.cpp \
           private/geodatapolygongroupattributebrowser_tableitemdelegate.cpp \
           private/geodatapolygongrouppolygon_triangulatortriangle.cpp \
           private/geodatapolygongrouppolygon_triangulatorvtk.cpp
TRANSLATIONS += languages/iricGdPolygonGroup_es_ES.ts \
                languages/iricGdPolygonGroup_fr_FR.ts \
                languages/iricGdPolygonGroup_id_ID.ts \
                languages/iricGdPolygonGroup_ja_JP.ts \
                languages/iricGdPolygonGroup_ko_KR.ts \
                languages/iricGdPolygonGroup_ru_RU.ts \
                languages/iricGdPolygonGroup_th_TH.ts \
                languages/iricGdPolygonGroup_vi_VN.ts \
                languages/iricGdPolygonGroup_zh_CN.ts
