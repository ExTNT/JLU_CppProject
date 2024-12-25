#include "nonefriend_err.h"
#include "ui_nonefriend_err.h"

nonefriend_err::nonefriend_err(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::nonefriend_err)
{
    ui->setupUi(this);
}

nonefriend_err::~nonefriend_err()
{
    delete ui;
}
