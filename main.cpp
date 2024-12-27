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
#include "group_dyh.h"
#include "groupmanager_dyh.h"
#include "qqgroupwindow.h"
#include "vxmain.h"
#include "vxlogin.h"
#include "vxsignup.h"
#include "vxdetail.h"
#include "vxchangedetail.h"
#include "vxresetpswd.h"
#include "vxfriendwindow.h"
#include "vxgroupwindow.h"
#include <QApplication>
#include <vector>
#include <queue>

user_dyh* CurUser = nullptr;
vxUser_dyh* CurVser = nullptr;

const std::string QQUserfile = "../../QQuserlist.json";
const std::string VXUserfile = "../../VXuserlist.json";

const std::string QQGroupfile = "../../QQgrouplist.json";
const std::string VXGroupfile = "../../VXgrouplist.json";

FriendManager_dyh QQuserls;
VXFriendManager_dyh VXuserls;

QQgroupmanager_dyh QQgroupls;
QQgroupmanager_dyh VXgroupls;

FriendManager_dyh& userls = QQuserls;
VXFriendManager_dyh& vserls = VXuserls;

//std::priority_queue<int, std::vector<int> > QQids;
//std::priority_queue<int, std::vector<int> > VXids;


QQService_dyh QQ;
WeChatService_dyh VX;
// WeiBoService_dyh WB;


int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    //实例化各页面
    chooseService chS;
    //QQ
    Widget w;
    vuceWidget vuce_w;
    QQmain qqmain;
    QQDetail qqdetail;
    QQchangedetail qqcdtl;
    QQResetPswd qqrspd;
    QQFriendWindow qqfw;
    QQgroupwindow qqgw;
    //VX
    VXmain vxmain;
    VXLogin vxlog;
    VXSignUp vxsign;
    VXDetail vxdetail;
    VXchangedetail vxcdtl;
    VXResetPswd vxrspd;
    VXFriendWindow vxfw;
    VXgroupwindow vxgw;
    //连接各页面
    chS.linkToQQPage(&w);
    chS.linkQQmain(&qqmain);
    chS.linkToVXPage(&vxlog);
    chS.linkVXmain(&vxmain);
    chS.linkApp(&a);
    //QQLINK
    w.LinkVuce(&vuce_w);
    w.LinkChoose(&chS);
    w.LinkMain(&qqmain);
    vuce_w.LinkW(&w);
    qqmain.LinkChoose(&chS);
    qqmain.LinkDetail(&qqdetail);
    qqmain.LinkFriend(&qqfw);
    qqmain.LinkGroups(&qqgw);
    qqdetail.LinkMainWindow(&qqmain);
    qqdetail.LinkchangeDetai(&qqcdtl);
    qqdetail.LinkResetpd(&qqrspd);
    qqcdtl.LinkQQdetail(&qqdetail);
    qqrspd.LinkQQDetail(&qqdetail);
    qqfw.LinkMain(&qqmain);
    qqgw.LinkMain(&qqmain);
    //VXLINL
    vxlog.LinkVuce(&vxsign);
    vxlog.LinkChoose(&chS);
    vxlog.LinkMain(&vxmain);
    vxsign.LinkW(&vxlog);
    vxmain.LinkChoose(&chS);
    vxmain.LinkDetail(&vxdetail);
    vxmain.LinkFriend(&vxfw);
    vxmain.LinkGroups(&vxgw);
    vxdetail.LinkMainWindow(&vxmain);
    vxdetail.LinkchangeDetai(&vxcdtl);
    vxdetail.LinkResetpd(&vxrspd);
    vxcdtl.LinkQQdetail(&vxdetail);
    vxrspd.LinkQQDetail(&vxdetail);
    vxfw.LinkMain(&vxmain);
    vxgw.LinkMain(&vxmain);
    //读取文件
    QQuserls.initUserList(readUsersFromFile(QQUserfile));
    QQuserls.initIds(readIdsFromFile(QQUserfile));
    VXuserls.initUserList(readVsersFromFile(VXUserfile));
    VXuserls.initIds(readVIdsFromFile(VXUserfile));
    QQgroupls.initGpList(readGroupsFromFile(QQGroupfile));
    QQgroupls.initIds(readGroupsIdsFromFile(QQGroupfile));
    VXgroupls.initGpList(readGroupsFromFile(VXGroupfile));
    VXgroupls.initIds(readGroupsIdsFromFile(VXGroupfile));
    chS.show();
    return a.exec();
}
