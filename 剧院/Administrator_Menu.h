//
//  Administrator_Menu.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/31.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Administrator_Menu_h
#define Administrator_Menu_h

#include"Include_All.h"

int Administrator_Menu(User *user){
    int i = 0;
    printf("\t\t\t\t\t——————————————————————————————————\n");
    printf("\t\t\t\t\t\t管理员:%s\n",user->User_username);
    printf("\t\t\t\t\t\t权限等级:%d\n",user->User_permission);
    printf("\t\t\t\t\t——————————————————————————————————\n");
    if (user->User_permission == 0) {
        printf("\t\t\t\t\t您是最高级root管理员，有权限进行如下操作\n");
        printf("\t\t\t\t\t——————————————————————————————————\n");
        printf("\t\t\t\t\t\tNo1:管理员账户增加\n");
        printf("\t\t\t\t\t\tNo2:管理员账户修改(包括自己)\n");
        printf("\t\t\t\t\t\tNo3:普通管理员账户删除\n");
        printf("\t\t\t\t\t\tNo4:查看所有管理员账户\n");
        i = 4;
    }
    else{
        printf("\t\t\t\t\t您是普通管理员，有权限进行如下操作\n");
    }
    printf("\t\t\t\t\t——————————————————————————————————\n");
    printf("\t\t\t\t\t\tNo%d:上架影片\n",++i);
    printf("\t\t\t\t\t\tNo%d:修改已上架影片信息\n",++i);
    printf("\t\t\t\t\t\tNo%d:删除已上架影片\n",++i);
    printf("\t\t\t\t\t\tNo%d:查看影片售出情况\n",++i);
    printf("\t\t\t\t\t\tNo%d:注销登录并回到主菜单\n",++i);
    printf("\t\t\t\t\t\tNo%d:直接退出\n",++i);
    printf("\t\t\t\t\t——————————————————————————————————\n");
    printf("\t\t\t\t\t");
    int t;
    scanf("%d",&t);
    if (user->User_permission == 1) {
        t = t+4;
    }
    switch(t) {
        case 1:
            Add_Administrator(user);
            break;
        case 2:
            Mod_Administrator(user);
            break;
        case 3:
            Del_Administrator(user);
            break;
        case 4:
            Look_Administrator(user);
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            Menu();
            break;
        case 10:
            
            break;
    }
    return 0;
}

#endif /* Administrator_Menu_h */
