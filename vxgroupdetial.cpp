#include "vxgroupdetial.h"
#include "ui_vxgroupdetial.h"
#include "user_name.h"
#include "vxgroupmemberitem.h"
#include "friendmanager_name.h"
#include "nonefriend_err.h"
#include "groupmanager_name.h"
#include "writeAndread.h"
extern vxUser_name *CurVser;
extern VXFriendManager_name &vserls;
extern QQgroupmanager_name VXgroupls;
inline const std::string VXUserfile = "../../VXuserlist.json";
inline const std::string VXGroupfile = "../../VXgrouplist.json";

VXGroupDetial::VXGroupDetial(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXGroupDetial)
{
    ui->setupUi(this);
    err = new nonefriend_err(this);
}

VXGroupDetial::~VXGroupDetial()
{
    delete ui;
}

void VXGroupDetial::initLab()
{
    ui->idLab->setText(QString::fromStdString(gp->getId()));
    if (gp->isOwner(CurVser->getId()))
    {
        ui->MyLab->setText("群主");
        return;
    }
    ui->MyLab->setText("群友");
    return;
}

void VXGroupDetial::initList()
{
    ui->listWidget->clear();
    for (auto &i : gp->givemembers())
    {
        VXGroupMemberItem *gmItem = new VXGroupMemberItem(this);
        gmItem->LinkGrp(gp);
        vxUser_name *temp = vserls.findFriend(i);
        gmItem->setIdMy(temp->getId(), temp->getNickname());
        gmItem->initBtm(ui->MyLab->text().toStdString());
        QListWidgetItem *mItem = new QListWidgetItem(ui->listWidget);
        mItem->setSizeHint(QSize(340, 120));
        ui->listWidget->setItemWidget(mItem, gmItem);
    }
}

void VXGroupDetial::on_pushButton_clicked()
{
    this->hide();
    this->close();
    delete this;
}

void VXGroupDetial::on_addBtm_clicked()
{
    vxUser_name *temp = vserls.findFriend(ui->idLdt->text().toStdString());
    if (temp == nullptr)
    {
        err->show();
        return;
    }
    gp->addmember(temp->getId());
    temp->joinGroup(gp->getId());
    initList();
    writeGroupsToFile(VXGroupfile, VXgroupls.giveGroups());
    writeVsersToFile(VXUserfile, vserls.showUserls());
}
