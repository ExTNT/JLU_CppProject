#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void LinkVuce(QWidget* p);
    void LinkChoose(QWidget* p);
    void LinkMain(QWidget* p);

  private slots:
    void on_vuce_pbt_clicked();

    void on_dglu_pbt_clicked();

    void on_exitBtm_clicked();

  private:
    Ui::Widget* ui;
    QWidget* vuce;
    QDialog* err;
    QWidget* choose;
    QWidget* mainWindow;
};
#endif // WIDGET_H
