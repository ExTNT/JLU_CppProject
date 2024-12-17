QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 mysql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    friendmanager_dyh.cpp \
    group_dyh.cpp \
    groupmanager_dyh.cpp \
    main.cpp \
    service_dyh.cpp \
    user_dyh.cpp \
    vucewidget.cpp \
    widget.cpp

HEADERS += \
    classHeader.h \
    friendmanager_dyh.h \
    global.h \
    group_dyh.h \
    groupmanager_dyh.h \
    service_dyh.h \
    user_dyh.h \
    vucewidget.h \
    widget.h

FORMS += \
    vucewidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc \
    style.qrc
