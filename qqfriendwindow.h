#ifndef QQFRIENDWINDOW_H
#define QQFRIENDWINDOW_H

#include <QWidget>

namespace Ui {
    class QQFriendWindow;
}

class QQFriendWindow : public QWidget {
    Q_OBJECT

  public:
    explicit QQFriendWindow(QWidget *parent = nullptr);
    ~QQFriendWindow();
    void initLab();
    void initList();
    void LinkMain(QWidget*);

  private slots:
    void on_exitBtm_clicked();

    void on_addBtm_clicked();

  private:
    Ui::QQFriendWindow* ui;
    QWidget* qqmain;
    QDialog* err;
};

#endif // QQFRIENDWINDOW_H
