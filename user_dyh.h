#ifndef USER_DYH_H
#define USER_DYH_H

#include <string>
#include <vector>

class user_dyh
{
private:
    std::string id;                      //用户id
    std::string nickname;               //昵称
    std::string brithday;               //出生日期
    std::string registrationTime;       //注册时间
    std::string location;               //所在地

    std::vector<std::string> friends;   //好友列表
    std::vector<std::string> groups;     //群列表
public:
    user_dyh();
    user_dyh(std::string id,std::string nickname,std::string brithday,std::string regTime,std::string location);
    ~user_dyh();

    std::string getId() const;
    void setNickName(const std::string& newName);

    void addFriend(const std::string& friendId);
    void delFriend(const std::string& friendId);

    void joinGroup(const std::string& GroupId);
    void leaveGroup(const std::string& GroupId);
};

namespace std {
template<>
struct hash<user_dyh>
{
    std::size_t operator()(const user_dyh& user)
        const{
        return hash<std::string>()(user.getId());
    }
};
}

#endif // USER_DYH_H
