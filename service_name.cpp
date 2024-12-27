#include "service_name.h"
#include "friendmanager_name.h"
#include <iostream>
extern user_name *CurUser;
extern vxUser_name *CurVser;
extern FriendManager_name &userls;
extern VXFriendManager_name &vserls;
extern FriendManager_name QQuserls;
extern VXFriendManager_name VXuserls;

void QQService_name::ActService()
{
    userls = QQuserls;
    std::cout << "QQ is running now" << std::endl;
    this->isActive = true;
}

bool QQService_name::login(const std::string id, const std::string pw)
{
    user_name *temp = userls.findFriend(id);
    if (temp == nullptr)
    {
        return false;
    }
    if (temp->getPassword() != pw)
    {
        return false;
    }
    if (temp->getPassword() == pw)
    {
        CurUser = temp;
        return true;
    }
    return false;
}

void QQService_name::logout()
{
    CurUser = nullptr;
    std::cout << "QQ has exited" << std::endl;
    this->isActive = false;
}

void WeChatService_name::ActService()
{
    vserls = VXuserls;
    std::cout << "WeChat is running now" << std::endl;
    this->isActive = true;
}

bool WeChatService_name::login(const std::string id, const std::string pw)
{
    vxUser_name *temp = vserls.findFriend(id);
    if (temp == nullptr)
    {
        return false;
    }
    if (temp->getPassword() != pw)
    {
        return false;
    }
    if (temp->getPassword() == pw)
    {
        CurVser = temp;
        return true;
    }
    return false;
}

void WeChatService_name::logout()
{
    CurVser = nullptr;
    std::cout << "WeChat has exited" << std::endl;
    this->isActive = false;
}
