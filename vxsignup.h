#ifndef VXSIGNUP_H
#define VXSIGNUP_H

#include <QWidget>
#include <QDialog>

namespace Ui {
    class VXSignUp;
}

class VXSignUp : public QWidget {
    Q_OBJECT

  public:
    explicit VXSignUp(QWidget *parent = nullptr);
    ~VXSignUp();
    void LinkW(QWidget *p);

  private slots:
    void on_qvxc_pbt_clicked();

    void on_vuce_pbt_clicked();

  private:
    Ui::VXSignUp* ui;
    QWidget* w;
    QDialog* err;
    QDialog* r;
    QDialog* err_name;
};

#endif // VXSIGNUP_H
