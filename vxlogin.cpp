#include "vxlogin.h"
#include "ui_vxlogin.h"
#include "service_name.h"
#include "qqlogin_err.h"
#include "vxmain.h"
#include <string>

extern WeChatService_name VX;

VXLogin::VXLogin(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXLogin)
{
    ui->setupUi(this);
    err = new QQLogin_err(this);
}

VXLogin::~VXLogin()
{
    delete ui;
}

void VXLogin::LinkVuce(QWidget *p)
{
    vuce = p;
}

void VXLogin::LinkChoose(QWidget *p)
{
    choose = p;
}

void VXLogin::LinkMain(QWidget *p)
{
    mainWindow = p;
}

void VXLogin::on_vuce_pbt_clicked()
{
    this->hide();
    vuce->show();
}

void VXLogin::on_dglu_pbt_clicked()
{
    std::string id = ui->vhhk_ldt->text().toStdString();
    std::string pw = ui->mima_ldt->text().toStdString();
    bool flag = VX.login(id, pw);
    if (flag)
    {
        ui->mima_ldt->clear();
        ui->vhhk_ldt->clear();
        this->hide();
        auto p = (VXmain *)mainWindow;
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

void VXLogin::on_exitBtm_clicked()
{
    ui->mima_ldt->clear();
    ui->vhhk_ldt->clear();
    VX.logout();
    this->hide();
    choose->show();
}
