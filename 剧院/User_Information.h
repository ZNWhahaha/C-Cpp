//
//  User_Information.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/30.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef User_Information_h
#define User_Information_h
//#include <stdio.h>

typedef struct User_Information {
    char User_username[15];
    char User_userpass[15];
    int User_permission;
    struct User_Information *next;
}User;


#endif /* User_Information_h */
