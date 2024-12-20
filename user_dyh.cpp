#include "user_dyh.h"
#include "friendmanager_dyh.h"
#include <algorithm>

extern FriendManager_dyh& userls;

user_dyh::user_dyh(std::string id, std::string nickname, std::string brithday, std::string regTime, std::string location, std::string password): id(id), password(password), nickname(nickname), brithday(brithday), registrationTime(regTime), location(location) {}

user_dyh::user_dyh() = default;

user_dyh::~user_dyh() = default;

std::string user_dyh::getId() const {
    return this->id;
}

std::vector<std::string> user_dyh::getFrds() const {
    return this->friends;
}

std::vector<std::string> user_dyh::getGrps() const {
    return this->groups;
}

std::string user_dyh::getPassword() const {
    return this->password;
}

std::vector<std::string>& user_dyh::giveFrds() {
    return this->friends;
}

std::vector<std::string>& user_dyh::giveGrps() {
    return this->groups;
}

void user_dyh::setNickName(const std::string& newName) {
    this->nickname = newName;
    return;
}

void user_dyh::addFriend(const std::string& friendId) {
    userls.addFriend(friendId, *this);
    return;
}

void user_dyh::delFriend(const std::string& friendId) {
    userls.delFriend(friendId, *this);
    return;
}

void user_dyh::joinGroup(const std::string& groupId) {
    this->groups.push_back(groupId);
    return;
}

void user_dyh::leaveGroup(const std::string& groupId) {
    this->groups.erase(std::find(this->groups.begin(), this->groups.end(), groupId));
    return;
}

json user_dyh::toJson() const {
    return json{
        {"id", id},
        {"password", password},
        {"nickname", nickname},
        {"brithday", brithday},
        {"registrationTime", registrationTime},
        {"location", location},
        {"friends", friends},
        {"groups", groups}
    };
}

void user_dyh::fromJson(const json& j) {
    j.at("id").get_to(id);
    j.at("password").get_to(password);
    j.at("nickname").get_to(nickname);
    j.at("brithday").get_to(brithday);
    j.at("registrationTime").get_to(registrationTime);
    j.at("location").get_to(location);
    j.at("friends").get_to(friends);
    j.at("groups").get_to(groups);
}

json vxUser_dyh::toJson() const {
    return json{
        {"id", id},
        {"password", password},
        {"nickname", nickname},
        {"brithday", brithday},
        {"registrationTime", registrationTime},
        {"location", location},
        {"friends", friends},
        {"groups", groups},
        {"linkQQ", linkQQ}
    };
}

void vxUser_dyh::fromJson(const json& j) {
    j.at("id").get_to(id);
    j.at("password").get_to(password);
    j.at("nickname").get_to(nickname);
    j.at("brithday").get_to(brithday);
    j.at("registrationTime").get_to(registrationTime);
    j.at("location").get_to(location);
    j.at("friends").get_to(friends);
    j.at("groups").get_to(groups);
    j.at("linkQQ").get_to(linkQQ);
}

void vxUser_dyh::linkToQQ(const std::string qqid) {
    this->linkQQ = qqid;
}
