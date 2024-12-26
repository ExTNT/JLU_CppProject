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
    void linkToVXPage(QWidget* p);
    void linkVXmain(QWidget* p);
    void linkApp(QApplication* p);
  private slots:
    void on_QQBtm_clicked();

    void on_VXBtm_clicked();

    void on_exitBtm_clicked();

  private:
    Ui::chooseService* ui;
    QWidget* qqpage;
    QWidget* qqmain;
    QWidget* vxpage;
    QWidget* vxmain;
    QApplication* app;
};

#endif // CHOOSESERVICE_H
