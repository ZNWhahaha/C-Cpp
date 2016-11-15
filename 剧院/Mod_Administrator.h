//
//  Mod_Administrator.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/31.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Mod_Administrator_h
#define Mod_Administrator_h
#include"Include_All.h"

int Mod_Administrator(User *Admini){
    char temp_name[15];
    printf("\t\t\t\t\t          修改管理员信息\n");
    printf("\t\t\t\t\t——————————————————————————————————\n");
    printf("\t\t\t\t\t\t请输入想要修改的管理员的账号:");
    scanf("%s",temp_name);
    User *user,*user_head;
    user = user_head = Open_File_User();
    while (user) {
        if (strcmp(user->User_username, temp_name) == 0) {
            printf("\t\t\t\t\t——————————————————————————————————\n");
            printf("\t\t\t\t\t\t  管理员信息如下:\n");
            printf("\t\t\t\t\t\t管理员账号:%s\n",user->User_username);
            printf("\t\t\t\t\t\t管理员密码:%s\n",user->User_userpass);
            printf("\t\t\t\t\t——————————————————————————————————\n");
            printf("\t\t\t\t\t\t请输入重置后账号:");
            scanf("%s",user->User_username);
            printf("\t\t\t\t\t\t请输入重置后密码:");
            scanf("%s",user->User_userpass);
            FILE *fp;
            fp = fopen("UserInfo.bat","wb+");
            while(user_head){
                fwrite(user_head, sizeof(User), 1, fp);
                user_head = user_head->next;
            }
            fclose(fp);
            printf("\t\t\t\t\t\t修改成功!");
            return 0;
        }
        user = user->next;
    }
    printf("\t\t\t\t\t\t没有找到此管理员！");
    Back_In_Ad(Admini);
    return 0;
}

#endif /* Mod_Administrator_h */
