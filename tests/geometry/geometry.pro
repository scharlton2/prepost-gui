######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 12:19:59 2014
######################################################################

TEMPLATE = app
TARGET = geometryTest
CONFIG   += console
CONFIG   += c++11

include( ../../paths.pri )

######################
# Internal libraries #
######################

#iricMisc library

unix {
	LIBS += -L"../../libs/guibase"
}
LIBS += -liricGuibase

win32 {
	LIBS += -L$(SolutionDir)/libdlls/$(Configuration)
}

SOURCES += geometry.cpp
