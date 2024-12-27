#include "qqchangedetail.h"
#include "ui_qqchangedetail.h"
#include "user_dyh.h"
#include "qqdetail.h"
#include "writeAndread.h"
#include "qqsignup_err_name.h"
#include"friendmanager_dyh.h"

extern FriendManager_dyh& userls;
extern user_dyh* CurUser;
inline const std::string QQUserfile = "../../QQuserlist.json";


QQchangedetail::QQchangedetail(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQchangedetail) {
    ui->setupUi(this);
    noname = new QQSignUp_err_name(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
}

QQchangedetail::~QQchangedetail() {
    delete ui;
}

void QQchangedetail::initLdt() {
    ui->idLab->setText(QString::fromStdString(CurUser->getId()));
    ui->regLab->setText(QString::fromStdString(CurUser->getReg()));
    ui->nameLdt->setText(QString::fromStdString(CurUser->getNickname()));
    ui->dateEdit->setDate(QDate::fromString(QString::fromStdString(CurUser->getBirth()), "yyyy-MM-dd"));
    ui->LocaLdt->setText(QString::fromStdString(CurUser->getLocal()));
}

void QQchangedetail::LinkQQdetail(QWidget* p) {
    qqdetail = p;
}

void QQchangedetail::on_confrimBtm_clicked() {
    if (ui->nameLdt->text().isEmpty()) {
        initLdt();
        noname->show();
        return;
    }
    CurUser->setNickName(ui->nameLdt->text().toStdString());
    CurUser->setBirthday(ui->dateEdit->date().toString("yyyy-MM-dd").toStdString());
    CurUser->setLocation(ui->LocaLdt->text().toStdString());
    this->hide();
    auto p = (QQDetail* )qqdetail;
    p->initLab();
    p->show();
    writeUsersToFile(QQUserfile, userls.showUserls());
}


void QQchangedetail::on_exitBtm_clicked() {
    this->hide();
    qqdetail->show();
}

