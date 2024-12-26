#ifndef NONEGROUP_ERR_H
#define NONEGROUP_ERR_H

#include <QDialog>

namespace Ui {
class nonegroup_err;
}

class nonegroup_err : public QDialog
{
    Q_OBJECT

public:
    explicit nonegroup_err(QWidget *parent = nullptr);
    ~nonegroup_err();

private:
    Ui::nonegroup_err *ui;
};

#endif // NONEGROUP_ERR_H
