######################################################################
# Automatically generated by qmake (2.01a) ? 10 23 18:49:25 2014
######################################################################

TARGET = iricPost3d
TEMPLATE = lib
INCLUDEPATH += ../..

DEFINES += POST3D_LIBRARY

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

# VTK

LIBS += \
	-lvtkCommonCore-6.1 \
	-lvtkCommonDataModel-6.1 \
	-lvtkCommonExecutionModel-6.1 \
	-lvtkCommonMath-6.1 \
	-lvtkCommonMisc-6.1 \
	-lvtkCommonTransforms-6.1 \
	-lvtkFiltersCore-6.1 \
	-lvtkFiltersGeometry-6.1 \
	-lvtkFiltersGeneral-6.1 \
	-lvtkFiltersExtraction-6.1 \
	-lvtkFiltersFlowPaths-6.1 \
	-lvtkFiltersSources-6.1 \
	-lvtkFiltersTexture-6.1 \
	-lvtkGUISupportQt-6.1 \
	-lvtkInteractionWidgets-6.1 \
	-lvtkIOImage-6.1 \
	-lvtkIOCore-6.1 \
	-lvtkIOLegacy-6.1 \
	-lvtkRenderingAnnotation-6.1 \
	-lvtkRenderingCore-6.1 \
	-lvtkRenderingFreeType-6.1 \
	-lvtkRenderingLabel-6.1 \
	-lvtkRenderingLOD-6.1

# Input
HEADERS += post3d_global.h \
           post3dobjectbrowser.h \
           post3dobjectbrowserview.h \
           post3dwindow.h \
           post3dwindowactionmanager.h \
           post3dwindowdataitem.h \
           post3dwindowdatamodel.h \
           post3dwindowgraphicsview.h \
           post3dwindowprojectdataitem.h \
           datamodel/post3dwindowarrowgroupdataitem.h \
           datamodel/post3dwindowarrowgroupsettingdialog.h \
           datamodel/post3dwindowcontourgroupdataitem.h \
           datamodel/post3dwindowcontourgroupsettingdialog.h \
           datamodel/post3dwindowfacedataitem.h \
           datamodel/post3dwindowfacesettingwidget.h \
           datamodel/post3dwindowgridshapedataitem.h \
           datamodel/post3dwindowgridtypedataitem.h \
           datamodel/post3dwindowisosurfacesettingdialog.h \
           datamodel/post3dwindownodescalardataitem.h \
           datamodel/post3dwindownodescalargroupdataitem.h \
           datamodel/post3dwindownodevectorparticledataitem.h \
           datamodel/post3dwindownodevectorparticlegroupdataitem.h \
           datamodel/post3dwindownodevectorparticlegroupstructureddataitem.h \
           datamodel/post3dwindownodevectorstreamlinedataitem.h \
           datamodel/post3dwindownodevectorstreamlinegroupdataitem.h \
           datamodel/post3dwindownodevectorstreamlinegroupstructureddataitem.h \
           datamodel/post3dwindowparticlestopdataitem.h \
           datamodel/post3dwindowparticlestructuredsettingdialog.h \
           datamodel/post3dwindowrootdataitem.h \
           datamodel/post3dwindowstreamlinestructuredsettingdialog.h \
           datamodel/post3dwindowsurfacedataitem.h \
           datamodel/post3dwindowsurfacegroupdataitem.h \
           datamodel/post3dwindowzonedataitem.h
FORMS += datamodel/post3dwindowarrowgroupsettingdialog.ui \
         datamodel/post3dwindowcontourgroupsettingdialog.ui \
         datamodel/post3dwindowfacesettingwidget.ui \
         datamodel/post3dwindowisosurfacesettingdialog.ui \
         datamodel/post3dwindowparticlestructuredsettingdialog.ui \
         datamodel/post3dwindowstreamlinestructuredsettingdialog.ui
SOURCES += post3dobjectbrowser.cpp \
           post3dobjectbrowserview.cpp \
           post3dwindow.cpp \
           post3dwindowactionmanager.cpp \
           post3dwindowdataitem.cpp \
           post3dwindowdatamodel.cpp \
           post3dwindowgraphicsview.cpp \
           post3dwindowprojectdataitem.cpp \
           datamodel/post3dwindowarrowgroupdataitem.cpp \
           datamodel/post3dwindowarrowgroupsettingdialog.cpp \
           datamodel/post3dwindowcontourgroupdataitem.cpp \
           datamodel/post3dwindowcontourgroupsettingdialog.cpp \
           datamodel/post3dwindowfacedataitem.cpp \
           datamodel/post3dwindowfacesettingwidget.cpp \
           datamodel/post3dwindowgridshapedataitem.cpp \
           datamodel/post3dwindowgridtypedataitem.cpp \
           datamodel/post3dwindowisosurfacesettingdialog.cpp \
           datamodel/post3dwindownodescalardataitem.cpp \
           datamodel/post3dwindownodescalargroupdataitem.cpp \
           datamodel/post3dwindownodevectorparticledataitem.cpp \
           datamodel/post3dwindownodevectorparticlegroupdataitem.cpp \
           datamodel/post3dwindownodevectorparticlegroupstructureddataitem.cpp \
           datamodel/post3dwindownodevectorstreamlinedataitem.cpp \
           datamodel/post3dwindownodevectorstreamlinegroupdataitem.cpp \
           datamodel/post3dwindownodevectorstreamlinegroupstructureddataitem.cpp \
           datamodel/post3dwindowparticlestopdataitem.cpp \
           datamodel/post3dwindowparticlestructuredsettingdialog.cpp \
           datamodel/post3dwindowrootdataitem.cpp \
           datamodel/post3dwindowstreamlinestructuredsettingdialog.cpp \
           datamodel/post3dwindowsurfacedataitem.cpp \
           datamodel/post3dwindowsurfacegroupdataitem.cpp \
           datamodel/post3dwindowzonedataitem.cpp
RESOURCES += post3d.qrc
TRANSLATIONS += languages/iricPost3d_es_ES.ts \
                languages/iricPost3d_fr_FR.ts \
                languages/iricPost3d_id_ID.ts \
                languages/iricPost3d_ja_JP.ts \
                languages/iricPost3d_ko_KR.ts \
                languages/iricPost3d_ru_RU.ts \
                languages/iricPost3d_th_TH.ts \
                languages/iricPost3d_vi_VN.ts \
                languages/iricPost3d_zh_CN.ts
