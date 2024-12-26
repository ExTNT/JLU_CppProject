#ifndef USER_DYH_H
#define USER_DYH_H

#include <string>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class user_dyh {
  protected:
    std::string id;                      //用户id
    std::string password;                //密码
    std::string nickname;                //昵称
    std::string brithday;                //出生日期
    std::string registrationTime;        //注册时间
    std::string location;                //所在地

    std::vector<std::string> friends;    //好友列表
    std::vector<std::string> groups;     //群列表
  public:
    user_dyh();
    user_dyh(std::string id, std::string nickname, std::string brithday, std::string regTime, std::string location, std::string password);
    ~user_dyh();

    std::string getId() const;
    std::vector<std::string> getFrds() const;
    std::vector<std::string> getGrps() const;
    std::string getPassword() const;
    const std::string getNickname() const;
    std::string getBirth() const;
    std::string getReg() const;
    std::string getLocal() const;

    std::vector<std::string>& giveFrds();
    std::vector<std::string>& giveGrps();

    void setNickName(const std::string& newName);
    void setPassword(const std::string& newPswd);
    //void setRegsTime(const std::string& regTime);
    void setBirthday(const std::string& newBirth);
    void setLocation(const std::string& newLocal);

    void addFriend(const std::string& friendId);
    void delFriend(const std::string& friendId);

    void creatGroup();
    void delGroup();
    void joinGroup(const std::string& GroupId);
    void leaveGroup(const std::string& GroupId);

    //序列化json
    virtual json toJson() const;
    //从json反序列化
    virtual void fromJson(const json& j);

};

class vxUser_dyh: public user_dyh {
  private:
    std::string linkQQ;         //qqid
  public:
    vxUser_dyh() {};
    vxUser_dyh(std::string id, std::string nickname, std::string brithday, std::string regTime, std::string location, std::string password);
    json toJson () const override;
    void fromJson(const json& j) override;
    void linkToQQ(const std::string qqid);
    std::string& giveQQ();
};

namespace std {
    template<>
    struct hash<user_dyh> {
        std::size_t operator()(const user_dyh& user)
        const {
            return hash<std::string>()(user.getId());
        }
    };
}

#endif // USER_DYH_H
