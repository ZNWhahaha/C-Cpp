#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define Up 0x48
#define Down 0x50
#define Left 0x4b
#define Right 0x4d
struct student// ѧ���ɼ���Ϣ
{
	char ID[10] ;
	char name[20];
	double score[3];
	double avg;
	struct student *next;
};
struct studentpassword//ѧ���˺���Ϣ
{
	char ID[10];
	char password[10];
	struct studentpassword *next; 
};
struct studentpassword *head;
struct student *phead=NULL;
int count=0; //  ѧ��������
#include "gotoxy.h"
#include "byebye.h"
#include "welcome.h"
#include "Delete.h"
#include "print.h"
#include "find.h"
#include "excellent.h"
#include "fail.h"
#include "sort.h"
#include "revise.h"
#include "savecount.h"
#include "saveother.h"
#include "save.h"
#include "readcount.h"
#include "read.h"
#include "statistics.h"
#include "look.h"
#include "add.h"
#include "adminpassword.h"
#include "adminmenu.h"
#include "studentpassword.h"
#include "landadmin.h"
#include "menu1.h"
main()
{
	welcome();
	menu1();
}