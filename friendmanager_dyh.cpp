#include "friendmanager_dyh.h"
#include <algorithm>

FriendManager_dyh::FriendManager_dyh() {}


void FriendManager_dyh::addFriend(const std::string friendId, user_dyh& user) {
    std::vector<std::string>& temp = user.giveFrds();
    temp.push_back(friendId);
    user_dyh* a = findFriend(friendId);
    std::vector<std::string>& tempf = a->giveFrds();
    tempf.push_back(user.getId());
}

void FriendManager_dyh::delFriend(const std::string friendId, user_dyh& user) {
    std::vector<std::string>& temp = user.giveFrds();
    temp.erase(std::find(temp.begin(), temp.end(), friendId));
    user_dyh& frd = userList[friendId];
    temp = frd.giveFrds();
    temp.erase(std::find(temp.begin(), temp.end(), user.getId()));
}

user_dyh* FriendManager_dyh::findFriend(const std::string id) {
    user_dyh* that = &userList[id];
    return that;
}

void FriendManager_dyh::initUserList(std::unordered_map<std::string, user_dyh> a) {
    this->userList = a;
    return;
}

void FriendManager_dyh::addUser(user_dyh& user) {
    this->userList.insert({user.getId(), user});
}

std::unordered_map<std::string, user_dyh> FriendManager_dyh::showUserls() const {
    return this->userList;
}
