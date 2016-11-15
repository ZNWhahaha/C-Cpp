//
//  Add_Administrator.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/31.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Add_Administrator_h
#define Add_Administrator_h
#include "Include_All.h"

int Add_Administrator(User *Admini){
    User *user;
    char temp[15];
    user = (User *)malloc(sizeof(User));
    printf("\t\t\t\t\t\t\t增加管理员\n");
    printf("\t\t\t\t\t\t管理员账号:");
    scanf("%s",user->User_username);
loop:    printf("\t\t\t\t\t\t管理员密码:");
    scanf("%s",user->User_userpass);
    printf("\t\t\t\t\t\t确认密码:");
    scanf("%s",temp);
    if (strcmp(user->User_userpass, temp) == 0) {
        user->User_permission = 1;
        Save_User_Information(user);
        printf("\t\t\t\t\t\t  增加成功\n");
    }
    else{
        printf("\t\t\t\t\t\t密码不一致!请重试!\n");
        goto loop;
    }
    Back_In_Ad(Admini);
    return 0;
}

#endif /* Add_Administrator_h */
