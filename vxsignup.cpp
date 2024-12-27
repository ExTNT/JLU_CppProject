#include "vxsignup.h"
#include "ui_vxsignup.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "writeAndread.h"
#include "errPassword2.h"
#include "remember.h"
#include "qqsignup_err_name.h"
#include <string>
#include <QString>
#include <QDateTime>

extern VXFriendManager_dyh& vserls;

inline const std::string VXUserfile = "../../VXuserlist.json";

VXSignUp::VXSignUp(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXSignUp) {
    ui->setupUi(this);
    err = new Dialog(this);
    err_name = new QQSignUp_err_name(this);
    r = new remember(this);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
}

VXSignUp::~VXSignUp() {
    delete ui;
}

void VXSignUp::LinkW(QWidget *p) {
    w = p;
}

void VXSignUp::on_qvxc_pbt_clicked() {
    this->hide();
    w->show();
}

void VXSignUp::on_vuce_pbt_clicked() {
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
    vxUser_dyh *temp;
    int id = vserls.showIds().top() + 1;
    std::string sid = std::to_string(id);
    std::string nickname = ui->name_ldt->text().toStdString();
    std::string password = ui->mima_ldt->text().toStdString();
    std::string birthday = ui->dateEdit->date().toString("yyyy-MM-dd").toStdString();
    std::string location = ui->location_ldt->text().toStdString();
    QDateTime curTime = QDateTime::currentDateTime();
    std::string regTime = curTime.toString("yyyy-MM-dd").toStdString();
    temp = new vxUser_dyh(sid, nickname, birthday, regTime, location, password);
    vserls.addUser(*temp);
    writeVsersToFile(VXUserfile, vserls.showUserls());
    vserls.initUserList(readVsersFromFile(VXUserfile));
    vserls.initIds(readVIdsFromFile(VXUserfile));
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
