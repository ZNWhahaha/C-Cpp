struct student *revise(struct student *phead)//修改学生信息
{
	struct student *p;
	FILE *fp;
	int flag,line=20,row=6,x=0;
	double s1;
	char b[20],a[10];
	system("cls");
    gotoxy(15,3);
	printf("===============================================");
	gotoxy(15,4);
	printf("|");
	gotoxy(61,4);
	printf("|");
	gotoxy(30,5);
	printf("ID:");
	gotoxy(15,5);
	printf("|");
	gotoxy(61,5);
	printf("|");
	gotoxy(15,6);
	printf("|");
	gotoxy(61,6);
	printf("|");
	gotoxy(30,6);
	printf("姓名:");
	gotoxy(15,7);
	printf("|");
	gotoxy(61,7);
	printf("|");
	gotoxy(30,7);
	printf("成绩:");
	gotoxy(15,8);
	printf("===============================================");
	gotoxy(35,5);
	scanf("%s",a);
	for(p=phead->next;p!=NULL;p=p->next)
		if(strcmp(p->ID,a)==0)
			 break;
	if(p!=NULL)
	{
		while(1)
		{
			system("cls");
			gotoxy(15,3);
			printf("===============================================");
			gotoxy(15,4);
			printf("|");
			gotoxy(61,4);
			printf("|");
			gotoxy(22,5);
			printf("ID:");
			gotoxy(28,5);
			printf("%s",p->ID);
			gotoxy(15,5);
			printf("|");
			gotoxy(61,5);
			printf("|");
			gotoxy(22,6);
			printf("姓名:");
			gotoxy(28,6);
			printf("%s",p->name);
			gotoxy(22,7);
			printf("语文:%lf",p->score[0]);
			gotoxy(22,8);
			printf("数学:%lf",p->score[1]);
			gotoxy(22,9);
			printf("英语:%lf",p->score[2]);
			gotoxy(15,8);
			printf("|");
			gotoxy(61,8);
			printf("|");
			gotoxy(15,9);
			printf("|");
			gotoxy(61,9);
			printf("|");
			gotoxy(15,10);
			printf("|");
			gotoxy(61,10);
			printf("|");
			gotoxy(15,6);
			printf("|");
			gotoxy(61,6);
			printf("|");
			gotoxy(15,7);
			printf("|");
			gotoxy(61,7);
			printf("|");
			gotoxy(15,11);
			printf("===============================================");
			gotoxy(28,1);
			printf("★用方向键控制光标★");
			gotoxy(line,row);
			putch(16);
			flag=getch();
			if(flag==Up)
			{
				row=row-1;
				if(row==5)
					row=9;
			}
			else if(flag==Down)
			{
				row=row+1;
				if(row==10)
					row=6;
			}
			if(flag==13)
			{
				if(line==20&&row==6)
				{
					gotoxy(27,6);
					printf("                ");
					gotoxy(27,6);
					scanf("%s",b);
					strcpy(p->name,b);
				}
				else if(line==20&&row==7)
				{
					gotoxy(27,7);
					printf("                ");
	    			gotoxy(27,7);
					scanf("%lf",&s1);
					p->score[0]=s1;
				}
				else if(line==20&&row==8)
				{
					gotoxy(27,8);
					printf("               ");
	    			gotoxy(27,8);
					scanf("%lf",&s1);
					p->score[1]=s1;
				}
				else if(line==20&&row==9)
				{
					gotoxy(27,9);
					printf("               ");
	    			gotoxy(27,9);
					scanf("%lf",&s1);
					p->score[2]=s1;
				}
				p->avg=(p->score[0]+p->score[1]+p->score[2])/3.0;
				break;
			}
		}
	}
		if(p==NULL)
		{
			gotoxy(30,9);
			printf("对不起没有找到该同学");
		}
	if((fp=fopen("f:\\aa.txt","wt"))==NULL)
	{
		printf("文件打开失败，两秒后自动退出\n");
		Sleep(2000);
		exit(1);
	}
	for(p=phead->next;p!=NULL;p=p->next)
		fwrite(p,sizeof(struct student),1,fp);
	fclose(fp);
	gotoxy(30,12);
	printf("按任意键返回主菜单\n");
	getch();
	return phead;
}