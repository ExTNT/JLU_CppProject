#ifndef GROUPMANAGER_DYH_H
#define GROUPMANAGER_DYH_H

#include "group_dyh.h"
#include<unordered_map>
#include <unordered_map>
#include <vector>
#include <queue>
#include "user_dyh.h"



class groupmanager_dyh {
  private:
    std::unordered_map<std::string, group_dyh> groupList;
    std::priority_queue<int, std::vector<int> > ids;
  public:
    groupmanager_dyh();
    void initGpList(std::unordered_map<std::string, group_dyh>);
    void initIds(std::priority_queue<int, std::vector<int> >);
    group_dyh* find(std::string id);
    void addgroup(group_dyh&);
    void delgroup(group_dyh&);

};

#endif // GROUPMANAGER_DYH_H
