#include "widget.h"
#include "vucewidget.h"
#include "global.h"
#include <QApplication>

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


    w.show();
    return a.exec();
}
