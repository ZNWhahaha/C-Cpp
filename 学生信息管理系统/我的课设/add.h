struct student *add(struct student *phead)//添加学生信息
{
	struct student *pnew;
	char a;
	int x;
	system("cls");
	gotoxy(20,2);
	printf("========================================");
	gotoxy(20,3);
	printf("|");
	gotoxy(59,3);
	printf("|");
	gotoxy(20,4);
	printf("|");
	gotoxy(59,4);
	printf("|");
	gotoxy(20,5);
	printf("|");
	gotoxy(59,5);
	printf("|");
	gotoxy(20,6);
	printf("|");
	gotoxy(59,6);
	printf("|");
	gotoxy(20,7);
	printf("|");
	gotoxy(59,7);
	printf("|");
	gotoxy(20,8);
	printf("|");
	gotoxy(59,8);
	printf("|");
	gotoxy(20,9);
	printf("|");
	gotoxy(59,9);
	printf("|");
	gotoxy(20,10);
	printf("|");
	gotoxy(59,10);
	printf("|");
	gotoxy(20,11);
	printf("|");
	gotoxy(59,11);
	printf("|");
	gotoxy(20,12);
	printf("|");
	gotoxy(59,12);
	printf("|");
	gotoxy(20,13);
	printf("|");
	gotoxy(59,13);
	printf("|");
	gotoxy(20,14);
	printf("|");
	gotoxy(59,14);
	printf("|");
	gotoxy(20,15);
	printf("|");
	gotoxy(59,15);
	printf("|");
	gotoxy(20,16);
	printf("========================================");
	phead=(struct student*)malloc(sizeof(struct student));
	phead->next=NULL;
	while(1)
	{
		pnew=(struct student*)malloc(sizeof(struct student));
		if(pnew!=NULL)
		{
			gotoxy(25,4);
			printf("请输入所添加的学生信息");
			gotoxy(28,6);
			printf("ID=");
			gotoxy(26,8);
			printf("姓名=");
			gotoxy(26,10);
			printf("语文=");
			gotoxy(26,12);
			printf("数学=");
			gotoxy(26,14);
			printf("英语=");
			gotoxy(31,6);
			printf("                ");
			gotoxy(31,8);
			printf("                ");
			gotoxy(31,10);
			printf("                ");
			gotoxy(31,12);
			printf("                ");
			gotoxy(31,14);
			printf("                ");
			while(1)
			{
				gotoxy(32,6);
				flushall();
				scanf("%s",pnew->ID);
				x=strlen(pnew->ID);
				if(x==8)
				{
					gotoxy(48,6);
					printf("            ");
					break;
				}
				else
				{
					gotoxy(48,6);
					printf("ID不符合要求");
					gotoxy(32,6);
			        printf("                ");
				}
			}
			gotoxy(31,8);
            scanf("%s",pnew->name);
			gotoxy(31,10);
            scanf("%lf",&pnew->score[0]);
			gotoxy(31,12);
            scanf("%lf",&pnew->score[1]);
			gotoxy(31,14);
            scanf("%lf",&pnew->score[2]);
			pnew->avg=(pnew->score[0]+pnew->score[1]+pnew->score[2])/3.0;
			pnew->next=phead->next;
			phead->next=pnew;
			count++;
		}
		gotoxy(22,18);
		printf("是否想继续添加？<y,n>\n");
		gotoxy(45,18);
		flushall();
		a=getchar();
		if(a=='n')
		   break;
		else
		{
			gotoxy(45,18);
		    printf(" ");
		}
	}
	gotoxy(18,20);
	printf("添加成功！按任意键返回主菜单");
	getch();
	return phead;
}