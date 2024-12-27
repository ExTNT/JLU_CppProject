#include "qqmain.h"
#include "ui_qqmain.h"
#include "user_name.h"
#include "qqdetail.h"
#include "qqfriendwindow.h"
#include <iostream>
#include <QString>
#include "qqgroupwindow.h"

extern user_name *CurUser;

QQmain::QQmain(QWidget *parent)
    : QWidget(parent), ui(new Ui::QQmain)
{
    ui->setupUi(this);
}
QQmain::~QQmain()
{
    delete ui;
}

void QQmain::setLab()
{
    ui->nicknameLab->setText(QString::fromStdString(CurUser->getNickname()) += " 的 QQ");
}

void QQmain::LinkChoose(QWidget *p)
{
    choose = p;
}

void QQmain::LinkDetail(QWidget *p)
{
    details = p;
}

void QQmain::on_detailBtm_clicked()
{
    this->hide();
    auto p = (QQDetail *)details;
    p->initLab();
    p->show();
}

void QQmain::on_exitBtm_clicked()
{
    this->hide();
    choose->show();
    CurUser = nullptr;
    std::cout << "exit qq now" << std::endl;
}

void QQmain::on_changeBtm_clicked()
{
    this->hide();
    choose->show();
    std::cout << "qq not exit, wait for other service to run" << std::endl;
}

void QQmain::LinkFriend(QWidget *p)
{
    Friends = p;
}

void QQmain::LinkGroups(QWidget *p)
{
    Groups = p;
}

void QQmain::on_friendBtm_clicked()
{
    this->hide();
    auto p = (QQFriendWindow *)Friends;
    p->initLab();
    p->initList();
    p->show();
}

void QQmain::on_groupBtm_clicked()
{
    this->hide();
    auto p = (QQgroupwindow *)Groups;
    p->initLab();
    p->initList();
    p->show();
}
