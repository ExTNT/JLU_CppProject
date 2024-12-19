#include "QQLogin.h"
#include "QQSignUp.h"
#include "global.h"
#include <QApplication>
#include <QSqlDatabase>
#include "friendmanager_dyh.h"
//#include "writeAndread.h"
FriendManager_dyh userls;

const std::string QQuserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";
const std::string VXuserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";
const std::string WBuserfile = "D:\\CS\\QtProject\\cpp_dyh\\WBuserlist.json";


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    Widget w;
    vuceWidget vuce_w;
    w.LinkVuce(&vuce_w);
    vuce_w.LinkW(&w);
    QFile qss(":/qdarkgraystyle/style.qss");
    if ( qss.open(QFile::ReadOnly)) {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    } else {
        qDebug("Open failed");
    }
    w.show();
    return a.exec();
}
