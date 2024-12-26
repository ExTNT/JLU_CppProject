#ifndef VXFRIENDITEM_H
#define VXFRIENDITEM_H

#include <QWidget>

namespace Ui {
    class vxfriendItem;
}

class vxfriendItem : public QWidget {
    Q_OBJECT

  public:
    explicit vxfriendItem(QWidget *parent = nullptr);
    ~vxfriendItem();
    void setIdNm(std::string id, std::string nm);
  private slots:
    void on_detailBtm_clicked();

    void on_delelteBtm_clicked();
  private:
    Ui::vxfriendItem* ui;
    QWidget* MyP;
};

#endif // VXFRIENDITEM_H
