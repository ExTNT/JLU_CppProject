#include "vxgroupitem.h"
#include "ui_vxgroupitem.h"
#include <string>
#include "user_name.h"
#include "group_name.h"
#include "groupmanager_name.h"
#include "ownerexit_err.h"
#include "writeAndread.h"
#include "friendmanager_name.h"
#include "vxgroupwindow.h"
#include "vxgroupdetial.h"

extern vxUser_name *CurVser;
extern VXFriendManager_name &vserls;
extern QQgroupmanager_name VXgroupls;
inline const std::string VXUserfile = "../../VXuserlist.json";
inline const std::string VXGroupfile = "../../VXgrouplist.json";

vxgroupItem::vxgroupItem(QWidget *parent)
    : QWidget(parent), ui(new Ui::vxgroupItem)
{
    ui->setupUi(this);
    err = new OwnerExit_err;
    MyP = parent;
}

vxgroupItem::~vxgroupItem()
{
    delete ui;
}

void vxgroupItem::setIdOn(std::string id, std::string on)
{
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(on));
}

void vxgroupItem::on_delelteBtm_clicked()
{
    group_name *temp = VXgroupls.find(ui->idLab->text().toStdString());
    if (temp->isOwner(CurVser->getId()))
    {
        err->show();
        return;
    }
    CurVser->leaveGroup(ui->idLab->text().toStdString());
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    writeVsersToFile(VXUserfile, vserls.showUserls());
    auto *p = (VXgroupwindow *)MyP;
    p->initList();
    return;
}

void vxgroupItem::on_detailBtm_clicked()
{
    auto dp = new VXGroupDetial;
    dp->gp = VXgroupls.find(ui->idLab->text().toStdString());
    dp->initLab();
    dp->initList();
    dp->show();
}
