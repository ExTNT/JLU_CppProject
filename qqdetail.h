#ifndef QQDETAIL_H
#define QQDETAIL_H

#include <QWidget>

namespace Ui {
    class QQDetail;
}

class QQDetail : public QWidget {
    Q_OBJECT

  public:
    explicit QQDetail(QWidget *parent = nullptr);
    ~QQDetail();
    void initLab();
    void LinkMainWindow(QWidget* p);
    void LinkchangeDetai(QWidget* p);
    void LinkResetpd(QWidget*p);
  private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::QQDetail* ui;
    QWidget* mainWindow;
    QWidget* changeDetail;
    QWidget* resetpd;
};

#endif // QQDETAIL_H
