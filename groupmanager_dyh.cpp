#include "groupmanager_dyh.h"

QQGroup_dyh* QQgroupmanager_dyh::find(const std::string id) {
    auto that = groupList.find(id);
    if (that != groupList.end()) {
        return &(that->second);
    } else {
        return nullptr;
    }
}

void QQgroupmanager_dyh::initGpList(std::unordered_map<std::string, QQGroup_dyh> a) {
    this->groupList = a;
}

void QQgroupmanager_dyh::initIds(std::priority_queue<int, std::vector<int> > a) {
    this->ids = a;
}

std::unordered_map<std::string, QQGroup_dyh>&  QQgroupmanager_dyh::showgroups() {
    return this->groupList;
}

std::priority_queue<int, std::vector<int> >& QQgroupmanager_dyh::showids() {
    return this->ids;
}

std::unordered_map<std::string, QQGroup_dyh> QQgroupmanager_dyh::giveGroups() const {
    return this->groupList;
}
