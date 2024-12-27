#include "vxgroupwindow.h"
#include "ui_vxgroupwindow.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "writeAndread.h"
#include "groupmanager_dyh.h"
#include "vxgroupitem.h"
#include "group_dyh.h"
#include "nonegroup_err.h"
#include <string>

extern vxUser_dyh* CurVser;
extern VXFriendManager_dyh& vserls;
extern QQgroupmanager_dyh VXgroupls;
inline const std::string VXUserfile = "../../VXuserlist.json";
inline const std::string VXGroupfile = "../../VXgrouplist.json";

VXgroupwindow::VXgroupwindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXgroupwindow) {
    ui->setupUi(this);
    err = new nonegroup_err;
}

VXgroupwindow::~VXgroupwindow() {
    delete ui;
}

void VXgroupwindow::initLab() {
    ui->nameLab->setText(QString::fromStdString(CurVser->getNickname()));
    ui->idLab->setText(QString::fromStdString(CurVser->getId()));
}

void VXgroupwindow::initList() {
    ui->listWidget->clear();
    for (auto &i : CurVser->giveGrps()) {
        vxgroupItem *gItem = new vxgroupItem(this);
        QQGroup_dyh *temp = VXgroupls.find(i);
        gItem->setIdOn(temp->getId(), temp->getOwner());
        QListWidgetItem *mItem = new QListWidgetItem(ui->listWidget);
        mItem->setSizeHint(QSize(340, 100));
        ui->listWidget->setItemWidget(mItem, gItem);
    }
}

void VXgroupwindow::on_exitBtm_clicked() {
    this->hide();
    main->show();
}


void VXgroupwindow::on_pushButton_clicked() {
    CurVser->creatGroup();
    this->initList();
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    writeVsersToFile(VXUserfile, vserls.showUserls());
}
