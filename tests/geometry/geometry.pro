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
	LIBS += -L"../../libs/misc"
	LIBS += -liricMisc
}

#iriGuibase library

win32 {
	CONFIG(debug, debug|release) {
		LIBS += -L"../../libs/guibase/debug"
	} else {
		LIBS += -L"../../libs/guibase/release"
	}
}
unix {
	LIBS += -L"../../libs/guibase"
}
LIBS += -liricGuibase

######################
# External libraries #
######################

#qwt library

unix {
	LIBS += -lqwt
}


#VTK
unix {
	LIBS += \
		-lvtkalglib-6.1 \
		-lvtkCommonComputationalGeometry-6.1 \
		-lvtkCommonCore-6.1 \
		-lvtkCommonDataModel-6.1 \
		-lvtkCommonExecutionModel-6.1 \
		-lvtkCommonMath-6.1 \
		-lvtkCommonMisc-6.1 \
		-lvtkCommonSystem-6.1 \
		-lvtkCommonTransforms-6.1 \
		-lvtkFiltersCore-6.1 \
		-lvtkFiltersExtraction-6.1 \
		-lvtkFiltersFlowPaths-6.1 \
		-lvtkFiltersGeneral-6.1 \
		-lvtkFiltersGeometry-6.1 \
		-lvtkFiltersHybrid-6.1 \
		-lvtkFiltersModeling-6.1 \
		-lvtkFiltersSources-6.1 \
		-lvtkFiltersStatistics-6.1 \
		-lvtkfreetype-6.1 \
		-lvtkftgl-6.1 \
		-lvtkImagingCore-6.1 \
		-lvtkImagingFourier-6.1 \
		-lvtkImagingSources-6.1 \
		-lvtkImagingGeneral-6.1 \
		-lvtkInteractionStyle-6.1 \
		-lvtkInteractionWidgets-6.1 \
		-lvtkIOCore-6.1 \
		-lvtkRenderingAnnotation-6.1 \
		-lvtkRenderingCore-6.1 \
		-lvtkRenderingFreeType-6.1 \
		-lvtkRenderingLabel-6.1 \
		-lvtkRenderingVolume-6.1 \
		-lvtksys-6.1 \
		-lvtkzlib-6.1
}

SOURCES += geometry.cpp
