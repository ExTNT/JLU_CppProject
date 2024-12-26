#ifndef OWNEREXIT_ERR_H
#define OWNEREXIT_ERR_H

#include <QDialog>

namespace Ui {
class OwnerExit_err;
}

class OwnerExit_err : public QDialog
{
    Q_OBJECT

public:
    explicit OwnerExit_err(QWidget *parent = nullptr);
    ~OwnerExit_err();

private:
    Ui::OwnerExit_err *ui;
};

#endif // OWNEREXIT_ERR_H
