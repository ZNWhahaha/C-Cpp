//
//  Del_Administrator.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/31.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Del_Administrator_h
#define Del_Administrator_h
#include"Include_All.h"
void Del_Administrator(User *Admini){
    User *user,*user_head;
    char del_name[15];
    user = user_head = Open_File_User();
    printf("\t\t\t\t\t——————————————————————————————————\n");
    printf("\t\t\t\t\t\t输入要删除的管理员账号:");
    scanf("%s",del_name);
    while (user->next) {
        if (strcmp(user->next->User_username, del_name) == 0) {
            printf("\t\t\t\t\t——————————————————————————————————\n");
            printf("\t\t\t\t\t\t  管理员信息如下:\n");
            printf("\t\t\t\t\t\t管理员账号:%s\n",user->next->User_username);
            printf("\t\t\t\t\t\t管理员密码:%s\n",user->next->User_userpass);
            printf("\t\t\t\t\t——————————————————————————————————\n");
            printf("\t\t\t\t\t\t确认删除？(1/0):");
            int choose;
            scanf("%d",&choose);
            if (choose == 1) {
                user->next = user->next->next;
                printf("\t\t\t\t\t\t删除成功!");
                FILE *fp;
                fp = fopen("UserInfo.bat","wb+");
                while(user_head){
                    fwrite(user_head, sizeof(User), 1, fp);
                    user_head = user_head->next;
                }
                fclose(fp);

                Back_In_Ad(Admini);
            }
            else{
                printf("\t\t\t\t\t\t取消成功!");
                Back_In_Ad(Admini);
            }
        }
        user = user->next;
    }
    printf("\n\t\t\t\t\t\t没有找到此管理员!");
    Back_In_Ad(Admini);
}

#endif /* Del_Administrator_h */
