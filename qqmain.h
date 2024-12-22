#ifndef QQMAIN_H
#define QQMAIN_H

#include <QWidget>

namespace Ui {
    class QQmain;
}

class QQmain : public QWidget {
    Q_OBJECT

  public:
    explicit QQmain(QWidget *parent = nullptr);
    ~QQmain();
    void setLab();
    void LinkChoose(QWidget* p);
    void LinkDetail(QWidget* p);

  private slots:
    void on_detailBtm_clicked();

    void on_exitBtm_clicked();

    void on_changeBtm_clicked();

  private:
    Ui::QQmain* ui;
    QWidget* choose;
    QWidget* details;
};

#endif // QQMAIN_H
