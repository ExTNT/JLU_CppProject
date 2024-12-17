#ifndef GROUP_DYH_H
#define GROUP_DYH_H
#include<string>
#include<vector>

class group_dyh
{
private:
    std::string groupId;
    std::string groupName;
    std::vector <std::string> members;

public:
    group_dyh();
    std::string getId() const;
    void addmember(const std::string& userid);
    void delmember(const std::string& userid);
    bool ismember(const std::string& userid) const;
};

class QQGroup_dyh:public group_dyh
{
private:
    std::vector<std::string> admins;
    std::string groupOwner;

public:
    QQGroup_dyh() {}
    bool isOwner(const std::string userid);
    bool isAdmin(const std::string userid);
    void addAdmin(const std::string userid);
    void delAdmin(const std::string userid);
};

class WeChatGroup_dyh:public group_dyh
{
private:
    std::string groupOwner;

public:
    WeChatGroup_dyh() {}
    void recommendAdd(const std::string userid);
};


namespace std {
template<>
struct hash<group_dyh>
{
    std::size_t operator()(const group_dyh& group)
    {
        return hash<std::string>()(group.getId());
    }
};
}

#endif // GROUP_DYH_H
