######################################################################
# Automatically generated by qmake (2.01a) ? 10 24 00:36:17 2014
######################################################################

TARGET = iricPostbase
TEMPLATE = lib


DEFINES += POSTBASE_LIBRARY

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

# iricGuibase

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../guibase/debug"
	} else {
		LIBS += -L"../guibase/release"
	}
}
unix {
	LIBS += -L"../guibase"
}
LIBS += -liricGuibase

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

######################
# External libraries #
######################

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingFreeType-6.1

# Input
HEADERS += cfshapeexportwindowinterface.h \
           particleexportwindowinterface.h \
           post2dwindowcontoursetting.h \
           postallzoneselectingdialog.h \
           postbase_global.h \
           postwindowgridtypedataiteminterface.h \
           svkmlexportwindowinterface.h \
           particle/postparticlebasicsetting.h \
           particle/postparticlebasicsettingdialog.h \
           particle/postparticlescalarpropertydialog.h \
           particle/postparticlevectorpropertydialog.h \
           time/posttimedataitem.h \
           time/posttimeeditdialog.h \
           title/posttitledataitem.h \
           title/posttitleeditdialog.h \
           title/posttitlesetting.h \
           title/private/posttitledataitem_setsettingcommand.h
FORMS += postallzoneselectingdialog.ui \
         particle/postparticlebasicsettingdialog.ui \
         particle/postparticlescalarpropertydialog.ui \
         particle/postparticlevectorpropertydialog.ui \
         time/posttimeeditdialog.ui \
         title/posttitleeditdialog.ui
SOURCES += post2dwindowcontoursetting.cpp \
           postallzoneselectingdialog.cpp \
           particle/postparticlebasicsetting.cpp \
           particle/postparticlebasicsettingdialog.cpp \
           particle/postparticlescalarpropertydialog.cpp \
           particle/postparticlevectorpropertydialog.cpp \
           time/posttimedataitem.cpp \
           time/posttimeeditdialog.cpp \
           title/posttitledataitem.cpp \
           title/posttitleeditdialog.cpp \
           title/posttitlesetting.cpp \
           title/private/posttitledataitem_setsettingcommand.cpp
TRANSLATIONS += languages/iricPostbase_es_ES.ts \
                languages/iricPostbase_fr_FR.ts \
                languages/iricPostbase_id_ID.ts \
                languages/iricPostbase_ja_JP.ts \
                languages/iricPostbase_ko_KR.ts \
                languages/iricPostbase_ru_RU.ts \
                languages/iricPostbase_th_TH.ts \
                languages/iricPostbase_vi_VN.ts \
                languages/iricPostbase_zh_CN.ts
