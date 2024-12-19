#include "friendmanager_dyh.h"
#include <algorithm>

FriendManager_dyh::FriendManager_dyh() {}

user_dyh* FriendManager_dyh::findFriend(const std::string id) {
    auto that = this->userList.find(id);
    if (that != userList.end()) {
        return &(that->second);
    } else {
        return nullptr;
    }
}
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
    user_dyh * a = findFriend(friendId);
    std::vector<std::string>& tempf = a->giveFrds();
    tempf.erase(std::find(tempf.begin(), tempf.end(), user.getId()));
}

void FriendManager_dyh::initUserList(std::unordered_map<std::string, user_dyh> a) {
    this->userList = a;
    return;
}

void FriendManager_dyh::initIds(std::priority_queue<int, std::vector<int> > a) {
    this->ids = a;
    return;
}

void FriendManager_dyh::addUser(user_dyh& user) {
    this->userList.insert({user.getId(), user});
}

std::unordered_map<std::string, user_dyh> FriendManager_dyh::showUserls() const {
    return this->userList;
}

std::priority_queue<int, std::vector<int> > FriendManager_dyh::showIds() const {
    return this->ids;
}
