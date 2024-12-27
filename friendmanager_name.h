#ifndef FRIENDMANAGER_NAME_H
#define FRIENDMANAGER_NAME_H

#include <unordered_map>
#include <vector>
#include <queue>
#include "user_name.h"

class FriendManager_name
{
private:
  std::unordered_map<std::string, user_name> userList; // 用户列表
  std::priority_queue<int, std::vector<int>> ids;      // 账号表
public:
  FriendManager_name();
  void addFriend(const std::string friendId, user_name &user);
  void delFriend(const std::string friendId, user_name &user);
  user_name *findFriend(const std::string id);
  void initUserList(std::unordered_map<std::string, user_name> a);
  void initIds(std::priority_queue<int, std::vector<int>> a);
  void addUser(user_name &user);
  std::unordered_map<std::string, user_name> showUserls() const;
  std::priority_queue<int, std::vector<int>> showIds() const;
};

class VXFriendManager_name
{
private:
  std::unordered_map<std::string, vxUser_name> userList; // 用户列表
  std::priority_queue<int, std::vector<int>> ids;        // 账号表
public:
  VXFriendManager_name();
  void addFriend(const std::string friendId, user_name &user);
  void delFriend(const std::string friendId, user_name &user);
  vxUser_name *findFriend(const std::string id);
  void initUserList(std::unordered_map<std::string, vxUser_name> a);
  void initIds(std::priority_queue<int, std::vector<int>> a);
  void addUser(vxUser_name &user);
  std::unordered_map<std::string, vxUser_name> showUserls() const;
  std::priority_queue<int, std::vector<int>> showIds() const;
};

#endif // FRIENDMANAGER_NAME_H
