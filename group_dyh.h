#ifndef GROUP_DYH_H
#define GROUP_DYH_H
#include<string>
#include<vector>

class group_dyh {
  private:
    std::string groupId;
    std::string groupOnwer;
    std::vector <std::string> members;

  public:
    group_dyh();
    std::string getId() const;
    bool isOwner(const std::string userid);
    void addmember(const std::string& userid);
    void delmember(const std::string& userid);
};

class QQGroup_dyh: public group_dyh {
  private:
    std::vector<std::string> admins;


  public:
    QQGroup_dyh() {}
    bool isAdmin(const std::string userid);
    void addAdmin(const std::string userid);
    void delAdmin(const std::string userid);
};

class WeChatGroup_dyh: public group_dyh {
  private:

  public:
    WeChatGroup_dyh() {}
    void recommendAdd(const std::string userid);
};


namespace std {
    template<>
    struct hash<group_dyh> {
        std::size_t operator()(const group_dyh& group) {
            return hash<std::string>()(group.getId());
        }
    };
}

#endif // GROUP_DYH_H
