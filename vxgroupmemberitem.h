#ifndef VXGROUPMEMBERITEM_H
#define VXGROUPMEMBERITEM_H
#include "group_dyh.h"
#include <QWidget>

namespace Ui {
    class VXGroupMemberItem;
}

class VXGroupMemberItem : public QWidget {
    Q_OBJECT

  public:
    explicit VXGroupMemberItem(QWidget *parent = nullptr);
    ~VXGroupMemberItem();

    void setIdMy(const std::string id, const std::string nm);
    void initBtm(const std::string);
    void LinkGrp(QQGroup_dyh*p) {
        Curg = p;
    }

  private slots:
    void on_pushButton_2_clicked();

  private:
    Ui::VXGroupMemberItem* ui;
    QQGroup_dyh* Curg;
    QWidget* MyP;
};

#endif // VXGROUPMEMBERITEM_H
