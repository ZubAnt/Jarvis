#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T16:43:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    smartdevice.cpp \
    smartbulb.cpp \
    settingsdialogwindow.cpp \
    styles.cpp \
    smartbulbconfig.cpp \
    grouptab.cpp \
    settingsbuttonbox.cpp \
    widgetgridlayout.cpp \
    dynamicbulbbutton.cpp

HEADERS  += mainwindow.h \
    smartdevice.h \
    smartbulb.h \
    settingsdialogwindow.h \
    styles.h \
    smartbulbconfig.h \
    grouptab.h \
    settingsbuttonbox.h \
    widgetgridlayout.h \
    dynamicbulbbutton.h

FORMS    += mainwindow.ui \
    settingsdialogwindow.ui \
    smartbulbconfig.ui

RESOURCES += \
    res.qrc
