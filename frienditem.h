#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>

namespace Ui {
    class friendItem;
}

class friendItem : public QWidget {
    Q_OBJECT

  public:
    explicit friendItem(QWidget *parent = nullptr);
    ~friendItem();
    void setIdNm(std::string id, std::string nm);
  private slots:
    void on_detailBtm_clicked();

    void on_delelteBtm_clicked();

  private:
    Ui::friendItem* ui;
    QWidget* MyP;
};

#endif // FRIENDITEM_H
