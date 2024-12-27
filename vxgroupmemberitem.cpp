#include "vxgroupmemberitem.h"
#include "ui_vxgroupmemberitem.h"
#include "vxgroupdetial.h"
#include "user_name.h"
#include "friendmanager_name.h"
#include "group_name.h"
#include "groupmanager_name.h"
#include "writeAndread.h"

extern vxUser_name *CurVser;
extern VXFriendManager_name &vserls;
extern QQgroupmanager_name VXgroupls;
inline const std::string VXUserfile = "../../VXuserlist.json";
inline const std::string VXGroupfile = "../../VXgrouplist.json";

VXGroupMemberItem::VXGroupMemberItem(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXGroupMemberItem)
{
    ui->setupUi(this);
    MyP = parent;
    ui->pushButton->hide();
    ui->pushButton->setEnabled(false);
}

VXGroupMemberItem::~VXGroupMemberItem()
{
    delete ui;
}

void VXGroupMemberItem::setIdMy(const std::string id, const std::string nm)
{
    ui->idLab->setText(QString::fromStdString(id));
    ui->nameLab->setText(QString::fromStdString(nm));
}

void VXGroupMemberItem::initBtm(const std::string str)
{
    if (str == "群主")
    {
        if (Curg->isOwner(ui->idLab->text().toStdString()))
        {
            ui->pushButton_2->hide();
            ui->pushButton_2->setEnabled(false);
            return;
        }
        ui->pushButton_2->show();
        ui->pushButton_2->setEnabled(true);
        return;
    }
    ui->pushButton_2->hide();
    ui->pushButton_2->setEnabled(false);
    return;
}

void VXGroupMemberItem::on_pushButton_2_clicked()
{
    Curg->delmember(ui->idLab->text().toStdString());
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    writeVsersToFile(VXUserfile, vserls.showUserls());
    auto p = (VXGroupDetial *)MyP;
    p->initList();
    return;
}
