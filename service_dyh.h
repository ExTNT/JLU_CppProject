#ifndef SERVICE_DYH_H
#define SERVICE_DYH_H

#include <string>

class Service_dyh
{
protected:
    std::string serviceName;        //服务名称
    bool isActive;                  //是否工作
    bool isRegist;                  //是否开通

public:
    Service_dyh(const std::string& name):serviceName(name),isActive(false),isRegist(false){}
    virtual ~Service_dyh();
    virtual void login()=0;         //登录功能
    virtual void logout()=0;        //登出功能
};

class QQService_dyh:public Service_dyh
{
public:
    QQService_dyh():Service_dyh("QQ"){}
    void login() override;
    void logout() override;
};

class WeChatService_dyh:public Service_dyh
{
public:
    WeChatService_dyh():Service_dyh("WeChat"){}
    void login() override;
    void logout() override;
};

#endif // SERVICE_DYH_H
