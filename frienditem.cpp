#include "frienditem.h"
#include "ui_frienditem.h"
#include "frienditem_detial.h"
#include "user_name.h"
#include "friendmanager_name.h"
#include "qqfriendwindow.h"
#include "writeAndread.h"
extern user_name *CurUser;
extern FriendManager_name &userls;
inline const std::string QQUserfile = "../../Quserlist.json";

friendItem::friendItem(QWidget *parent)
    : QWidget(parent), ui(new Ui::friendItem)
{
    ui->setupUi(this);
    MyP = parent;
}

friendItem::~friendItem()
{
    delete ui;
}

void friendItem::setIdNm(std::string id, std::string nm)
{
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(nm));
}

void friendItem::on_detailBtm_clicked()
{
    friendItem_detial *fd = new friendItem_detial();
    user_name *temp = userls.findFriend(ui->idLab->text().toStdString());
    fd->initLab(temp);
    fd->show();
}

void friendItem::on_delelteBtm_clicked()
{
    CurUser->delFriend(ui->idLab->text().toStdString());
    writeUsersToFile(QQUserfile, userls.showUserls());
    auto p = (QQFriendWindow *)MyP;
    p->initList();
}
