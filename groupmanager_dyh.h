#ifndef GROUPMANAGER_DYH_H
#define GROUPMANAGER_DYH_H

#include "group_dyh.h"
#include<unordered_map>
#include <unordered_map>
#include <vector>
#include <queue>
#include "user_dyh.h"



class QQgroupmanager_dyh {
  private:
    std::unordered_map<std::string, QQGroup_dyh> groupList;
    std::priority_queue<int, std::vector<int> > ids;
  public:
    QQgroupmanager_dyh() = default;
    void initGpList(std::unordered_map<std::string, QQGroup_dyh>);
    void initIds(std::priority_queue<int, std::vector<int> >);
    QQGroup_dyh* find(std::string id);

    std::unordered_map<std::string, QQGroup_dyh>& showgroups();
    std::priority_queue<int, std::vector<int> >& showids();
    std::unordered_map<std::string, QQGroup_dyh>giveGroups() const;

};

#endif // GROUPMANAGER_DYH_H
