#ifndef QQRESETPD_ERR_H
#define QQRESETPD_ERR_H

#include <QDialog>

namespace Ui {
    class qqresetpd_err;
}

class qqresetpd_err : public QDialog {
    Q_OBJECT

  public:
    explicit qqresetpd_err(QWidget *parent = nullptr);
    ~qqresetpd_err();

  private:
    Ui::qqresetpd_err* ui;

};

#endif // QQRESETPD_ERR_H
