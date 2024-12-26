#ifndef WRITEANDREAD_H
#define WRITEANDREAD_H

#include <unordered_map>
#include <vector>
#include <queue>
#include "user_dyh.h"
#include "group_dyh.h"


void writeUsersToFile(const std::string& filePath, const std::unordered_map<std::string, user_dyh>& userls);
std::unordered_map<std::string, user_dyh> readUsersFromFile(const std::string& filePath);
std::priority_queue<int, std::vector<int> > readIdsFromFile(const std::string& filePath);

void writeVsersToFile(const std::string& filePath, const std::unordered_map<std::string, vxUser_dyh>& vserls);
std::unordered_map<std::string, vxUser_dyh> readVsersFromFile(const std::string& filePath);
std::priority_queue<int, std::vector<int> > readVIdsFromFile(const std::string& filePath);

void writeGroupsToFile(const std::string& filePath, const std::unordered_map < std::string, QQGroup_dyh>& groupls);
std::unordered_map < std::string, QQGroup_dyh> readGroupsFromFile(const std::string& filePath);
std::priority_queue<int, std::vector<int> > readGroupsIdsFromFile(const std::string& filePath);

#endif // WRITEANDREAD_H
