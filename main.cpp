#include "widget.h"
#include "vucewidget.h"
#include "global.h"
#include <QApplication>
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    vuceWidget vuce_w;
    w.LinkVuce(&vuce_w);
    vuce_w.LinkW(&w);

    QFile qss(":/qdarkgraystyle/style.qss");
    if( qss.open(QFile::ReadOnly))
    {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open failed");
    }

    qDebug()<<"available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    qDebug()<<driver;

    w.show();
    return a.exec();
}
