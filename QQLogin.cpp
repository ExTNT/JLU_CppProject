#include "QQLogin.h"
#include "ui_QQLogin.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::LinkVuce(QWidget *p) {
    vuce = p;
}

void Widget::on_vuce_pbt_clicked() {
    this->hide();
    vuce->show();
}

