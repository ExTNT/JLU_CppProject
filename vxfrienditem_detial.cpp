#include "vxfrienditem_detial.h"
#include "ui_vxfrienditem_detial.h"
#include "user_dyh.h"

vxfriendItem_detial::vxfriendItem_detial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vxfriendItem_detial) {
    ui->setupUi(this);
    Myparent = parent;
}

vxfriendItem_detial::~vxfriendItem_detial() {
    delete ui;
}

void vxfriendItem_detial::initLab(vxUser_dyh* p) {
    ui->idLab->setText(QString::fromStdString(p->getId()));
    ui->nameLab->setText(QString::fromStdString(p->getNickname()));
    ui->birthLab->setText(QString::fromStdString(p->getBirth()));
    ui->locaLab->setText(QString::fromStdString(p->getLocal()));
    ui->regLab->setText(QString::fromStdString(p->getReg()));
    if (p->giveQQ().empty()) {
        ui->qqLab->setText("无关联QQ");
    } else {
        ui->qqLab->setText(QString::fromStdString(p->giveQQ()));
    }
}

void vxfriendItem_detial::on_pushButton_clicked() {
    this->hide();
    this->close();
    delete this;
}
