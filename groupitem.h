#ifndef GROUPITEM_H
#define GROUPITEM_H

#include <QWidget>

namespace Ui {
    class groupItem;
}

class groupItem : public QWidget {
    Q_OBJECT

  public:
    explicit groupItem(QWidget *parent = nullptr);
    ~groupItem();
    void setIdOn(std::string id, std::string on);
  private slots:
    void on_delelteBtm_clicked();

    void on_detailBtm_clicked();

  private:
    QDialog* err;
    QWidget* MyP;
    Ui::groupItem* ui;
};

#endif // GROUPITEM_H
