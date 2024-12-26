#include "chooseservice.h"
#include "ui_chooseservice.h"
#include "service_dyh.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "groupmanager_dyh.h"
#include "writeAndread.h"

extern QQService_dyh QQ;
extern user_dyh* CurUser;
extern WeChatService_dyh VX;
extern vxUser_dyh* CurVser;
inline const std::string QQUserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";
inline const std::string VXUserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";
inline const std::string QQGroupfile = "D:\\CS\\QtProject\\cpp_dyh\\QQgrouplist.json";
inline const std::string VXGroupfile = "D:\\CS\\QtProject\\cpp_dyh\\VXgrouplist.json";
extern FriendManager_dyh& userls;
extern VXFriendManager_dyh& vserls;
extern QQgroupmanager_dyh QQgroupls;
extern QQgroupmanager_dyh VXgroupls;

chooseService::chooseService(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chooseService) {
    ui->setupUi(this);
}

chooseService::~chooseService() {
    delete ui;
}

void chooseService::on_QQBtm_clicked() {
    if (CurUser != nullptr) {
        this->hide();
        qqmain->show();
        return;
    }
    this->hide();
    qqpage->show();
    QQ.ActService();
}

void chooseService::linkApp(QApplication* p) {
    this->app = p;
}

void chooseService::linkToQQPage(QWidget* p) {
    this->qqpage = p;
}

void chooseService::linkQQmain(QWidget* p) {
    qqmain = p;
}

void chooseService::linkToVXPage(QWidget* p) {
    this->vxpage = p;
}

void chooseService::linkVXmain(QWidget* p) {
    vxmain = p;
}

void chooseService::on_VXBtm_clicked() {
    if (CurVser != nullptr) {
        this->hide();
        vxmain->show();
        return;
    }
    this->hide();
    vxpage->show();
    VX.ActService();
}


void chooseService::on_exitBtm_clicked() {
    writeVsersToFile(VXUserfile, vserls.showUserls());
    writeUsersToFile(QQUserfile, userls.showUserls());
    writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    app->exit(0);
}

