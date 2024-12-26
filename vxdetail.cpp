#include "vxdetail.h"
#include "ui_vxdetail.h"
#include "user_dyh.h"
#include "vxchangedetail.h"
#include "vxresetpswd.h"
extern vxUser_dyh* CurVser;

VXDetail::VXDetail(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXDetail) {
    ui->setupUi(this);
}

VXDetail::~VXDetail() {
    delete ui;
}

void VXDetail::initLab() {
    ui->idLab->setText(QString::fromStdString(CurVser->getId()));
    ui->nameLab->setText(QString::fromStdString(CurVser->getNickname()));
    ui->birthLab->setText(QString::fromStdString(CurVser->getBirth()));
    ui->regLab->setText(QString::fromStdString(CurVser->getReg()));
    ui->locaLab->setText(QString::fromStdString(CurVser->getLocal()));
    if (CurVser->giveQQ().empty()) {
        ui->qqLab->setText("无关联QQ");
    } else {
        ui->qqLab->setText(QString::fromStdString(CurVser->giveQQ()));
    }
}

void VXDetail::LinkMainWindow(QWidget *p) {
    mainWindow = p;
}

void VXDetail::on_pushButton_3_clicked() {
    this->hide();
    mainWindow->show();
}

void VXDetail::LinkchangeDetai(QWidget *p) {
    changeDetail = p;
}

void VXDetail::on_pushButton_clicked() {
    this->hide();
    auto p = (VXchangedetail*)changeDetail;
    p->initLdt();
    p->show();
}

void VXDetail::LinkResetpd(QWidget *p) {
    resetpd = p;
}

void VXDetail::on_pushButton_2_clicked() {
    this->hide();
    auto p = (VXResetPswd*)resetpd;
    p->initLab();
    p->show();
}
