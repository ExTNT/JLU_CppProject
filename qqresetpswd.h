#ifndef QQRESETPSWD_H
#define QQRESETPSWD_H

#include <QWidget>

namespace Ui {
    class QQResetPswd;
}

class QQResetPswd : public QWidget {
    Q_OBJECT

  public:
    explicit QQResetPswd(QWidget *parent = nullptr);
    ~QQResetPswd();
    void LinkQQDetail(QWidget*);
    void initLab();

  private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::QQResetPswd* ui;
    QWidget* qqdetail;
    QDialog* err;
};

#endif // QQRESETPSWD_H
