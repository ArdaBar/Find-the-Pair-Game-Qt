TEMPLATE = app
TARGET = Puzzle

QT = core gui
QT += testlib

CONFIG += testcase

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h
