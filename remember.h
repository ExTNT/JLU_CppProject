#ifndef REMEMBER_H
#define REMEMBER_H

#include <QDialog>
#include "user_dyh.h"

namespace Ui {
    class remember;
}

class remember : public QDialog {
    Q_OBJECT

  public:
    explicit remember(QWidget *parent = nullptr);
    ~remember();
    void LinkUser(user_dyh* p) {
        u = p;
    }
    void initLab();

  private:
    Ui::remember* ui;
    user_dyh* u;
};

#endif // REMEMBER_H
