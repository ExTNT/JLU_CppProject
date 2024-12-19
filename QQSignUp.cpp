#include "QQSignUp.h"
#include "ui_QQSignUp.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "writeAndread.h"
#include "errPassword2.h"
#include <string>
#include <QString>
#include <QDateTime>
extern FriendManager_dyh& userls;
const std::string QQUserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";

vuceWidget::vuceWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vuceWidget) {
    ui->setupUi(this);
    err = new Dialog(this);
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
    if ((ui->mima_ldt->text() != ui->qvrf_ldt->text()) || (ui->mima_ldt->text().isEmpty() || ui->qvrf_ldt->text().isEmpty())) {
        ui->mima_ldt->clear();
        ui->qvrf_ldt->clear();
        err->show();
        return;
    }
    user_dyh* temp;
    int id = userls.showIds().top() + 1;
    std::string sid = std::to_string(id);
    std::string nickname = ui->name_ldt->text().toStdString();
    std::string password = ui->mima_ldt->text().toStdString();
    std::string birthday = ui->birth_ldt->text().toStdString();
    std::string location = ui->location_ldt->text().toStdString();
    QDateTime curTime = QDateTime::currentDateTime();
    std::string regTime = curTime.toString("yyyy-MM-dd").toStdString();
    temp = new user_dyh(sid, nickname, birthday, regTime, location, password);
    userls.addUser(*temp);
    writeUsersToFile(QQUserfile, userls.showUserls());
    ui->name_ldt->clear();
    ui->mima_ldt->clear();
    ui->qvrf_ldt->clear();
    ui->birth_ldt->clear();
    ui->location_ldt->clear();
    return;
}

