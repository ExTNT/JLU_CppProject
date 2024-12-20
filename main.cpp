#include "QQLogin.h"
#include "QQSignUp.h"
#include "chooseservice.h"
#include "friendmanager_dyh.h"
#include "global.h"
#include "writeAndread.h"
#include "service_dyh.h"
#include <QApplication>
#include <vector>
#include <queue>

user_dyh* CurUser = nullptr;

const std::string QQUserfile = "D:\\CS\\QtProject\\cpp_dyh\\QQuserlist.json";
const std::string VXUserfile = "D:\\CS\\QtProject\\cpp_dyh\\VXuserlist.json";
const std::string WBUserfile = "D:\\CS\\QtProject\\cpp_dyh\\WBuserlist.json";

FriendManager_dyh QQuserls;
FriendManager_dyh VXuserls;
FriendManager_dyh WBuserls;

FriendManager_dyh& userls = QQuserls;

std::priority_queue<int, std::vector<int> > QQids;
std::priority_queue<int, std::vector<int> > VXids;
std::priority_queue<int, std::vector<int> > WBids;

QQService_dyh QQ;
// WeChatService_dyh VX;
// WeiBoService_dyh WB;


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    chooseService chS;
    Widget w;
    vuceWidget vuce_w;
    chS.linkToQQPage(&w);
    w.LinkVuce(&vuce_w);
    w.LinkChoose(&chS);
    vuce_w.LinkW(&w);
    QFile qss(":/qdarkgraystyle/style.qss");
    if (qss.open(QFile::ReadOnly)) {
        qDebug("open success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    } else {
        qDebug("Open failed");
    }
    QQuserls.initUserList(readUsersFromFile(QQUserfile));
    QQuserls.initIds(readIdsFromFile(QQUserfile));
    chS.show();
    return a.exec();
}
