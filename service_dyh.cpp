#include "service_dyh.h"
#include"friendmanager_dyh.h"
#include <iostream>
extern user_dyh* CurUser;
extern FriendManager_dyh& userls;

extern FriendManager_dyh QQuserls;
extern FriendManager_dyh VXuserls;
extern FriendManager_dyh WBuserls;


void QQService_dyh::ActService() {
    userls = QQuserls;
    std::cout << "QQ is running now" << std::endl;
    this->isActive = true;
}


bool QQService_dyh::login(const std::string id, const std::string pw) {
    user_dyh* temp = userls.findFriend(id);
    if (temp == nullptr) {
        return false;
    }
    if (temp->getPassword() != pw) {
        return false;
    }
    if (temp->getPassword() == pw) {
        CurUser = temp;
        return true;
    }
    return false;
}

void QQService_dyh::logout() {
    CurUser = nullptr;
    std::cout << "QQ has exited" << std::endl;
    this->isActive = false;
}
