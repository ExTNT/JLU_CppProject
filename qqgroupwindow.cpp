#include "qqgroupwindow.h"
#include "ui_qqgroupwindow.h"
#include "user_name.h"
#include "friendmanager_name.h"
#include "writeAndread.h"
#include "groupmanager_name.h"
#include "groupitem.h"
#include "group_name.h"
#include "nonegroup_err.h"
#include <string>

extern user_name *CurUser;
extern FriendManager_name &userls;
extern QQgroupmanager_name QQgroupls;
inline const std::string QQUserfile = "../../QQuserlist.json";
inline const std::string QQGroupfile = "../../QQgrouplist.json";

QQgroupwindow::QQgroupwindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::QQgroupwindow)
{
    ui->setupUi(this);
    err = new nonegroup_err;
}

QQgroupwindow::~QQgroupwindow()
{
    delete ui;
}

void QQgroupwindow::initLab()
{
    ui->nameLab->setText(QString::fromStdString(CurUser->getNickname()));
    ui->idLab->setText(QString::fromStdString(CurUser->getId()));
}

void QQgroupwindow::initList()
{
    ui->listWidget->clear();
    for (auto &i : CurUser->giveGrps())
    {
        groupItem *gItem = new groupItem(this);
        QQGroup_name *temp = QQgroupls.find(i);
        gItem->setIdOn(temp->getId(), temp->getOwner());
        QListWidgetItem *mItem = new QListWidgetItem(ui->listWidget);
        mItem->setSizeHint(QSize(340, 100));
        ui->listWidget->setItemWidget(mItem, gItem);
    }
}

void QQgroupwindow::on_exitBtm_clicked()
{
    this->hide();
    main->show();
}

void QQgroupwindow::on_addBtm_clicked()
{
    if (QQgroupls.find(ui->idLdt->text().toStdString()) == nullptr)
    {
        err->show();
        return;
    }
    CurUser->joinGroup(ui->idLdt->text().toStdString());
    this->initList();
    writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
    writeUsersToFile(QQUserfile, userls.showUserls());
    return;
}

void QQgroupwindow::on_pushButton_clicked()
{
    CurUser->creatGroup();
    this->initList();
    writeGroupsToFile(QQGroupfile, QQgroupls.giveGroups());
    writeUsersToFile(QQUserfile, userls.showUserls());
}
