#ifndef VXDETAIL_H
#define VXDETAIL_H

#include <QWidget>

namespace Ui {
    class VXDetail;
}

class VXDetail : public QWidget {
    Q_OBJECT

  public:
    explicit VXDetail(QWidget *parent = nullptr);
    ~VXDetail();
    void initLab();
    void LinkMainWindow(QWidget* p);
    void LinkchangeDetai(QWidget* p);
    void LinkResetpd(QWidget*p);

  private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  private:
    Ui::VXDetail* ui;
    QWidget* mainWindow;
    QWidget* changeDetail;
    QWidget* resetpd;
};

#endif // VXDETAIL_H
