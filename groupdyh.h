#ifndef GROUPDYH_H
#define GROUPDYH_H
#include "global.h"

class groupDYH
{
public:
    //群名
    QString group_name;
    //群号
    QString group_number;


    userDYH** members;
    groupDYH();
};

#endif // GROUPDYH_H
