#include "nonegroup_err.h"
#include "ui_nonegroup_err.h"

nonegroup_err::nonegroup_err(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::nonegroup_err)
{
    ui->setupUi(this);
}

nonegroup_err::~nonegroup_err()
{
    delete ui;
}
