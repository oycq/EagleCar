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
    timer.cpp



HEADERS  += mainwindow.h \
    timer.h

FORMS    += mainwindow.ui
