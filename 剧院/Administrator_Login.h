//
//  Administrator_Login.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/30.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Administrator_Login_h
#define Administrator_Login_h

#include "Include_All.h"
int Administrator_Login(){
    User *user;
    int i = 0;
    char username[15],userpass[15];
    user = Open_File_User();
    if (user == NULL){
        printf("\t\t\t\t\t当前系统未初始化管理，请进行初始化并设置最高管理员。\n");
        Administrator_Registe();
    }
    else{
        printf("\t\t\t\t             登陆界面\n");
        printf("\t\t\t\t         帐号:");
        scanf("%s",username);
    loop:  printf("\t\t\t\t         密码:");
        scanf("%s",userpass);
    }
    while (user) {
        if (strcmp(user->User_username,username) == 0) {
            if (strcmp(user->User_userpass, userpass) == 0) {
                printf("\t\t\t\t\t\t登陆成功\n");
                Administrator_Menu(user);
                return 0;
            }
            else{
                printf("\t\t\t\t\t\t密码错误 (%d/3)\n",i+1);
                i++;
                if(i == 3) exit(0);
                else goto loop;
                return 0;
            }
        }
        else
            user = user->next;
    }
    printf("\t\t\t\t\t\t没有找到此用户\n");
    return 0;
}

#endif /* Administrator_Login_h */
