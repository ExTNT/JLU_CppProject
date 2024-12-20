#include "qqsignup_err_name.h"
#include "ui_qqsignup_err_name.h"

QQSignUp_err_name::QQSignUp_err_name(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QQSignUp_err_name)
{
    ui->setupUi(this);
}

QQSignUp_err_name::~QQSignUp_err_name()
{
    delete ui;
}
