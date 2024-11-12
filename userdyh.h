#ifndef USERDYH_H
#define USERDYH_H
#include "global.h"
class userDYH
{
public:
    //id
    QString user_name;
    //账号
    QString user_number;
    //出生时间
    QDate birthday;
    //注册时间
    QDate sign_up_time;
    //住址
    QString location;
    //好友
    userDYH** friend_list;

    userDYH();
};

#endif // USERDYH_H
