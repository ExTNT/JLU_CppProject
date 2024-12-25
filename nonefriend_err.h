#ifndef NONEFRIEND_ERR_H
#define NONEFRIEND_ERR_H

#include <QDialog>

namespace Ui {
class nonefriend_err;
}

class nonefriend_err : public QDialog
{
    Q_OBJECT

public:
    explicit nonefriend_err(QWidget *parent = nullptr);
    ~nonefriend_err();

private:
    Ui::nonefriend_err *ui;
};

#endif // NONEFRIEND_ERR_H
