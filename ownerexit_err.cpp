#include "ownerexit_err.h"
#include "ui_ownerexit_err.h"

OwnerExit_err::OwnerExit_err(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OwnerExit_err)
{
    ui->setupUi(this);
}

OwnerExit_err::~OwnerExit_err()
{
    delete ui;
}
