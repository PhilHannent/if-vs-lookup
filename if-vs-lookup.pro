QT += core

TARGET = if-vs-lookup
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp

DISTFILES += \
    README.md \
    LICENSE

