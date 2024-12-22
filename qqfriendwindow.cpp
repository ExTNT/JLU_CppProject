#include "qqfriendwindow.h"
#include "ui_qqfriendwindow.h"

QQFriendWindow::QQFriendWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QQFriendWindow)
{
    ui->setupUi(this);
}

QQFriendWindow::~QQFriendWindow()
{
    delete ui;
}
