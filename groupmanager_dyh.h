#ifndef GROUPMANAGER_DYH_H
#define GROUPMANAGER_DYH_H

#include<group_dyh.h>
#include<unordered_map>

class groupmanager_dyh {
  private:
    std::unordered_map<std::string, group_dyh> groupList;

  public:
    groupmanager_dyh();
};

#endif // GROUPMANAGER_DYH_H
