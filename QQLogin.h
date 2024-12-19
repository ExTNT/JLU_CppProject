#ifndef QQLOGIN_H
#define QQLOGIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class QQLogin;
}
QT_END_NAMESPACE

class QQLogin : public QWidget {
    Q_OBJECT

  public:
    QQLogin(QWidget *parent = nullptr);
    ~QQLogin();
    void LinkVuce(QWidget* p);

  private slots:
    void on_vuce_pbt_clicked();

  private:
    Ui::QQLogin* ui;
    QWidget* vuce;
};
#endif // QQLOGIN_H
