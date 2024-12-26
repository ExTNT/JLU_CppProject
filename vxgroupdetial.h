#ifndef VXGROUPDETIAL_H
#define VXGROUPDETIAL_H
#include "group_dyh.h"
#include <QWidget>

namespace Ui {
    class VXGroupDetial;
}

class VXGroupDetial : public QWidget {
    Q_OBJECT

  public:
    explicit VXGroupDetial(QWidget *parent = nullptr);
    ~VXGroupDetial();
    void initLab();
    void initList();
    QQGroup_dyh* gp;

  private slots:
    void on_pushButton_clicked();

    void on_addBtm_clicked();

  private:
    Ui::VXGroupDetial* ui;
    QDialog* err;
};

#endif // VXGROUPDETIAL_H
