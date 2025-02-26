#include "vxfrienditem.h"
#include "ui_vxfrienditem.h"
#include "vxfrienditem_detial.h"
#include "user_name.h"
#include "friendmanager_name.h"
#include "vxfriendwindow.h"
#include "writeAndread.h"

extern vxUser_name *CurVser;
extern VXFriendManager_name &vserls;
inline const std::string VXUserfile = "../../VXuserlist.json";

vxfriendItem::vxfriendItem(QWidget *parent)
    : QWidget(parent), ui(new Ui::vxfriendItem)
{
    ui->setupUi(this);
    MyP = parent;
}

vxfriendItem::~vxfriendItem()
{
    delete ui;
}

void vxfriendItem::setIdNm(std::string id, std::string nm)
{
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(nm));
}

void vxfriendItem::on_detailBtm_clicked()
{
    vxfriendItem_detial *fd = new vxfriendItem_detial();
    vxUser_name *temp = vserls.findFriend(ui->idLab->text().toStdString());
    fd->initLab(temp);
    fd->show();
}

void vxfriendItem::on_delelteBtm_clicked()
{
    CurVser->delFriend(ui->idLab->text().toStdString());
    writeVsersToFile(VXUserfile, vserls.showUserls());
    auto p = (VXFriendWindow *)MyP;
    p->initList();
}
