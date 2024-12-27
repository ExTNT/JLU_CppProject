#include "user_name.h"
#include "friendmanager_name.h"
#include "group_name.h"
#include "groupmanager_name.h"
#include <algorithm>
#include <string>
#include <iostream>

extern FriendManager_name &userls;
extern QQgroupmanager_name QQgroupls;

user_name::user_name(std::string id, std::string nickname, std::string brithday, std::string regTime, std::string location, std::string password) : id(id), password(password), nickname(nickname), brithday(brithday), registrationTime(regTime), location(location) {}

vxUser_name::vxUser_name(std::string id, std::string nickname, std::string brithday, std::string regTime, std::string location, std::string password) : user_name(id, nickname, brithday, regTime, location, password), linkQQ("") {}

user_name::user_name() = default;

user_name::~user_name() = default;

std::string user_name::getId() const
{
    return this->id;
}

std::vector<std::string> user_name::getFrds() const
{
    return this->friends;
}

std::vector<std::string> user_name::getGrps() const
{
    return this->groups;
}

std::string user_name::getPassword() const
{
    return this->password;
}

const std::string user_name::getNickname() const
{
    return this->nickname;
}

std::string user_name::getBirth() const
{
    return this->brithday;
}

std::string user_name::getReg() const
{
    return this->registrationTime;
}

std::string user_name::getLocal() const
{
    return this->location;
}

std::vector<std::string> &user_name::giveFrds()
{
    return this->friends;
}

std::vector<std::string> &user_name::giveGrps()
{
    return this->groups;
}

void user_name::setNickName(const std::string &newName)
{
    this->nickname = newName;
    return;
}

void user_name::setPassword(const std::string &newPswd)
{
    this->password = newPswd;
    return;
}

void user_name::setBirthday(const std::string &newBirth)
{
    this->brithday = newBirth;
}

void user_name::setLocation(const std::string &newLocal)
{
    this->location = newLocal;
}

void user_name::addFriend(const std::string &friendId)
{
    userls.addFriend(friendId, *this);
    return;
}

void user_name::delFriend(const std::string &friendId)
{
    userls.delFriend(friendId, *this);
    return;
}

void user_name::joinGroup(const std::string &groupId)
{
    this->groups.push_back(groupId);
    QQGroup_name *target = QQgroupls.find(groupId);
    target->addmember(this->id);
    return;
}

void user_name::leaveGroup(const std::string &groupId)
{
    this->groups.erase(std::find(this->groups.begin(), this->groups.end(), groupId));
    QQGroup_name *target = QQgroupls.find(groupId);
    target->delmember(this->id);
    return;
}

json user_name::toJson() const
{
    return json{
        {"id", id},
        {"password", password},
        {"nickname", nickname},
        {"brithday", brithday},
        {"registrationTime", registrationTime},
        {"location", location},
        {"friends", friends},
        {"groups", groups}};
}

void user_name::fromJson(const json &j)
{
    j.at("id").get_to(id);
    j.at("password").get_to(password);
    j.at("nickname").get_to(nickname);
    j.at("brithday").get_to(brithday);
    j.at("registrationTime").get_to(registrationTime);
    j.at("location").get_to(location);
    j.at("friends").get_to(friends);
    j.at("groups").get_to(groups);
}

json vxUser_name::toJson() const
{
    return json{
        {"id", id},
        {"password", password},
        {"nickname", nickname},
        {"brithday", brithday},
        {"registrationTime", registrationTime},
        {"location", location},
        {"friends", friends},
        {"groups", groups},
        {"linkQQ", linkQQ}};
}

void vxUser_name::fromJson(const json &j)
{
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

void vxUser_name::linkToQQ(const std::string qqid)
{
    this->linkQQ = qqid;
}

void user_name::creatGroup()
{
    QQGroup_name temp;
    temp.setID(std::to_string(QQgroupls.showids().top() + 1));
    QQgroupls.showids().push(QQgroupls.showids().top() + 1);
    temp.setOwner(this->id);
    temp.givemembers().push_back(this->getId());
    QQgroupls.showgroups().insert({temp.getId(), temp});
    this->groups.push_back(temp.getId());
}

std::string &vxUser_name::giveQQ()
{
    return this->linkQQ;
}
