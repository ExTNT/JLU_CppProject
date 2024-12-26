#include "vxfrienditem.h"
#include "ui_vxfrienditem.h"
#include "vxfrienditem_detial.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "vxfriendwindow.h"
#include "writeAndread.h"

extern vxUser_dyh* CurVser;
extern VXFriendManager_dyh& vserls;
inline const std::string VXUserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";


vxfriendItem::vxfriendItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vxfriendItem) {
    ui->setupUi(this);
    MyP = parent;
}

vxfriendItem::~vxfriendItem() {
    delete ui;
}

void vxfriendItem::setIdNm(std::string id, std::string nm) {
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(nm));
}

void vxfriendItem::on_detailBtm_clicked() {
    vxfriendItem_detial* fd = new vxfriendItem_detial();
    vxUser_dyh*temp = vserls.findFriend(ui->idLab->text().toStdString());
    fd->initLab(temp);
    fd->show();
}


void vxfriendItem::on_delelteBtm_clicked() {
    CurVser->delFriend(ui->idLab->text().toStdString());
    writeVsersToFile(VXUserfile, vserls.showUserls());
    auto p = (VXFriendWindow*)MyP;
    p->initList();
}


