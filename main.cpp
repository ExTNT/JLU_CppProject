#include "widget.h"
#include "vucewidget.h"
#include "global.h"
#include <QApplication>
#include <QSqlDatabase>
#include "friendmanager_dyh.h"
#include "writeAndread.h"
FriendManager_dyh userls;

const std::string filePath = "D:\\CS\\QtProject\\cpp_dyh\\userlist.json";

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
    userls.initUserList(readUsersFromFile(filePath));
    user_dyh *a1 = userls.findFriend("10001");
    a1->addFriend("10002");
    writeUsersToFile(filePath, userls.showUserls());
    return a.exec();
}
