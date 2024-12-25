#include "QQLogin.h"
#include "QQSignUp.h"
#include "chooseservice.h"
#include "friendmanager_dyh.h"
#include "global.h"
#include "writeAndread.h"
#include "service_dyh.h"
#include "qqmain.h"
#include "qqdetail.h"
#include "qqchangedetail.h"
#include "qqresetpswd.h"
#include "qqfriendwindow.h"
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
    //实例化各页面
    chooseService chS;
    Widget w;
    vuceWidget vuce_w;
    QQmain qqmain;
    QQDetail qqdetail;
    QQchangedetail qqcdtl;
    QQResetPswd qqrspd;
    QQFriendWindow qqfw;
    //连接各页面
    chS.linkToQQPage(&w);
    chS.linkQQmain(&qqmain);
    w.LinkVuce(&vuce_w);
    w.LinkChoose(&chS);
    w.LinkMain(&qqmain);
    vuce_w.LinkW(&w);
    qqmain.LinkChoose(&chS);
    qqmain.LinkDetail(&qqdetail);
    qqmain.LinkFriend(&qqfw);
    qqdetail.LinkMainWindow(&qqmain);
    qqdetail.LinkchangeDetai(&qqcdtl);
    qqdetail.LinkResetpd(&qqrspd);
    qqcdtl.LinkQQdetail(&qqdetail);
    qqrspd.LinkQQDetail(&qqdetail);
    qqfw.LinkMain(&qqmain);
    //读取样式表
    // QFile qss(":/qdarkgraystyle/style.qss");
    // if (qss.open(QFile::ReadOnly)) {
    //     qDebug("open success");
    //     QString style = QLatin1String(qss.readAll());
    //     a.setStyleSheet(style);
    //     qss.close();
    // } else {
    //     qDebug("Open failed");
    // }
    QQuserls.initUserList(readUsersFromFile(QQUserfile));
    QQuserls.initIds(readIdsFromFile(QQUserfile));
    chS.show();
    return a.exec();
}
