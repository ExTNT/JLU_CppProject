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
    void LinkFriend(QWidget* p);

  private slots:
    void on_detailBtm_clicked();

    void on_exitBtm_clicked();

    void on_changeBtm_clicked();

    void on_friendBtm_clicked();

  private:
    Ui::QQmain* ui;
    QWidget* choose;
    QWidget* details;
    QWidget* Friends;
};

#endif // QQMAIN_H
