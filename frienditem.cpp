#include "frienditem.h"
#include "ui_frienditem.h"
#include "frienditem_detial.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "qqfriendwindow.h"
#include "writeAndread.h"
extern user_dyh* CurUser;
extern FriendManager_dyh& userls;
inline const std::string QQUserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";

friendItem::friendItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::friendItem) {
    ui->setupUi(this);
    MyP = parent;
}

friendItem::~friendItem() {
    delete ui;
}

void friendItem::setIdNm(std::string id, std::string nm) {
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(nm));
}

void friendItem::on_detailBtm_clicked() {
    friendItem_detial* fd = new friendItem_detial();
    user_dyh*temp = userls.findFriend(ui->idLab->text().toStdString());
    fd->initLab(temp);
    fd->show();
}


void friendItem::on_delelteBtm_clicked() {
    CurUser->delFriend(ui->idLab->text().toStdString());
    writeUsersToFile(QQUserfile, userls.showUserls());
    auto p = (QQFriendWindow*)MyP;
    p->initList();
}

