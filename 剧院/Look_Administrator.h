//
//  Look_Administrator.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/31.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Look_Administrator_h
#define Look_Administrator_h
#include"Include_All.h"
void Look_Administrator(User *Admini){
    User *user;
    int i = 0;
    user = Open_File_User();
    while (user) {
        printf("\t\t\t\t\t——————————————————————————————————\n");
        printf("\t\t\t\t\t\t  第%d个管理员:\n",++i);
        printf("\t\t\t\t\t\t账号:%s\n",user->User_username);
        printf("\t\t\t\t\t\t密码:%s\n",user->User_userpass);
        printf("\t\t\t\t\t\t权限等级:%d\n",user->User_permission);
        user = user->next;
    }
    Back_In_Ad(Admini);
}

#endif /* Look_Administrator_h */
