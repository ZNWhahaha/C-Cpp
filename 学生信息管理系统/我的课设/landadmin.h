landadmin()// 管理员登录
{
	char a[7],b[7],c[20];
	int i=0,k=0,t,j,y=0,n=1;
	int line=33,row=10;
	FILE *fp;
	fp=fopen("f:\\adminpassword.txt","rt");
	fscanf(fp,"%s",a);
	fclose(fp);
	system("cls");
	gotoxy(15,3);
	printf("===========================================");
	gotoxy(15,15);
    printf("===========================================");
	gotoxy(15,4);
	printf("|");
	gotoxy(57,4);
	printf("|");
	gotoxy(15,5);
	printf("|");
	gotoxy(57,5);
	printf("|");
	gotoxy(15,6);
	printf("|");
	gotoxy(57,6);
	printf("|");
	gotoxy(15,7);
	printf("|");
	gotoxy(57,7);
	printf("|");
	gotoxy(15,8);
	printf("|");
	gotoxy(57,8);
	printf("|");
	gotoxy(15,9);
	printf("|");
	gotoxy(57,9);
	printf("|");
	gotoxy(15,10);
	printf("|");
	gotoxy(57,10);
	printf("|");
	gotoxy(15,11);
	printf("|");
	gotoxy(57,11);
	printf("|");
	gotoxy(15,12);
	printf("|");
	gotoxy(57,12);
	printf("|");
	gotoxy(15,13);
	printf("|");
	gotoxy(57,13);
	printf("|");
	gotoxy(15,14);
	printf("|");
	gotoxy(57,14);
	printf("|");
	gotoxy(27,8);
	printf("管理员：admin");
	gotoxy(27,10);
	printf("密码：");
	gotoxy(line,row);
	while(1)
	{
		flushall();
		while((c[i]=getch())!='\r')//i为输入密码位数 k为星号个数
		{
			if(i==0&&c[i]=='\b')
				c[0]='\0';
			else if(i>0&&c[i]=='\b')
			{
				printf("\b \b");
				i--;
				k--;
			}
			else if(k<7)
			{
				printf("*");
				k++;
				i++;
			}
		}
		c[i]='\0';
		t=strlen(c);
		for(j=0;j<6;j++)
			b[j]=c[j];
		b[j]='\0';
		if(t==6&&strcmp(a,b)==0)
		{
			gotoxy(24,12);
			printf("                         ");
			gotoxy(28,12);
			printf("登录成功");
			n=0;
			break;
		}
		else 
		{
			y++;
			if(y<3)
			{
				gotoxy(24,12);
				printf("                     ");
				gotoxy(24,12);
				printf("密码错误，请再次输入!");
				i=0;
				k=0;
				gotoxy(line,row);
				printf("                     ");
				gotoxy(line,row);
			}
			else if(y==3)
			{
				gotoxy(23,12);
				printf("                       ");
				gotoxy(23,12);
				printf("错误次数超过三次，退出!");
				n=1;
				break;
			}
		}
		if(n==0)
		   break;
	}
Sleep(2000);
if(n==0)
    adminmenu();
}
