#include "chooseservice.h"
#include "ui_chooseservice.h"
#include "service_name.h"
#include "user_name.h"
#include "friendmanager_name.h"
#include "groupmanager_name.h"
#include "writeAndread.h"

extern QQService_name QQ;
extern user_name *CurUser;
extern WeChatService_name VX;
extern vxUser_name *CurVser;
inline const std::string QQUserfile = "../../QQuserlist.json";
inline const std::string VXUserfile = "../../VXuserlist.json";
inline const std::string QQGroupfile = "../../QQgrouplist.json";
inline const std::string VXGroupfile = "../../Xgrouplist.json";
extern FriendManager_name &userls;
extern VXFriendManager_name &vserls;
extern QQgroupmanager_name QQgroupls;
extern QQgroupmanager_name VXgroupls;

chooseService::chooseService(QWidget *parent)
    : QWidget(parent), ui(new Ui::chooseService)
{
    ui->setupUi(this);
}

chooseService::~chooseService()
{
    delete ui;
}

void chooseService::on_QQBtm_clicked()
{
    if (CurUser != nullptr)
    {
        this->hide();
        qqmain->show();
        return;
    }
    this->hide();
    qqpage->show();
    QQ.ActService();
}

void chooseService::linkApp(QApplication *p)
{
    this->app = p;
}

void chooseService::linkToQQPage(QWidget *p)
{
    this->qqpage = p;
}

void chooseService::linkQQmain(QWidget *p)
{
    qqmain = p;
}

void chooseService::linkToVXPage(QWidget *p)
{
    this->vxpage = p;
}

void chooseService::linkVXmain(QWidget *p)
{
    vxmain = p;
}

void chooseService::on_VXBtm_clicked()
{
    if (CurVser != nullptr)
    {
        this->hide();
        vxmain->show();
        return;
    }
    this->hide();
    vxpage->show();
    VX.ActService();
}

void chooseService::on_exitBtm_clicked()
{
    writeVsersToFile(VXUserfile, vserls.showUserls());
    writeUsersToFile(QQUserfile, userls.showUserls());
    writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    app->exit(0);
}
