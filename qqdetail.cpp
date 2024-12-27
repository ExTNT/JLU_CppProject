#include "qqdetail.h"
#include "ui_qqdetail.h"
#include "user_name.h"
#include "qqchangedetail.h"
#include "qqresetpswd.h"
extern user_name *CurUser;

QQDetail::QQDetail(QWidget *parent)
    : QWidget(parent), ui(new Ui::QQDetail)
{
    ui->setupUi(this);
}

QQDetail::~QQDetail()
{
    delete ui;
}

void QQDetail::initLab()
{
    ui->idLab->setText(QString::fromStdString(CurUser->getId()));
    ui->nameLab->setText(QString::fromStdString(CurUser->getNickname()));
    ui->birthLab->setText(QString::fromStdString(CurUser->getBirth()));
    ui->regLab->setText(QString::fromStdString(CurUser->getReg()));
    ui->locaLab->setText(QString::fromStdString(CurUser->getLocal()));
}

void QQDetail::LinkMainWindow(QWidget *p)
{
    mainWindow = p;
}

void QQDetail::on_pushButton_3_clicked()
{
    this->hide();
    mainWindow->show();
}

void QQDetail::LinkchangeDetai(QWidget *p)
{
    changeDetail = p;
}

void QQDetail::on_pushButton_clicked()
{
    this->hide();
    auto p = (QQchangedetail *)changeDetail;
    p->initLdt();
    p->show();
}

void QQDetail::LinkResetpd(QWidget *p)
{
    resetpd = p;
}

void QQDetail::on_pushButton_2_clicked()
{
    this->hide();
    auto p = (QQResetPswd *)resetpd;
    p->initLab();
    p->show();
}
