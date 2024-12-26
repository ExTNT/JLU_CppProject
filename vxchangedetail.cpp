#include "vxchangedetail.h"
#include "ui_vxchangedetail.h"
#include "user_dyh.h"
#include "vxdetail.h"
#include "writeAndread.h"
#include "qqsignup_err_name.h"
#include "friendmanager_dyh.h"

extern VXFriendManager_dyh& vserls;
extern vxUser_dyh* CurVser;
inline const std::string VXUserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";

VXchangedetail::VXchangedetail(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXchangedetail) {
    ui->setupUi(this);
    noname = new QQSignUp_err_name(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
}

VXchangedetail::~VXchangedetail() {
    delete ui;
}

void VXchangedetail::initLdt() {
    ui->idLab->setText(QString::fromStdString(CurVser->getId()));
    ui->regLab->setText(QString::fromStdString(CurVser->getReg()));
    ui->nameLdt->setText(QString::fromStdString(CurVser->getNickname()));
    ui->dateEdit->setDate(QDate::fromString(QString::fromStdString(CurVser->getBirth()), "yyyy-MM-dd"));
    ui->LocaLdt->setText(QString::fromStdString(CurVser->getLocal()));
    if (CurVser->giveQQ().empty()) {
        ui->qqLdt->clear();
    } else {
        ui->qqLdt->setText(QString::fromStdString(CurVser->giveQQ()));
    }
}

void VXchangedetail::LinkQQdetail(QWidget *p) {
    vxdetail = p;
}

void VXchangedetail::on_confrimBtm_clicked() {
    if (ui->nameLdt->text().isEmpty()) {
        initLdt();
        noname->show();
        return;
    }
    CurVser->setNickName(ui->nameLdt->text().toStdString());
    CurVser->setBirthday(ui->dateEdit->date().toString("yyyy-MM-dd").toStdString());
    CurVser->setLocation(ui->LocaLdt->text().toStdString());
    std::string& qq = CurVser->giveQQ();
    qq.clear();
    qq = ui->qqLdt->text().toStdString();
    this->hide();
    auto p = (VXDetail*)vxdetail;
    p->initLab();
    p->show();
    writeVsersToFile(VXUserfile, vserls.showUserls());
}

void VXchangedetail::on_exitBtm_clicked() {
    this->hide();
    vxdetail->show();
}
