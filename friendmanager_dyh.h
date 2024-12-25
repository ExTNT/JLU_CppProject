#ifndef FRIENDMANAGER_DYH_H
#define FRIENDMANAGER_DYH_H

#include <unordered_map>
#include <vector>
#include <queue>
#include "user_dyh.h"


class FriendManager_dyh {
  private:
    std::unordered_map<std::string, user_dyh> userList;       //用户列表
    std::priority_queue<int, std::vector<int> > ids;          //账号表
  public:
    FriendManager_dyh();
    void addFriend(const std::string friendId, user_dyh& user);
    void delFriend(const std::string friendId, user_dyh& user);
    user_dyh* findFriend(const std::string id);
    void initUserList(std::unordered_map<std::string, user_dyh> a);
    void initIds(std::priority_queue<int, std::vector<int> > a);
    void addUser(user_dyh& user);
    std::unordered_map<std::string, user_dyh> showUserls() const;
    std::priority_queue<int, std::vector<int> >showIds() const;
};

#endif // FRIENDMANAGER_DYH_H
