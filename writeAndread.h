#ifndef WRITEANDREAD_H
#define WRITEANDREAD_H

#include<unordered_map>
#include<vector>
#include<queue>
#include"user_dyh.h"

void writeUsersToFile(const std::string& filePath, const std::unordered_map<std::string, user_dyh>& userls);
std::unordered_map<std::string, user_dyh> readUsersFromFile(const std::string& filePath);
std::priority_queue<int, std::vector<int> > readIdsFromFile(const std::string& filePath);

#endif // WRITEANDREAD_H
