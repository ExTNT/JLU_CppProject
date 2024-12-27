#include "groupmanager_name.h"

QQGroup_name *QQgroupmanager_name::find(const std::string id)
{
    auto that = groupList.find(id);
    if (that != groupList.end())
    {
        return &(that->second);
    }
    else
    {
        return nullptr;
    }
}

void QQgroupmanager_name::initGpList(std::unordered_map<std::string, QQGroup_name> a)
{
    this->groupList = a;
}

void QQgroupmanager_name::initIds(std::priority_queue<int, std::vector<int>> a)
{
    this->ids = a;
}

std::unordered_map<std::string, QQGroup_name> &QQgroupmanager_name::showgroups()
{
    return this->groupList;
}

std::priority_queue<int, std::vector<int>> &QQgroupmanager_name::showids()
{
    return this->ids;
}

std::unordered_map<std::string, QQGroup_name> QQgroupmanager_name::giveGroups() const
{
    return this->groupList;
}
