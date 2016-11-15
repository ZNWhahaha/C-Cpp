//
//  Back_In_Ad.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/31.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Back_In_Ad_h
#define Back_In_Ad_h
#include"Include_All.h"

void Back_In_Ad(User *Admini){
    int i;
    printf("\n\t\t\t\t\t输入1返回管理员%s的菜单,输入其他退出:",Admini->User_username);
    scanf("%d",&i);
    if (i == 1) {
        Administrator_Menu(Admini);
    }
    else exit(1);

}

#endif /* Back_In_Ad_h */
