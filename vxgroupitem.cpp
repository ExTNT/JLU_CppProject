#include "vxgroupitem.h"
#include "ui_vxgroupitem.h"
#include <string>
#include "user_dyh.h"
#include "group_dyh.h"
#include "groupmanager_dyh.h"
#include "ownerexit_err.h"
#include "writeAndread.h"
#include "friendmanager_dyh.h"
#include "vxgroupwindow.h"
#include "vxgroupdetial.h"

extern vxUser_dyh* CurVser;
extern VXFriendManager_dyh& vserls;
extern QQgroupmanager_dyh VXgroupls;
inline const std::string VXUserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";
inline const std::string VXGroupfile = "D:\\CS\\QtProject\\cpp_dyh\\VXgrouplist.json";

vxgroupItem::vxgroupItem(QWidget *parent)
    : QWidget(parent), ui(new Ui::vxgroupItem) {
    ui->setupUi(this);
    err = new OwnerExit_err;
    MyP = parent;
}

vxgroupItem::~vxgroupItem() {
    delete ui;
}

void vxgroupItem::setIdOn(std::string id, std::string on) {
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(on));
}

void vxgroupItem::on_delelteBtm_clicked() {
    group_dyh *temp = VXgroupls.find(ui->idLab->text().toStdString());
    if (temp->isOwner(CurVser->getId())) {
        err->show();
        return;
    }
    CurVser->leaveGroup(ui->idLab->text().toStdString());
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    writeVsersToFile(VXUserfile, vserls.showUserls());
    auto *p = (VXgroupwindow*)MyP;
    p->initList();
    return;
}

void vxgroupItem::on_detailBtm_clicked() {
    auto dp = new VXGroupDetial;
    dp->gp = VXgroupls.find(ui->idLab->text().toStdString());
    dp->initLab();
    dp->initList();
    dp->show();
}
