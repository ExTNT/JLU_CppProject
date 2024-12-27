#ifndef VXFRIENDITEM_DETIAL_H
#define VXFRIENDITEM_DETIAL_H

#include <QWidget>
#include "user_name.h"

namespace Ui
{
  class vxfriendItem_detial;
}

class vxfriendItem_detial : public QWidget
{
  Q_OBJECT

public:
  explicit vxfriendItem_detial(QWidget *parent = nullptr);
  ~vxfriendItem_detial();
  void initLab(vxUser_name *);
private slots:
  void on_pushButton_clicked();

private:
  Ui::vxfriendItem_detial *ui;
  QWidget *Myparent;
};

#endif // VXFRIENDITEM_DETIAL_H
