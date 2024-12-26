#include "vxresetpswd.h"
#include "ui_vxresetpswd.h"
#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include "writeAndread.h"
#include "qqresetpd_err.h"

extern vxUser_dyh* CurVser;
extern VXFriendManager_dyh& vserls;
inline const std::string VXUserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";

VXResetPswd::VXResetPswd(QWidget *parent)
    : QWidget(parent), ui(new Ui::VXResetPswd) {
    ui->setupUi(this);
    err = new qqresetpd_err(this);
}

VXResetPswd::~VXResetPswd() {
    delete ui;
}

void VXResetPswd::LinkQQDetail(QWidget *p) {
    this->qqdetail = p;
}

void VXResetPswd::on_pushButton_clicked() {
    std::string oringin = ui->oringinLdt->text().toStdString();
    std::string newpd1 = ui->newLdt1->text().toStdString();
    std::string newpd2 = ui->newLdt2->text().toStdString();
    if (oringin == CurVser->getPassword() && newpd1 == newpd2 && !oringin.empty() && !newpd1.empty() && !newpd2.empty()) {
        CurVser->setPassword(newpd1);
        writeVsersToFile(VXUserfile, vserls.showUserls());
        this->hide();
        qqdetail->show();
    } else {
        ui->oringinLdt->clear();
        ui->newLdt1->clear();
        ui->newLdt2->clear();
        err->show();
    }
}

void VXResetPswd::initLab() {
    ui->idLab->setText(QString::fromStdString(CurVser->getId()));
    ui->nameLab->setText(QString::fromStdString(CurVser->getNickname()));
}

void VXResetPswd::on_pushButton_2_clicked() {
    this->hide();
    qqdetail->show();
}
