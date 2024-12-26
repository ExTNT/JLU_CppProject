#include "service_dyh.h"
#include"friendmanager_dyh.h"
#include <iostream>
extern user_dyh* CurUser;
extern vxUser_dyh* CurVser;
extern FriendManager_dyh& userls;
extern VXFriendManager_dyh& vserls;
extern FriendManager_dyh QQuserls;
extern VXFriendManager_dyh VXuserls;


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

void WeChatService_dyh::ActService() {
    vserls = VXuserls;
    std::cout << "WeChat is running now" << std::endl;
    this->isActive = true;
}


bool WeChatService_dyh::login(const std::string id, const std::string pw) {
    vxUser_dyh* temp = vserls.findFriend(id);
    if (temp == nullptr) {
        return false;
    }
    if (temp->getPassword() != pw) {
        return false;
    }
    if (temp->getPassword() == pw) {
        CurVser = temp;
        return true;
    }
    return false;
}

void WeChatService_dyh::logout() {
    CurVser = nullptr;
    std::cout << "WeChat has exited" << std::endl;
    this->isActive = false;
}
