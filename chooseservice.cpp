#include "chooseservice.h"
#include "ui_chooseservice.h"
#include "service_dyh.h"
#include "user_dyh.h"

extern QQService_dyh QQ;
extern user_dyh* CurUser;
// extern WeChatService_dyh VX;
// extern WeiBoService_dyh WB;

chooseService::chooseService(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chooseService) {
    ui->setupUi(this);
}

chooseService::~chooseService() {
    delete ui;
}

void chooseService::on_QQBtm_clicked() {
    if (CurUser != nullptr) {
        this->hide();
        qqmain->show();
        return;
    }
    this->hide();
    qqpage->show();
    QQ.ActService();
}

void chooseService::linkToQQPage(QWidget* p) {
    this->qqpage = p;
}

void chooseService::linkQQmain(QWidget* p) {
    qqmain = p;
}
