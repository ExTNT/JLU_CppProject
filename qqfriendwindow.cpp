#include "qqfriendwindow.h"
#include "ui_qqfriendwindow.h"
#include "frienditem.h"
#include "user_name.h"
#include "friendmanager_name.h"
#include "nonefriend_err.h"
#include "writeAndread.h"
#include <string>

extern user_name *CurUser;
extern FriendManager_name &userls;
inline const std::string QQUserfile = "../../QQuserlist.json";

QQFriendWindow::QQFriendWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::QQFriendWindow)
{
    ui->setupUi(this);
    err = new nonefriend_err;
}

void QQFriendWindow::initList()
{
    ui->listWidget->clear();
    for (auto &i : CurUser->giveFrds())
    {
        friendItem *fItem = new friendItem(this);
        user_name *temp = userls.findFriend(i);
        fItem->setIdNm(temp->getId(), temp->getNickname());
        QListWidgetItem *mItem = new QListWidgetItem(ui->listWidget);
        mItem->setSizeHint(QSize(340, 100));
        ui->listWidget->setItemWidget(mItem, fItem);
    }
}

QQFriendWindow::~QQFriendWindow()
{
    delete ui;
}

void QQFriendWindow::initLab()
{
    ui->nameLab->setText(QString::fromStdString(CurUser->getNickname()));
    ui->idLab->setText(QString::fromStdString(CurUser->getId()));
}

void QQFriendWindow::LinkMain(QWidget *p)
{
    this->qqmain = p;
}

void QQFriendWindow::on_exitBtm_clicked()
{
    this->hide();
    qqmain->show();
}

void QQFriendWindow::on_addBtm_clicked()
{
    if (userls.findFriend(ui->idLdt->text().toStdString()) == nullptr)
    {
        err->show();
        return;
    }
    CurUser->addFriend(ui->idLdt->text().toStdString());
    this->initList();
    writeUsersToFile(QQUserfile, userls.showUserls());
    return;
}
