#ifndef SERVICE_DYH_H
#define SERVICE_DYH_H

#include <string>

class Service_dyh {
  protected:
    std::string serviceName;        //服务名称
    bool isActive;                  //是否工作

  public:
    Service_dyh() = default;
    Service_dyh(const std::string& name): serviceName(name), isActive(false) {}
    ~Service_dyh() = default;
    virtual bool login(const std::string, const std::string) = 0;      //登录功能
    virtual void logout() = 0;      //登出功能
    virtual void ActService() = 0;
};

class QQService_dyh: public Service_dyh {
  public:
    QQService_dyh(): Service_dyh("QQ") {}
    bool login(const std::string, const std::string) override;
    void logout() override;
    void ActService() override;
};

class WeChatService_dyh: public Service_dyh {
  public:
    WeChatService_dyh(): Service_dyh("WeChat") {}
    bool login(const std::string, const std::string) override;
    void logout() override;
    void ActService() override;
};

class WeiBoService_dyh: public Service_dyh {
  public:
    WeiBoService_dyh(): Service_dyh("WeiBo") {}
    bool login(const std::string, const std::string) override;
    void logout() override;
    void ActService() override;
};

#endif // SERVICE_DYH_H
