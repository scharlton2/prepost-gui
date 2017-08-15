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

unix {
        LIBS += \
        -lvtkCommonExecutionModel-6.1 \
        -lvtkCommonMath-6.1 \
        -lvtkCommonMisc-6.1 \
        -lvtkCommonSystem-6.1 \
        -lvtkCommonTransforms-6.1 \
        -lvtksys-6.1 \
        -lvtkzlib-6.1
}

SOURCES += main.cpp

QMAKE_CLEAN += \
        test1_input.vtk \
        test1_output.csv \
        test1_output.vtk \
        test2_input.vtk \
        test2_output.csv \
        test2_output.vtk \
        test3_input.vtk \
        test3_output.csv \
        test3_output.vtk
