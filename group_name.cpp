#include "group_name.h"
#include <algorithm>

group_name::group_name() {}

std::string group_name::getId() const
{
    return this->groupId;
}

std::string group_name::getOwner() const
{
    return this->groupOwner;
}

json QQGroup_name::toJson() const
{
    return json{
        {"id", groupId},
        {"owner", groupOwner},
        {"admins", admins},
        {"members", members}};
}

void QQGroup_name::fromJson(const json &j)
{
    j.at("id").get_to(groupId);
    j.at("owner").get_to(groupOwner);
    j.at("admins").get_to(admins);
    j.at("members").get_to(members);
}

json WeChatGroup_name::toJson() const
{
    return json{
        {"id", groupId},
        {"owner", groupOwner},
        {"members", members}};
}

void WeChatGroup_name::fromJson(const json &j)
{
    j.at("id").get_to(groupId);
    j.at("owner").get_to(groupOwner);
    j.at("members").get_to(members);
}

void group_name::setID(const std::string &str)
{
    groupId = str;
}

void group_name::setOwner(const std::string &str)
{
    groupOwner = str;
}

std::vector<std::string> &group_name::givemembers()
{
    return members;
}

void group_name::addmember(const std::string &userid)
{
    if (std::find(members.begin(), members.end(), userid) == members.end())
    {
        this->members.push_back(userid);
        return;
    }
}

void group_name::delmember(const std::string &userid)
{
    if (std::find(this->members.begin(), this->members.end(), userid) == members.end())
    {
        return;
    }
    this->members.erase(std::find(this->members.begin(), this->members.end(), userid));
}

bool group_name::isOwner(const std::string &userid)
{
    return userid == groupOwner;
}

bool QQGroup_name::isAdmin(const std::string userid)
{
    auto temp = std::find(this->admins.begin(), this->admins.end(), userid);
    if (temp == this->admins.end())
    {
        return false;
    }
    return true;
}

void QQGroup_name::addAdmin(const std::string userid)
{
    if (std::find(admins.begin(), admins.end(), userid) == admins.end())
    {
        this->admins.push_back(userid);
        return;
    }
}

void QQGroup_name::delAdmin(const std::string userid)
{
    if (std::find(admins.begin(), admins.end(), userid) == admins.end())
    {
        return;
    }
    this->admins.erase(std::find(admins.begin(), admins.end(), userid));
}
