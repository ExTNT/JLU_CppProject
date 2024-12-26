#ifndef VXRESETPSWD_H
#define VXRESETPSWD_H

#include <QWidget>

namespace Ui {
    class VXResetPswd;
}

class VXResetPswd : public QWidget {
    Q_OBJECT

  public:
    explicit VXResetPswd(QWidget *parent = nullptr);
    ~VXResetPswd();
    void LinkQQDetail(QWidget*);
    void initLab();

  private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::VXResetPswd* ui;
    QWidget* qqdetail;
    QDialog* err;
};

#endif // VXRESETPSWD_H
