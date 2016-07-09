######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGeoio
TEMPLATE = lib
INCLUDEPATH += ..

DEFINES += GEOIO_LIBRARY

QT += widgets

include( ../../paths.pri )

######################
# Internal libraries #
######################

# iricMisc

win32 {
        CONFIG(debug, debug|release) {
                LIBS += -L"../misc/debug"
        } else {
                LIBS += -L"../misc/release"
        }
}
unix {
        LIBS += -L"../misc"
}
LIBS += -liricMisc

######################
# External libraries #
######################

# shapelib

win32{
	LIBS += -lshapelib_i
}

# geos

LIBS += -lgeos

# Input
HEADERS += geoio_global.h \
           io.h \
           polygoncsvexporter.h \
           polygoncsvimporter.h \
           polygonexporterfactory.h \
           polygonexporteri.h \
           polygonimporterfactory.h \
           polygonimporteri.h \
           polygonio.h \
           polygonshapeexporter.h \
           polygonshapeimporter.h \
           polylinecsvexporter.h \
           polylinecsvimporter.h \
           polylineexporterfactory.h \
           polylineexporteri.h \
           polylineimporterfactory.h \
           polylineimporteri.h \
           polylineio.h \
           polylineshapeexporter.h \
           polylineshapeimporter.h \
           private/csvhelper.h \
           private/dbfitemselectdialog.h \
           private/polygonexporterfactory_impl.h \
           private/polygonimporterfactory_impl.h \
           private/polylineexporterfactory_impl.h \
           private/polylineimporterfactory_impl.h
FORMS += private/dbfitemselectdialog.ui
SOURCES += polygoncsvexporter.cpp \
           polygoncsvimporter.cpp \
           polygonexporterfactory.cpp \
           polygonimporterfactory.cpp \
           polygonio.cpp \
           polygonshapeexporter.cpp \
           polygonshapeimporter.cpp \
           polylinecsvexporter.cpp \
           polylinecsvimporter.cpp \
           polylineexporterfactory.cpp \
           polylineimporterfactory.cpp \
           polylineio.cpp \
           polylineshapeexporter.cpp \
           polylineshapeimporter.cpp \
           private/csvhelper.cpp \
           private/dbfitemselectdialog.cpp
