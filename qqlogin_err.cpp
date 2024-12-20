#include "qqlogin_err.h"
#include "ui_qqlogin_err.h"

QQLogin_err::QQLogin_err(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QQLogin_err)
{
    ui->setupUi(this);
}

QQLogin_err::~QQLogin_err()
{
    delete ui;
}
