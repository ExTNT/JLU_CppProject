#ifndef QQSIGNUP_H
#define QQSIGNUP_H

#include <QWidget>
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
    class vuceWidget;
}
QT_END_NAMESPACE


class vuceWidget : public QWidget {
    Q_OBJECT

  public:
    explicit vuceWidget(QWidget *parent = nullptr);
    ~vuceWidget();
    void LinkW(QWidget *p);

  private slots:
    void on_qvxc_pbt_clicked();

    void on_vuce_pbt_clicked();

  private:
    Ui::vuceWidget* ui;
    QWidget* w;
    QDialog* err;
    QDialog* err_name;
};

#endif // QQSIGNUP_H
