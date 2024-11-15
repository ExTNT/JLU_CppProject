#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void LinkVuce(QWidget* p);

private slots:
    void on_vuce_pbt_clicked();

private:
    Ui::Widget *ui;
    QWidget *vuce;
};
#endif // WIDGET_H
