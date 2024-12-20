#ifndef QQLOGIN_ERR_H
#define QQLOGIN_ERR_H

#include <QDialog>

namespace Ui {
class QQLogin_err;
}

class QQLogin_err : public QDialog
{
    Q_OBJECT

public:
    explicit QQLogin_err(QWidget *parent = nullptr);
    ~QQLogin_err();

private:
    Ui::QQLogin_err *ui;
};

#endif // QQLOGIN_ERR_H
