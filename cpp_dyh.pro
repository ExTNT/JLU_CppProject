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
    frienditem.cpp \
    frienditem_detial.cpp \
    friendmanager_dyh.cpp \
    group_dyh.cpp \
    groupitem.cpp \
    groupmanager_dyh.cpp \
    groupmemberitem.cpp \
    main.cpp \
    nonefriend_err.cpp \
    nonegroup_err.cpp \
    ownerexit_err.cpp \
    qqchangedetail.cpp \
    qqdetail.cpp \
    qqfriendwindow.cpp \
    qqgroupdetial.cpp \
    qqgroupwindow.cpp \
    qqlogin_err.cpp \
    qqmain.cpp \
    qqresetpd_err.cpp \
    qqresetpswd.cpp \
    qqsignup_err_name.cpp \
    remember.cpp \
    service_dyh.cpp \
    user_dyh.cpp \
    vxchangedetail.cpp \
    vxdetail.cpp \
    vxfrienditem.cpp \
    vxfrienditem_detial.cpp \
    vxfriendwindow.cpp \
    vxgroupdetial.cpp \
    vxgroupitem.cpp \
    vxgroupmemberitem.cpp \
    vxgroupwindow.cpp \
    vxlogin.cpp \
    vxmain.cpp \
    vxresetpswd.cpp \
    vxsignup.cpp \
    writeAndRead.cpp

HEADERS += \
    QQLogin.h \
    QQSignUp.h \
    chooseservice.h \
    errPassword2.h \
    frienditem.h \
    frienditem_detial.h \
    friendmanager_dyh.h \
    global.h \
    group_dyh.h \
    groupitem.h \
    groupmanager_dyh.h \
    groupmemberitem.h \
    json.hpp \
    nonefriend_err.h \
    nonegroup_err.h \
    ownerexit_err.h \
    qqchangedetail.h \
    qqdetail.h \
    qqfriendwindow.h \
    qqgroupdetial.h \
    qqgroupwindow.h \
    qqlogin_err.h \
    qqmain.h \
    qqresetpd_err.h \
    qqresetpswd.h \
    qqsignup_err_name.h \
    remember.h \
    service_dyh.h \
    user_dyh.h \
    vxchangedetail.h \
    vxdetail.h \
    vxfrienditem.h \
    vxfrienditem_detial.h \
    vxfriendwindow.h \
    vxgroupdetial.h \
    vxgroupitem.h \
    vxgroupmemberitem.h \
    vxgroupwindow.h \
    vxlogin.h \
    vxmain.h \
    vxresetpswd.h \
    vxsignup.h \
    writeAndread.h

FORMS += \
    QQLogin.ui \
    QQSignUp.ui \
    chooseservice.ui \
    errPassword2.ui \
    frienditem.ui \
    frienditem_detial.ui \
    groupitem.ui \
    groupmemberitem.ui \
    nonefriend_err.ui \
    nonegroup_err.ui \
    ownerexit_err.ui \
    qqchangedetail.ui \
    qqdetail.ui \
    qqfriendwindow.ui \
    qqgroupdetial.ui \
    qqgroupwindow.ui \
    qqlogin_err.ui \
    qqmain.ui \
    qqresetpd_err.ui \
    qqresetpswd.ui \
    qqsignup_err_name.ui \
    remember.ui \
    vxchangedetail.ui \
    vxdetail.ui \
    vxfrienditem.ui \
    vxfrienditem_detial.ui \
    vxfriendwindow.ui \
    vxgroupdetial.ui \
    vxgroupitem.ui \
    vxgroupmemberitem.ui \
    vxgroupwindow.ui \
    vxlogin.ui \
    vxmain.ui \
    vxresetpswd.ui \
    vxsignup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ico.qrc
