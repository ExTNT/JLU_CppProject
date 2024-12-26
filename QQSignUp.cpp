#include "QQSignUp.h"
#include "ui_QQSignUp.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "writeAndread.h"
#include "errPassword2.h"
#include "qqsignup_err_name.h"
#include "remember.h"
#include <string>
#include <QString>
#include <QDateTime>
extern FriendManager_dyh& userls;


inline const std::string QQUserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";

vuceWidget::vuceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vuceWidget) {
    ui->setupUi(this);
    err = new Dialog(this);
    err_name = new QQSignUp_err_name(this);
    r = new remember(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
}

vuceWidget::~vuceWidget() {
    delete ui;
}

void vuceWidget::LinkW(QWidget *p) {
    w = p;
}

void vuceWidget::on_qvxc_pbt_clicked() {
    this->hide();
    w->show();
}


void vuceWidget::on_vuce_pbt_clicked() {
    if (ui->name_ldt->text().isEmpty()) {
        ui->name_ldt->clear();
        ui->mima_ldt->clear();
        ui->qvrf_ldt->clear();
        ui->dateEdit->clear();
        ui->location_ldt->clear();
        err_name->show();
        return;
    }
    if ((ui->mima_ldt->text() != ui->qvrf_ldt->text()) || (ui->mima_ldt->text().isEmpty() || ui->qvrf_ldt->text().isEmpty())) {
        ui->name_ldt->clear();
        ui->mima_ldt->clear();
        ui->qvrf_ldt->clear();
        ui->dateEdit->clear();
        ui->location_ldt->clear();
        err->show();
        return;
    }
    user_dyh* temp;
    int id = userls.showIds().top() + 1;
    std::string sid = std::to_string(id);
    std::string nickname = ui->name_ldt->text().toStdString();
    std::string password = ui->mima_ldt->text().toStdString();
    std::string birthday = ui->dateEdit->date().toString("yyyy-MM-dd").toStdString();
    std::string location = ui->location_ldt->text().toStdString();
    QDateTime curTime = QDateTime::currentDateTime();
    std::string regTime = curTime.toString("yyyy-MM-dd").toStdString();
    temp = new user_dyh(sid, nickname, birthday, regTime, location, password);
    userls.addUser(*temp);
    writeUsersToFile(QQUserfile, userls.showUserls());
    userls.initUserList(readUsersFromFile(QQUserfile));
    userls.initIds(readIdsFromFile(QQUserfile));
    ui->name_ldt->clear();
    ui->mima_ldt->clear();
    ui->qvrf_ldt->clear();
    ui->dateEdit->clear();
    ui->location_ldt->clear();
    auto p = (remember*)r;
    p->LinkUser(temp);
    p->initLab();
    p->show();
    this->hide();
    w->show();
    return;
}

