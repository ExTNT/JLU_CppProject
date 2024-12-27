#include "QQLogin.h"
#include "ui_QQLogin.h"
#include "service_name.h"
#include "qqlogin_err.h"
#include <string>
#include "qqmain.h"

extern QQService_name QQ;

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    err = new QQLogin_err(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::LinkVuce(QWidget *p)
{
    vuce = p;
}

void Widget::LinkChoose(QWidget *p)
{
    choose = p;
}

void Widget::LinkMain(QWidget *p)
{
    mainWindow = p;
}

void Widget::on_vuce_pbt_clicked()
{
    this->hide();
    vuce->show();
}

void Widget::on_dglu_pbt_clicked()
{
    std::string id = ui->vhhk_ldt->text().toStdString();
    std::string pw = ui->mima_ldt->text().toStdString();
    bool flag = QQ.login(id, pw);
    if (flag)
    {
        ui->mima_ldt->clear();
        ui->vhhk_ldt->clear();
        this->hide();
        auto p = (QQmain *)mainWindow;
        p->setLab();
        p->show();
    }
    else
    {
        ui->mima_ldt->clear();
        ui->vhhk_ldt->clear();
        err->show();
    }
}

void Widget::on_exitBtm_clicked()
{
    ui->mima_ldt->clear();
    ui->vhhk_ldt->clear();
    QQ.logout();
    this->hide();
    choose->show();
}
