#include "chooseservice.h"
#include "ui_chooseservice.h"

chooseService::chooseService(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chooseService)
{
    ui->setupUi(this);
}

chooseService::~chooseService()
{
    delete ui;
}
