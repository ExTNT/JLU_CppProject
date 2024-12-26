#include "vxmain.h"
#include "ui_vxmain.h"
#include "user_dyh.h"
#include "vxdetail.h"
#include "vxfriendwindow.h"
#include <iostream>
#include <QString>
#include "vxgroupwindow.h"

extern vxUser_dyh* CurVser;

VXmain::VXmain(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXmain) {
    ui->setupUi(this);
}

VXmain::~VXmain() {
    delete ui;
}

void VXmain::setLab() {
    ui->nicknameLab->setText(QString::fromStdString(CurVser->getNickname()) += " 的 微信 ");
}

void VXmain::LinkChoose(QWidget *p) {
    choose = p;
}

void VXmain::LinkDetail(QWidget *p) {
    details = p;
}

void VXmain::on_detailBtm_clicked() {
    this->hide();
    auto p = (VXDetail*)details;
    p->initLab();
    p->show();
}

void VXmain::on_exitBtm_clicked() {
    this->hide();
    choose->show();
    CurVser = nullptr;
    std::cout << "exit wechat now" << std::endl;
}

void VXmain::on_changeBtm_clicked() {
    this->hide();
    choose->show();
    std::cout << "wechat not exit, wait for other service to run" << std::endl;
}

void VXmain::LinkFriend(QWidget *p) {
    Friends = p;
}

void VXmain::LinkGroups(QWidget *p) {
    Groups = p;
}

void VXmain::on_friendBtm_clicked() {
    this->hide();
    auto p = (VXFriendWindow*)Friends;
    p->initLab();
    p->initList();
    p->show();
}

void VXmain::on_groupBtm_clicked() {
    this->hide();
    auto p = (VXgroupwindow*)Groups;
    p->initLab();
    p->initList();
    p->show();
}
