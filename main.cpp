#include "widget.h"
#include "global.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

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


    w.show();
    return a.exec();
}
