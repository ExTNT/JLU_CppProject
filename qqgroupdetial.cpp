#include "qqgroupdetial.h"
#include "ui_qqgroupdetial.h"
#include "user_dyh.h"
#include "groupmemberitem.h"
#include "friendmanager_dyh.h"

extern user_dyh* CurUser;
extern FriendManager_dyh& userls;

QQGroupDetial::QQGroupDetial(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQGroupDetial) {
    ui->setupUi(this);
}

QQGroupDetial::~QQGroupDetial() {
    delete ui;
}

void QQGroupDetial::initLab() {
    ui->idLab->setText(QString::fromStdString(gp->getId()));
    if (gp->isOwner(CurUser->getId())) {
        ui->MyLab->setText("群主");
        return;
    } else if (gp->isAdmin(CurUser->getId())) {
        ui->MyLab->setText("管理员");
        return;
    }
    ui->MyLab->setText("群友");
    return;
}

void QQGroupDetial::initList() {
    ui->listWidget->clear();
    for (auto& i : gp->givemembers()) {
        GroupMemberItem* gmItem = new GroupMemberItem(this);
        gmItem->LinkGrp(gp);
        user_dyh*temp = userls.findFriend(i);
        gmItem->setIdMy(temp->getId(), temp->getNickname());
        gmItem->initBtm(ui->MyLab->text().toStdString());
        QListWidgetItem* mItem = new QListWidgetItem(ui->listWidget);
        mItem->setSizeHint(QSize(340, 120));
        ui->listWidget->setItemWidget(mItem, gmItem);
    }
}

void QQGroupDetial::on_pushButton_clicked() {
    this->hide();
    this->close();
    delete this;
}

