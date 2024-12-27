#ifndef GROUPMANAGER_name_H
#define GROUPMANAGER_name_H

#include "group_name.h"
#include <unordered_map>
#include <unordered_map>
#include <vector>
#include <queue>
#include "user_name.h"

class QQgroupmanager_name
{
private:
  std::unordered_map<std::string, QQGroup_name> groupList;
  std::priority_queue<int, std::vector<int>> ids;

public:
  QQgroupmanager_name() = default;
  void initGpList(std::unordered_map<std::string, QQGroup_name>);
  void initIds(std::priority_queue<int, std::vector<int>>);
  QQGroup_name *find(std::string id);

  std::unordered_map<std::string, QQGroup_name> &showgroups();
  std::priority_queue<int, std::vector<int>> &showids();
  std::unordered_map<std::string, QQGroup_name> giveGroups() const;
};

#endif // GROUPMANAGER_name_H
