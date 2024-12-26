#ifndef GROUP_DYH_H
#define GROUP_DYH_H
#include<string>
#include<vector>
#include"json.hpp"

using json = nlohmann::json;

class group_dyh {
  protected:
    std::string groupId;
    std::string groupOwner;
    std::vector <std::string> members;

  public:
    group_dyh();
    std::string getId() const;
    std::string getOwner() const;

    void setID(const std::string&);
    void setOwner(const std::string&);

    std::vector<std::string>& givemembers();

    bool isOwner(const std::string& userid);
    void addmember(const std::string& userid);
    void delmember(const std::string& userid);

    virtual json toJson() const = 0;
    virtual void fromJson(const json& j) = 0;
};

class QQGroup_dyh: public group_dyh {
  private:
    std::vector<std::string> admins;


  public:
    QQGroup_dyh() {}
    bool isAdmin(const std::string userid);
    void addAdmin(const std::string userid);
    void delAdmin(const std::string userid);
    json toJson() const override;
    void fromJson(const json& j) override;
};

class WeChatGroup_dyh: public group_dyh {
  private:

  public:
    WeChatGroup_dyh() {}
    json toJson() const override;
    void fromJson(const json& j) override;
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
