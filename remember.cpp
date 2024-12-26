#include "remember.h"
#include "ui_remember.h"

remember::remember(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::remember) {
    ui->setupUi(this);
}

remember::~remember() {
    delete ui;
}

void remember::initLab() {
    ui->label->setText("您的账号是: " + QString::fromStdString(u->getId()));
}
