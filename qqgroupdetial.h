#ifndef QQGROUPDETIAL_H
#define QQGROUPDETIAL_H
#include "group_name.h"
#include <QWidget>

namespace Ui
{
  class QQGroupDetial;
}

class QQGroupDetial : public QWidget
{
  Q_OBJECT

public:
  explicit QQGroupDetial(QWidget *parent = nullptr);
  ~QQGroupDetial();
  void initLab();
  void initList();
  QQGroup_name *gp;

private slots:
  void on_pushButton_clicked();

private:
  Ui::QQGroupDetial *ui;
};

#endif // QQGROUPDETIAL_H
