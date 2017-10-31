QT += core
QT -= gui

CONFIG += c++11

TARGET = ProjServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    bcm2835_stub.cpp \
    pin.cpp \
    pwm.cpp

HEADERS += \
    bcm2835.h \
    pin.h \
    pwm.h
