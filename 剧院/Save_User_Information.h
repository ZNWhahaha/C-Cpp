//
//  Save_User_Information.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/30.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Save_User_Information_h
#define Save_User_Information_h
#include "Include_All.h"
int Save_User_Information(User *user){
    FILE *fp;
    fp = fopen("UserInfo.bat", "ab+");
    fwrite(user, sizeof(User), 1, fp);
    fclose(fp);
    return 0;
}

#endif /* Save_User_Information_h */
