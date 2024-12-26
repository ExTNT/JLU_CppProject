#ifndef VXGROUPITEM_H
#define VXGROUPITEM_H

#include <QWidget>

namespace Ui {
    class vxgroupItem;
}

class vxgroupItem : public QWidget {
    Q_OBJECT

  public:
    explicit vxgroupItem(QWidget *parent = nullptr);
    ~vxgroupItem();
    void setIdOn(std::string id, std::string on);
  private slots:
    void on_delelteBtm_clicked();

    void on_detailBtm_clicked();

  private:
    Ui::vxgroupItem* ui;
    QDialog* err;
    QWidget* MyP;
};

#endif // VXGROUPITEM_H
