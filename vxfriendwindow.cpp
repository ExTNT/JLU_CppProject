#include "vxfriendwindow.h"
#include "ui_vxfriendwindow.h"
#include "vxfrienditem.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "nonefriend_err.h"
#include "writeAndread.h"
#include <string>

extern vxUser_dyh* CurVser;
extern VXFriendManager_dyh& vserls;
inline const std::string VXUserfile = "../../VXuserlist.json";

VXFriendWindow::VXFriendWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXFriendWindow) {
    ui->setupUi(this);
    err = new nonefriend_err;
}

VXFriendWindow::~VXFriendWindow() {
    delete ui;
}

void VXFriendWindow::initList() {
    ui->listWidget->clear();
    for (auto &i : CurVser->giveFrds()) {
        vxfriendItem *fItem = new vxfriendItem(this);
        vxUser_dyh *temp = vserls.findFriend(i);
        fItem->setIdNm(temp->getId(), temp->getNickname());
        QListWidgetItem *mItem = new QListWidgetItem(ui->listWidget);
        mItem->setSizeHint(QSize(340, 100));
        ui->listWidget->setItemWidget(mItem, fItem);
    }
}

void VXFriendWindow::initLab() {
    ui->nameLab->setText(QString::fromStdString(CurVser->getNickname()));
    ui->idLab->setText(QString::fromStdString(CurVser->getId()));
}

void VXFriendWindow::LinkMain(QWidget *p) {
    this->vxmain = p;
}

void VXFriendWindow::on_exitBtm_clicked() {
    this->hide();
    vxmain->show();
}

void VXFriendWindow::on_addBtm_clicked() {
    if (vserls.findFriend(ui->idLdt->text().toStdString()) == nullptr) {
        err->show();
        return;
    }
    CurVser->addFriend(ui->idLdt->text().toStdString());
    this->initList();
    writeVsersToFile(VXUserfile, vserls.showUserls());
    return;
}
