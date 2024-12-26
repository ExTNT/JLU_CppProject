#ifndef GROUPMEMBERITEM_H
#define GROUPMEMBERITEM_H

#include <QWidget>
#include "group_dyh.h"
namespace Ui {
    class GroupMemberItem;
}

class GroupMemberItem : public QWidget {
    Q_OBJECT

  public:
    explicit GroupMemberItem(QWidget *parent = nullptr);
    ~GroupMemberItem();
    void setIdMy(const std::string id, const std::string nm);
    void initBtm(const std::string);
    void LinkGrp(QQGroup_dyh*p) {
        Curg = p;
    }

  private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::GroupMemberItem* ui;
    QQGroup_dyh* Curg;
    QWidget* MyP;
};

#endif // GROUPMEMBERITEM_H
