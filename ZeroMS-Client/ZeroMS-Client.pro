#-------------------------------------------------
#
# Project created by QtCreator 2012-05-19T17:32:52
#
#-------------------------------------------------

QT       += core gui network sql

TARGET = ZeroMS-Client
TEMPLATE = app

INCLUDEPATH += .


SOURCES += main.cpp\
        LoginWidget.cpp \
    ../public/OSettings.cpp \
    ../public/OMessage.cpp \
    ../public/OAbstractPeer.cpp \
    ../public/OGlobal/OGlobal.cpp \
    ../public/ODataBase.cpp \
    OClientCore.cpp \
    OServerPeer.cpp \
    MainWidget.cpp \
    FriendListItem.cpp \
    FriendList.cpp \
    ChatWidget.cpp

HEADERS  += LoginWidget.h \
    ../public/OSettings.h \
    ../public/OMessage.h \
    ../public/OGlobal.h \
    ../public/OAbstractPeer.h \
    ../public/OGlobal/protocol2.0.h \
    global.h \
    ../public/ODataBase.h \
    OClientCore.h \
    OServerPeer.h \
    MainWidget.h \
    FriendListItem.h \
    FriendList.h \
    ChatWidget.h

FORMS    += LoginWidget.ui \
    MainWidget.ui \
    FriendListItem.ui \
    ChatWidget.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    config.ini \
    zeroms-client-2.x.desktop
