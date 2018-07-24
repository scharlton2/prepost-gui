TEMPLATE = app
TARGET = cgnslink
CONFIG   += console
CONFIG   += c++11

include( ../../paths.pri )

######################
# External libraries #
######################

LIBS += -liriclib

win32{
	LIBS += -lcgnsdll
}
unix{
	LIBS += -lcgns
}

# Input
SOURCES += main.cpp
