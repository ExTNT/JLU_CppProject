#ifndef CHOOSESERVICE_H
#define CHOOSESERVICE_H

#include <QWidget>

namespace Ui {
class chooseService;
}

class chooseService : public QWidget
{
    Q_OBJECT

public:
    explicit chooseService(QWidget *parent = nullptr);
    ~chooseService();

private:
    Ui::chooseService *ui;
};

#endif // CHOOSESERVICE_H
