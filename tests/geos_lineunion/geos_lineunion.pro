TEMPLATE = app
TARGET = iricGeosLineUnion
CONFIG   += console
CONFIG   += c++11

include( ../../paths.pri )

# GEOS

LIBS += -lgeos

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkIOCore-6.1 \
	-lvtkIOLegacy-6.1

SOURCES += main.cpp
