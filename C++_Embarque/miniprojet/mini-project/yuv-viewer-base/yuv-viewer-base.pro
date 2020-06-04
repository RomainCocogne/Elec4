QT += widgets
QT += gui
QT += core

CONFIG += strict_c++ c++17

TARGET = yuv-viewer
TEMPLATE = app

SOURCES += \
    main.cpp\
    mainwindow.cpp \
    yuvimage.cpp

HEADERS += \
    mainwindow.h \
    yuvimage.h \
    util.h


CONFIG(debug, debug|release) {
    DESTDIR = build/debug
} else {
    DESTDIR = build/release
}


OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui

