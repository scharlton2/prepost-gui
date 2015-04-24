######################################################################
# Automatically generated by qmake (2.01a) ? 10 24 09:50:18 2014
######################################################################

TARGET = iricSolverconsole
TEMPLATE = lib
INCLUDEPATH += ..

DEFINES += SOLVERCONSOLE_LIBRARY

include( ../../paths.pri )

QT += widgets xml

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

# iricGuicore

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../guicore/debug"
	} else {
		LIBS += -L"../guicore/release"
	}
}
unix {
	LIBS += -L"../guicore"
}
LIBS += -liricGuicore

# Input
HEADERS += solverconsole_global.h \
           solverconsolewindow.h \
           solverconsolewindowprojectdataitem.h
SOURCES += solverconsolewindow.cpp \
           solverconsolewindowprojectdataitem.cpp
RESOURCES += solverconsole.qrc
TRANSLATIONS += languages/iricSolverconsole_es_ES.ts \
                languages/iricSolverconsole_fr_FR.ts \
                languages/iricSolverconsole_id_ID.ts \
                languages/iricSolverconsole_ja_JP.ts \
                languages/iricSolverconsole_ko_KR.ts \
                languages/iricSolverconsole_ru_RU.ts \
                languages/iricSolverconsole_th_TH.ts \
                languages/iricSolverconsole_vi_VN.ts \
                languages/iricSolverconsole_zh_CN.ts
