######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricGraph2d
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += GRAPH2D_LIBRARY

include( ../../../paths.pri )

QT += widgets xml

######################
# Internal libraries #
######################

# iricMisc

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../misc/debug"
	} else {
		LIBS += -L"../../misc/release"
	}
}
unix {
	LIBS += -L"../../misc"
}
LIBS += -liricMisc

# iricGuibase

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../guibase/debug"
	} else {
		LIBS += -L"../../guibase/release"
	}
}
unix {
	LIBS += -L"../../guibase"
}
LIBS += -liricGuibase

# iricGuicore

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../guicore/debug"
	} else {
		LIBS += -L"../../guicore/release"
	}
}
unix {
	LIBS += -L"../../guicore"
}
LIBS += -liricGuicore

# iricPostbase

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../postbase/debug"
	} else {
		LIBS += -L"../../postbase/release"
	}
}
unix {
	LIBS += -L"../../postbase"
}
LIBS += -liricPostbase

######################
# External libraries #
######################

# Qwt

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -lqwtd
	}
	else {
		LIBS += -lqwt
		DEFINES += QT_NO_DEBUG_OUTPUT
		DEFINES += QT_NO_WARNING_OUTPUT
	}
}
unix {
	LIBS += -lqwt
	DEFINES += QT_NO_DEBUG_OUTPUT
	DEFINES += QT_NO_WARNING_OUTPUT
}

# Input
HEADERS += graph2d_global.h \
           graph2dwindowdataitem.h \
           graph2dwindowdatamodel.h \
           graph2dwindowmarkersetting.h \
           graph2dwindowmarkersettingdialog.h \
           graph2dwindowrootdataitem.h \
           graph2dwindowverticalaxissetting.h \
           graph2dwindowverticalaxissettingdialog.h \
           graph2dwindowview.h \
           datamodel/graph2dwindowmarkerdataitem.h \
           datamodel/graph2dwindowmarkergroupdataitem.h
FORMS += graph2dwindowmarkersettingdialog.ui \
         graph2dwindowverticalaxissettingdialog.ui
SOURCES += graph2dwindowdataitem.cpp \
           graph2dwindowdatamodel.cpp \
           graph2dwindowmarkersetting.cpp \
           graph2dwindowmarkersettingdialog.cpp \
           graph2dwindowrootdataitem.cpp \
           graph2dwindowverticalaxissetting.cpp \
           graph2dwindowverticalaxissettingdialog.cpp \
           graph2dwindowview.cpp \
           datamodel/graph2dwindowmarkerdataitem.cpp \
           datamodel/graph2dwindowmarkergroupdataitem.cpp
TRANSLATIONS += languages/iricGraph2d_es_ES.ts \
                languages/iricGraph2d_fr_FR.ts \
                languages/iricGraph2d_id_ID.ts \
                languages/iricGraph2d_ja_JP.ts \
                languages/iricGraph2d_ko_KR.ts \
                languages/iricGraph2d_ru_RU.ts \
                languages/iricGraph2d_th_TH.ts \
                languages/iricGraph2d_vi_VN.ts \
                languages/iricGraph2d_zh_CN.ts
