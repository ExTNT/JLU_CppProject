#include "groupmemberitem.h"
#include "ui_groupmemberitem.h"
#include "qqgroupdetial.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "group_dyh.h"
#include "groupmanager_dyh.h"
#include "writeAndread.h"

extern user_dyh* CurUser;
extern FriendManager_dyh& userls;
extern QQgroupmanager_dyh QQgroupls;
inline const std::string QQUserfile = "../../QQuserlist.json";
inline const std::string QQGroupfile = "../../QQgrouplist.json";


GroupMemberItem::GroupMemberItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GroupMemberItem) {
    ui->setupUi(this);
    MyP = parent;
}

GroupMemberItem::~GroupMemberItem() {
    delete ui;
}

void GroupMemberItem::setIdMy(const std::string id, const std::string nm) {
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(nm));
}

void GroupMemberItem::initBtm(const std::string str) {
    if (str == "群主") {
        if (Curg->isOwner(ui->idLab->text().toStdString())) {
            ui->pushButton->hide();
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->hide();
            ui->pushButton_2->setEnabled(false);
            return;
        }
        if (Curg->isAdmin(ui->idLab->text().toStdString())) {
            ui->pushButton->setText("移除管理");
        } else {
            ui->pushButton->setText("设为管理");
        }
        ui->pushButton->show();
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->show();
        ui->pushButton_2->setEnabled(true);
        return;
    } else if (str == "管理员") {
        ui->pushButton->hide();
        ui->pushButton->setEnabled(false);
        if (Curg->isAdmin(ui->idLab->text().toStdString()) || Curg->isOwner(ui->idLab->text().toStdString())) {
            ui->pushButton_2->hide();
            ui->pushButton_2->setEnabled(false);
        } else {
            ui->pushButton_2->show();
            ui->pushButton_2->setEnabled(true);
        }
        return;
    }
    ui->pushButton->hide();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->hide();
    ui->pushButton_2->setEnabled(false);
    return;
}

void GroupMemberItem::on_pushButton_clicked() {
    if (ui->pushButton->text() == "移除管理") {
        Curg->delAdmin(ui->idLab->text().toStdString());
        writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
        writeUsersToFile(QQUserfile, userls.showUserls());
        auto p = (QQGroupDetial*)MyP;
        p->initList();
        return;
    }
    if (ui->pushButton->text() == "设为管理") {
        Curg->addAdmin(ui->idLab->text().toStdString());
        writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
        writeUsersToFile(QQUserfile, userls.showUserls());
        auto p = (QQGroupDetial*)MyP;
        p->initList();
        return;
    }
}


void GroupMemberItem::on_pushButton_2_clicked() {
    if (ui->pushButton->text() == "移除管理") {
        Curg->delAdmin(ui->idLab->text().toStdString());
        Curg->delmember(ui->idLab->text().toStdString());
        writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
        writeUsersToFile(QQUserfile, userls.showUserls());
        auto p = (QQGroupDetial*)MyP;
        p->initList();
        return;
    }
    Curg->delmember(ui->idLab->text().toStdString());
    writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
    writeUsersToFile(QQUserfile, userls.showUserls());
    auto p = (QQGroupDetial*)MyP;
    p->initList();
    return;
}

