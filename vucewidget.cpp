#include "vucewidget.h"
#include "ui_vucewidget.h"

vuceWidget::vuceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vuceWidget)
{
    ui->setupUi(this);
}

vuceWidget::~vuceWidget()
{
    delete ui;
}

void vuceWidget::LinkW(QWidget *p)
{
    w=p;
}

void vuceWidget::on_qvxc_pbt_clicked()
{
    this->hide();
    w->show();
}

