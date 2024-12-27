#ifndef REMEMBER_H
#define REMEMBER_H

#include <QDialog>
#include "user_name.h"

namespace Ui
{
  class remember;
}

class remember : public QDialog
{
  Q_OBJECT

public:
  explicit remember(QWidget *parent = nullptr);
  ~remember();
  void LinkUser(user_name *p)
  {
    u = p;
  }
  void initLab();

private:
  Ui::remember *ui;
  user_name *u;
};

#endif // REMEMBER_H
