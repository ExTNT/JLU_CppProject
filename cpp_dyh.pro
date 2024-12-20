QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    QQLogin.cpp \
    QQSignUp.cpp \
    chooseservice.cpp \
    errPassword2.cpp \
    friendmanager_dyh.cpp \
    group_dyh.cpp \
    groupmanager_dyh.cpp \
    main.cpp \
    qqlogin_err.cpp \
    qqsignup_err_name.cpp \
    service_dyh.cpp \
    user_dyh.cpp \
    writeAndRead.cpp

HEADERS += \
    QQLogin.h \
    QQSignUp.h \
    chooseservice.h \
    classHeader.h \
    errPassword2.h \
    friendmanager_dyh.h \
    global.h \
    group_dyh.h \
    groupmanager_dyh.h \
    json.hpp \
    qqlogin_err.h \
    qqsignup_err_name.h \
    service_dyh.h \
    user_dyh.h \
    writeAndread.h

FORMS += \
    QQLogin.ui \
    QQSignUp.ui \
    chooseservice.ui \
    errPassword2.ui \
    qqlogin_err.ui \
    qqsignup_err_name.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc \
    style.qrc
