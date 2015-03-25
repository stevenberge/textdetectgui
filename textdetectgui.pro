#-------------------------------------------------
#
# Project created by QtCreator 2015-03-17T15:29:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = textdetectgui
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    fast_clustering.cpp \
    group_classifier.cpp \
    max_meaningful_clustering.cpp \
    min_bounding_box.cpp \
    mser.cpp \
    main.cpp \
    region.cpp \
    region_classifier.cpp \
    nfa.cpp \
    extend.cpp \
    mainthread.cpp

HEADERS  += mainwindow.h \
    group_classifier.h \
    max_meaningful_clustering.h \
    min_bounding_box.h \
    mser.h \
    region.h \
    region_classifier.h \
    groups.h \
    extend.h \
    mainthread.h

FORMS    += mainwindow.ui

#####################for opencv

INCLUDEPATH += /usr/include/opencv/

LIBS +=  /usr/lib/i386-linux-gnu/libopencv_calib3d.so /usr/lib/i386-linux-gnu/libopencv_contrib.so /usr/lib/i386-linux-gnu/libopencv_core.so /usr/lib/i386-linux-gnu/libopencv_features2d.so /usr/lib/i386-linux-gnu/libopencv_flann.so /usr/lib/i386-linux-gnu/libopencv_gpu.so /usr/lib/i386-linux-gnu/libopencv_highgui.so /usr/lib/i386-linux-gnu/libopencv_imgproc.so /usr/lib/i386-linux-gnu/libopencv_legacy.so /usr/lib/i386-linux-gnu/libopencv_ml.so /usr/lib/i386-linux-gnu/libopencv_objdetect.so /usr/lib/i386-linux-gnu/libopencv_ocl.so /usr/lib/i386-linux-gnu/libopencv_photo.so /usr/lib/i386-linux-gnu/libopencv_stitching.so /usr/lib/i386-linux-gnu/libopencv_superres.so /usr/lib/i386-linux-gnu/libopencv_ts.so /usr/lib/i386-linux-gnu/libopencv_video.so /usr/lib/i386-linux-gnu/libopencv_videostab.so -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_objdetect -lopencv_ocl -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
  #-L/usr/lib/i386-linux-gnu/ -lcv -lcvaux -lcxcore -lhighgui -lml

OTHER_FILES += \
    boost_train/trained_boost_char.xml \
    boost_train/trained_boost_groups.xml
