#include "frienditem_detial.h"
#include "ui_frienditem_detial.h"
#include "user_dyh.h"

friendItem_detial::friendItem_detial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::friendItem_detial) {
    ui->setupUi(this);
    Myparent = parent;
}

friendItem_detial::~friendItem_detial() {
    delete ui;
}

void friendItem_detial::initLab(user_dyh* p) {
    ui->idLab_2->setText(QString::fromStdString(p->getId()));
    ui->nameLab_2->setText(QString::fromStdString(p->getNickname()));
    ui->birthLab_2->setText(QString::fromStdString(p->getBirth()));
    ui->locaLab_2->setText(QString::fromStdString(p->getLocal()));
    ui->regLab_2->setText(QString::fromStdString(p->getReg()));
}

void friendItem_detial::on_pushButton_clicked() {
    this->hide();
    this->close();
    delete this;
}

