//
//  Administrator_Registe.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/30.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Administrator_Registe_h
#define Administrator_Registe_h


#include "Include_All.h"

int Administrator_Registe(){
    User *user;
    char temp[15];
    user = (User *)malloc(sizeof(User));
    printf("\t\t\t\t\t\t   系统初始化\n\n");
    printf("\t\t\t\t\t\t————————————————\n");
    printf("\n\t\t\t\t\t\t帐号:");
    scanf("%s",user->User_username);
    printf("\n\t\t\t\t\t\t密码:");
    scanf("%s",user->User_userpass);
    printf("\n\t\t\t\t\t\t请确认密码:");
    scanf("%s",temp);
    if (strcmp(user->User_userpass, temp) == 0) {
        user->User_permission = 0;
        user->next = NULL;
        Save_User_Information(user);
        printf("\n\t\t\t\t\t\t初始化成功");
    }
    return 0;
}

#endif /* Administrator_Registe_h */
