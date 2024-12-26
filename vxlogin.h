#ifndef VXLOGIN_H
#define VXLOGIN_H

#include <QWidget>

namespace Ui {
    class VXLogin;
}

class VXLogin : public QWidget {
    Q_OBJECT

  public:
    explicit VXLogin(QWidget *parent = nullptr);
    ~VXLogin();
    void LinkVuce(QWidget*p);
    void LinkChoose(QWidget* p);
    void LinkMain(QWidget* p);

  private slots:
    void on_vuce_pbt_clicked();

    void on_dglu_pbt_clicked();

    void on_exitBtm_clicked();


  private:
    Ui::VXLogin* ui;
    QWidget* vuce;
    QDialog* err;
    QWidget* choose;
    QWidget* mainWindow;
};

#endif // VXLOGIN_H
