#ifndef QQSIGNUP_ERR_NAME_H
#define QQSIGNUP_ERR_NAME_H

#include <QDialog>

namespace Ui {
class QQSignUp_err_name;
}

class QQSignUp_err_name : public QDialog
{
    Q_OBJECT

public:
    explicit QQSignUp_err_name(QWidget *parent = nullptr);
    ~QQSignUp_err_name();

private:
    Ui::QQSignUp_err_name *ui;
};

#endif // QQSIGNUP_ERR_NAME_H
