//
//  Menu.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/30.
//  Copyright © 2016年 杨帆. All rights reserved.
//


#include "Include_All.h"
int Menu(){
    printf("\t\t\t\t\t\t   没人来大剧院\n\n");
    printf("\t\t\t\t\t\t————————————————\n");
    printf("\t\t\t\t\t\tNo1：管理员登陆\n");
    printf("\t\t\t\t\t\tNo2：游客身份登陆\n");
    printf("\t\t\t\t\t\tNO3：退出\n");
    printf("\t\t\t\t\t\t————————————————\n");
    printf("\t\t\t\t\t\t");
    int i;
    scanf("%d",&i);
    switch(i){
        case 1:Administrator_Login();break;
        case 2:break;
        case 3:exit(0);
    }
    return 0;
}

