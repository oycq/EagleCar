#-------------------------------------------------
#
# Project created by QtCreator 2017-02-15T21:40:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EagleCar
TEMPLATE = app

LIBS += -LC:/opencv/build/x64/vc14/lib
LIBS += -lopencv_world310


INCLUDEPATH += C:/opencv/build/include/opencv2
INCLUDEPATH += C:/opencv/build/include


SOURCES += main.cpp\
        mainwindow.cpp \
    runtimer.cpp \
    roi.cpp \
    lr.cpp \
    bias.cpp



HEADERS  += mainwindow.h \
    runtimer.h \
    roi.h \
    lr.h \
    bias.h

FORMS    += mainwindow.ui
