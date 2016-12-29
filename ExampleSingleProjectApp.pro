#-------------------------------------------------
#
# Project created by QtCreator 2016-12-29T07:43:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExampleSingleProjectApp
TEMPLATE = app


SOURCES += main.cpp\
        EllipseCalculator.cpp \
    SettingsDialog.cpp \
    ValueCalculator.cpp

HEADERS  += EllipseCalculator.h \
    SettingsDialog.h \
    ValueCalculator.h

FORMS    += EllipseCalculator.ui \
    SettingsDialog.ui

RESOURCES += \
    resources.qrc
