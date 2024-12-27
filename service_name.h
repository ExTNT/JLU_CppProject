#ifndef SERVICE_NAME_H
#define SERVICE_NAME_H

#include <string>

class Service_name
{
protected:
  std::string serviceName; // 服务名称
  bool isActive;           // 是否工作

public:
  Service_name() = default;
  Service_name(const std::string &name) : serviceName(name), isActive(false) {}
  ~Service_name() = default;
  virtual bool login(const std::string, const std::string) = 0; // 登录功能
  virtual void logout() = 0;                                    // 登出功能
  virtual void ActService() = 0;
};

class QQService_name : public Service_name
{
public:
  QQService_name() : Service_name("QQ") {}
  bool login(const std::string, const std::string) override;
  void logout() override;
  void ActService() override;
};

class WeChatService_name : public Service_name
{
public:
  WeChatService_name() : Service_name("WeChat") {}
  bool login(const std::string, const std::string) override;
  void logout() override;
  void ActService() override;
};

class WeiBoService_name : public Service_name
{
public:
  WeiBoService_name() : Service_name("WeiBo") {}
  bool login(const std::string, const std::string) override;
  void logout() override;
  void ActService() override;
};

#endif // SERVICE_NAME_H
