#ifndef CHOOSESERVICE_H
#define CHOOSESERVICE_H

#include <QWidget>

namespace Ui {
    class chooseService;
}

class chooseService : public QWidget {
    Q_OBJECT

  public:
    explicit chooseService(QWidget *parent = nullptr);
    ~chooseService();
    void linkToQQPage(QWidget* p);
    void linkQQmain(QWidget* p);

  private slots:
    void on_QQBtm_clicked();

  private:
    Ui::chooseService* ui;
    QWidget* qqpage;
    QWidget* qqmain;
};

#endif // CHOOSESERVICE_H
