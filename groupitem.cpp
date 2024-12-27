#include "groupitem.h"
#include "ui_groupitem.h"
#include <string>
#include "user_name.h"
#include "group_name.h"
#include "groupmanager_name.h"
#include "ownerexit_err.h"
#include "writeAndread.h"
#include "friendmanager_name.h"
#include "qqgroupwindow.h"
#include "qqgroupdetial.h"

extern user_name *CurUser;
extern FriendManager_name &userls;
extern QQgroupmanager_name QQgroupls;
inline const std::string QQUserfile = "../../QQuserlist.json";
inline const std::string QQGroupfile = "../../QQgrouplist.json";

groupItem::groupItem(QWidget *parent)
    : QWidget(parent), ui(new Ui::groupItem)
{
    ui->setupUi(this);
    err = new OwnerExit_err;
    MyP = parent;
}

groupItem::~groupItem()
{
    delete ui;
}

void groupItem::setIdOn(std::string id, std::string on)
{
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(on));
}

void groupItem::on_delelteBtm_clicked()
{
    group_name *temp = QQgroupls.find(ui->idLab->text().toStdString());
    if (temp->isOwner(CurUser->getId()))
    {
        err->show();
        return;
    }
    CurUser->leaveGroup(ui->idLab->text().toStdString());
    writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
    writeUsersToFile(QQUserfile, userls.showUserls());
    auto *p = (QQgroupwindow *)MyP;
    p->initList();
    return;
}

void groupItem::on_detailBtm_clicked()
{
    auto dp = new QQGroupDetial;
    dp->gp = QQgroupls.find(ui->idLab->text().toStdString());
    dp->initLab();
    dp->initList();
    dp->show();
}
