#ifndef VXCHANGEDETAIL_H
#define VXCHANGEDETAIL_H

#include <QWidget>

namespace Ui {
    class VXchangedetail;
}

class VXchangedetail : public QWidget {
    Q_OBJECT

  public:
    explicit VXchangedetail(QWidget *parent = nullptr);
    ~VXchangedetail();
    void initLdt();
    void LinkQQdetail(QWidget*);

  private slots:
    void on_confrimBtm_clicked();

    void on_exitBtm_clicked();

  private:
    Ui::VXchangedetail* ui;
    QWidget* vxdetail;
    QDialog* noname;
};

#endif // VXCHANGEDETAIL_H
