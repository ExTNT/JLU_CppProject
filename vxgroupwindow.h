#ifndef VXGROUPWINDOW_H
#define VXGROUPWINDOW_H

#include <QWidget>

namespace Ui {
    class VXgroupwindow;
}

class VXgroupwindow : public QWidget {
    Q_OBJECT

  public:
    explicit VXgroupwindow(QWidget *parent = nullptr);
    ~VXgroupwindow();
    void initLab();
    void initList();
    void LinkMain(QWidget* p) {
        this->main = p;
    }
  private slots:
    void on_exitBtm_clicked();
    void on_pushButton_clicked();

  private:
    Ui::VXgroupwindow* ui;
    QDialog* err;
    QWidget* main;
};

#endif // VXGROUPWINDOW_H
