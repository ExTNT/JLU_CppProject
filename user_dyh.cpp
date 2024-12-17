#include "user_dyh.h"
#include <algorithm>

user_dyh::user_dyh(std::string id,std::string nickname,std::string brithday,std::string regTime,std::string location):id(id),nickname(nickname),brithday(brithday),registrationTime(regTime),location(location){}

user_dyh::~user_dyh()
{
    delete this;
}

std::string user_dyh::getId() const
{
    return this->id;
}

void user_dyh::setNickName(const std::string& newName)
{
    this->nickname=newName;
    return;
}

void user_dyh::addFriend(const std::string& friendId)
{
    this->friends.push_back(friendId);
    return;
}

void user_dyh::delFriend(const std::string& friendId)
{
    this->friends.erase(std::find(this->friends.begin(),this->friends.end(),friendId));
    return;
}

void user_dyh::joinGroup(const std::string& groupId)
{
    this->groups.push_back(groupId);
    return;
}

void user_dyh::leaveGroup(const std::string& groupId)
{
    this->groups.erase(std::find(this->groups.begin(),this->groups.end(),groupId));
    return;
}
