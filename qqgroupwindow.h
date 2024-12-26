#ifndef QQGROUPWINDOW_H
#define QQGROUPWINDOW_H

#include <QWidget>

namespace Ui {
    class QQgroupwindow;
}

class QQgroupwindow : public QWidget {
    Q_OBJECT

  public:
    explicit QQgroupwindow(QWidget *parent = nullptr);
    ~QQgroupwindow();
    void initLab();
    void initList();
    void LinkMain(QWidget* p) {
        this->main = p;
    }

  private slots:
    void on_exitBtm_clicked();

    void on_addBtm_clicked();

    void on_pushButton_clicked();

  private:
    Ui::QQgroupwindow* ui;
    QDialog* err;
    QWidget* main;
};

#endif // QQGROUPWINDOW_H
