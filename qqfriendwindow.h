#ifndef QQFRIENDWINDOW_H
#define QQFRIENDWINDOW_H

#include <QWidget>

namespace Ui {
class QQFriendWindow;
}

class QQFriendWindow : public QWidget
{
    Q_OBJECT

public:
    explicit QQFriendWindow(QWidget *parent = nullptr);
    ~QQFriendWindow();

private:
    Ui::QQFriendWindow *ui;
};

#endif // QQFRIENDWINDOW_H
