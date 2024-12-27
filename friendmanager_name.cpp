#include "friendmanager_name.h"
#include <algorithm>

FriendManager_name::FriendManager_name() {}

user_name *FriendManager_name::findFriend(const std::string id)
{
    auto that = this->userList.find(id);
    if (that != userList.end())
    {
        return &(that->second);
    }
    else
    {
        return nullptr;
    }
}
void FriendManager_name::addFriend(const std::string friendId, user_name &user)
{
    std::vector<std::string> &temp = user.giveFrds();
    if (std::find(temp.begin(), temp.end(), friendId) == temp.end())
    {
        temp.push_back(friendId);
    }
    user_name *a = findFriend(friendId);
    std::vector<std::string> &tempf = a->giveFrds();
    if (std::find(tempf.begin(), tempf.end(), user.getId()) == temp.end())
    {
        tempf.push_back(user.getId());
    }
}

void FriendManager_name::delFriend(const std::string friendId, user_name &user)
{
    std::vector<std::string> &temp = user.giveFrds();
    temp.erase(std::find(temp.begin(), temp.end(), friendId));
    user_name *a = findFriend(friendId);
    std::vector<std::string> &tempf = a->giveFrds();
    tempf.erase(std::find(tempf.begin(), tempf.end(), user.getId()));
}

void FriendManager_name::initUserList(std::unordered_map<std::string, user_name> a)
{
    this->userList = a;
    return;
}

void FriendManager_name::initIds(std::priority_queue<int, std::vector<int>> a)
{
    this->ids = a;
    return;
}

void FriendManager_name::addUser(user_name &user)
{
    this->userList.insert({user.getId(), user});
}

std::unordered_map<std::string, user_name> FriendManager_name::showUserls() const
{
    return this->userList;
}

std::priority_queue<int, std::vector<int>> FriendManager_name::showIds() const
{
    return this->ids;
}

// vx start
VXFriendManager_name::VXFriendManager_name() {}

vxUser_name *VXFriendManager_name::findFriend(const std::string id)
{
    auto that = this->userList.find(id);
    if (that != userList.end())
    {
        return &(that->second);
    }
    else
    {
        return nullptr;
    }
}
void VXFriendManager_name::addFriend(const std::string friendId, user_name &user)
{
    std::vector<std::string> &temp = user.giveFrds();
    if (std::find(temp.begin(), temp.end(), friendId) == temp.end())
    {
        temp.push_back(friendId);
    }
    user_name *a = findFriend(friendId);
    std::vector<std::string> &tempf = a->giveFrds();
    if (std::find(tempf.begin(), tempf.end(), user.getId()) == temp.end())
    {
        tempf.push_back(user.getId());
    }
}

void VXFriendManager_name::delFriend(const std::string friendId, user_name &user)
{
    std::vector<std::string> &temp = user.giveFrds();
    temp.erase(std::find(temp.begin(), temp.end(), friendId));
    user_name *a = findFriend(friendId);
    std::vector<std::string> &tempf = a->giveFrds();
    tempf.erase(std::find(tempf.begin(), tempf.end(), user.getId()));
}

void VXFriendManager_name::initUserList(std::unordered_map<std::string, vxUser_name> a)
{
    this->userList = a;
    return;
}

void VXFriendManager_name::initIds(std::priority_queue<int, std::vector<int>> a)
{
    this->ids = a;
    return;
}

void VXFriendManager_name::addUser(vxUser_name &user)
{
    this->userList.insert({user.getId(), user});
}

std::unordered_map<std::string, vxUser_name> VXFriendManager_name::showUserls() const
{
    return this->userList;
}

std::priority_queue<int, std::vector<int>> VXFriendManager_name::showIds() const
{
    return this->ids;
}
