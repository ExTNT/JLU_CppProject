#ifndef QQCHANGEDETAIL_H
#define QQCHANGEDETAIL_H

#include <QWidget>

namespace Ui {
    class QQchangedetail;
}

class QQchangedetail : public QWidget {
    Q_OBJECT

  public:
    explicit QQchangedetail(QWidget *parent = nullptr);
    ~QQchangedetail();
    void initLdt();
    void LinkQQdetail(QWidget*);

  private slots:
    void on_confrimBtm_clicked();

    void on_exitBtm_clicked();

  private:
    Ui::QQchangedetail* ui;
    QWidget* qqdetail;
};

#endif // QQCHANGEDETAIL_H
