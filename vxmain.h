#ifndef VXMAIN_H
#define VXMAIN_H

#include <QWidget>

namespace Ui {
    class VXmain;
}

class VXmain : public QWidget {
    Q_OBJECT

  public:
    explicit VXmain(QWidget *parent = nullptr);
    ~VXmain();
    void setLab();
    void LinkChoose(QWidget* p);
    void LinkDetail(QWidget* p);
    void LinkFriend(QWidget* p);
    void LinkGroups(QWidget* p);

  private slots:
    void on_detailBtm_clicked();

    void on_exitBtm_clicked();

    void on_changeBtm_clicked();

    void on_friendBtm_clicked();

    void on_groupBtm_clicked();

  private:
    Ui::VXmain* ui;
    QWidget* choose;
    QWidget* details;
    QWidget* Friends;
    QWidget* Groups;
};

#endif // VXMAIN_H
