#ifndef FRIENDITEM_DETIAL_H
#define FRIENDITEM_DETIAL_H

#include <QWidget>
#include "user_name.h"

namespace Ui
{
  class friendItem_detial;
}

class friendItem_detial : public QWidget
{
  Q_OBJECT

public:
  explicit friendItem_detial(QWidget *parent = nullptr);
  ~friendItem_detial();
  void initLab(user_name *);
private slots:
  void on_pushButton_clicked();

private:
  Ui::friendItem_detial *ui;
  QWidget *Myparent;
};

#endif // FRIENDITEM_DETIAL_H
