#-------------------------------------------------
#
# Project created by QtCreator 2012-02-01T21:32:33
#
#-------------------------------------------------

QT       += core gui network

TARGET = ONetworkDebuger
TEMPLATE = app


SOURCES += main.cpp\
    ../public/OGlobal/OGlobal.cpp \
    ONetworkDebuger.cpp \
    ../public/OMessage.cpp

HEADERS  += \
    ../public/OGlobal.h \
    ../public/OGlobal/protocol2.0.h \
    ONetworkDebuger.h \
    ../public/OMessage.h

FORMS    += ONetworkDebuger.ui

