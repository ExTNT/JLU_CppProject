#ifndef VXFRIENDWINDOW_H
#define VXFRIENDWINDOW_H

#include <QWidget>

namespace Ui {
    class VXFriendWindow;
}

class VXFriendWindow : public QWidget {
    Q_OBJECT

  public:
    explicit VXFriendWindow(QWidget *parent = nullptr);
    ~VXFriendWindow();
    void initLab();
    void initList();
    void LinkMain(QWidget*);

  private slots:
    void on_exitBtm_clicked();

    void on_addBtm_clicked();
  private:
    Ui::VXFriendWindow* ui;
    QWidget* vxmain;
    QDialog* err;
};

#endif // VXFRIENDWINDOW_H
