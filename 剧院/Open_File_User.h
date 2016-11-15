//
//  Open_File_User.h
//  剧场票务管理系统
//
//  Created by 杨帆 on 16/5/30.
//  Copyright © 2016年 杨帆. All rights reserved.
//

#ifndef Open_File_User_h
#define Open_File_User_h

#include "Include_All.h"
User *Open_File_User(){
    User *Head = NULL;
    User *New,*End;
    FILE *fp;
    if((fp = fopen("UserInfo.bat", "rb")) == NULL ){
        return Head;
    }
    fseek(fp, 0, SEEK_SET);
    New = End = (User *)malloc(sizeof(User));
    fread(New, sizeof(User), 1, fp);
    while(feof(fp) == 0){
        if (Head == NULL) {
            Head = New;
            End = New;
            New->next = NULL;
        }
        else{
            End->next = New;
            End = New;
        }
        New = (User *)malloc(sizeof(User));
        fread(New, sizeof(User), 1, fp);
    }
    free(New);
    fclose(fp);
    return Head;
}


#endif /* Open_File_User_h */
