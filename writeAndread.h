#ifndef WRITEANDREAD_H
#define WRITEANDREAD_H

#include <unordered_map>
#include <vector>
#include <queue>
#include "user_name.h"
#include "group_name.h"

void writeUsersToFile(const std::string &filePath, const std::unordered_map<std::string, user_name> &userls);
std::unordered_map<std::string, user_name> readUsersFromFile(const std::string &filePath);
std::priority_queue<int, std::vector<int>> readIdsFromFile(const std::string &filePath);

void writeVsersToFile(const std::string &filePath, const std::unordered_map<std::string, vxUser_name> &vserls);
std::unordered_map<std::string, vxUser_name> readVsersFromFile(const std::string &filePath);
std::priority_queue<int, std::vector<int>> readVIdsFromFile(const std::string &filePath);

void writeGroupsToFile(const std::string &filePath, const std::unordered_map<std::string, QQGroup_name> &groupls);
std::unordered_map<std::string, QQGroup_name> readGroupsFromFile(const std::string &filePath);
std::priority_queue<int, std::vector<int>> readGroupsIdsFromFile(const std::string &filePath);

#endif // WRITEANDREAD_H
