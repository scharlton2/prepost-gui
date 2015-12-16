######################################################################
# Automatically generated by qmake (2.01a) ? 10 24 09:50:18 2014
######################################################################

TARGET = iricMisc
TEMPLATE = lib

DEFINES += MISC_LIBRARY

QT += widgets xml

include( ../../paths.pri )

# Input
HEADERS += arrowsettingcontainer.h \
           boolcontainer.h \
           colorcontainer.h \
           compositecontainer.h \
           doublecontainer.h \
           doublemappingsetting.h \
           edge.h \
           enumcontainert.h \
           errormessage.h \
           filesystemfunction.h \
           informationdialog.h \
           intcontainer.h \
           integerrangecontainer.h \
           interpolator.h \
           iricundostack.h \
           lastiodirectory.h \
           latitudelongitude.h \
           latitudelongitudeangle.h \
           linearinterpolator.h \
           mathsupport.h \
           misc_global.h \
           numericvaluecontainert.h \
           opacitycontainer.h \
           qpointfcontainer.h \
           qttool.h \
           simplevaluecontainert.h \
           slowmotionspeededitdialog.h \
           stringcontainer.h \
           stringtool.h \
           threadwithprogressinfo.h \
           timeformat.h \
           versionnumber.h \
           windowgeometrycontainer.h \
           xmlattributecontainer.h \
           xmlsupport.h \
           zdepthrange.h \
           ziparchive.h \
           private/colorcontainer_impl.h \
           private/compositecontainer_impl.h \
           private/latitudelongitude_impl.h \
           private/latitudelongitudeangle_impl.h \
           private/numericvaluecontainert_detail.h \
           private/simplevaluecontainert_detail.h \
           private/versionnumber_impl.h \
           private/xmlattributecontainer_impl.h \
           private/zdepthrange_impl.h
FORMS += informationdialog.ui slowmotionspeededitdialog.ui
SOURCES += arrowsettingcontainer.cpp \
           boolcontainer.cpp \
           colorcontainer.cpp \
           compositecontainer.cpp \
           doublecontainer.cpp \
           errormessage.cpp \
           filesystemfunction.cpp \
           informationdialog.cpp \
           intcontainer.cpp \
           integerrangecontainer.cpp \
           iricundostack.cpp \
           lastiodirectory.cpp \
           latitudelongitude.cpp \
           latitudelongitudeangle.cpp \
           linearinterpolator.cpp \
           mathsupport.cpp \
           opacitycontainer.cpp \
           qpointfcontainer.cpp \
           qttool.cpp \
           slowmotionspeededitdialog.cpp \
           stringcontainer.cpp \
           stringtool.cpp \
           threadwithprogressinfo.cpp \
           timeformat.cpp \
           versionnumber.cpp \
           windowgeometrycontainer.cpp \
           xmlattributecontainer.cpp \
           xmlsupport.cpp \
           zdepthrange.cpp \
           ziparchive.cpp
TRANSLATIONS += languages/iricMisc_es_ES.ts \
                languages/iricMisc_fr_FR.ts \
                languages/iricMisc_id_ID.ts \
                languages/iricMisc_ja_JP.ts \
                languages/iricMisc_ko_KR.ts \
                languages/iricMisc_ru_RU.ts \
                languages/iricMisc_th_TH.ts \
                languages/iricMisc_vi_VN.ts \
                languages/iricMisc_zh_CN.ts
