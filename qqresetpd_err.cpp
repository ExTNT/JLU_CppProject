#include "qqresetpd_err.h"
#include "ui_qqresetpd_err.h"

qqresetpd_err::qqresetpd_err(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::qqresetpd_err) {
    ui->setupUi(this);
}

qqresetpd_err::~qqresetpd_err() {
    delete ui;
}
