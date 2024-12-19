#ifndef QQSIGNUP_H
#define QQSIGNUP_H

#include <QWidget>


namespace Ui {
    class vuceWidget;
}

class vuceWidget : public QWidget {
    Q_OBJECT

  public:
    explicit vuceWidget(QWidget *parent = nullptr);
    ~vuceWidget();
    void LinkW(QWidget *p);

  private slots:
    void on_qvxc_pbt_clicked();

  private:
    Ui::vuceWidget* ui;
    QWidget* w;
};

#endif // QQSIGNUP_H
