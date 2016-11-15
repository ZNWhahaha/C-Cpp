struct studentpassword *adminpassword()//注册学生账号
{
	struct studentpassword *pnew,*head=NULL,*p,*h,*q,*t;
	int s,x;
	FILE *fp,*fp1;
	fp1=fopen("f:\\studentpassword.txt","rt");  //读取账号信息
	h=(struct studentpassword*)malloc(sizeof(struct studentpassword));
	h->next=NULL;
	while(!feof(fp1))
	{
		q=(struct studentpassword*)malloc(sizeof(struct studentpassword));
		fscanf(fp1,"%s %s ",q->ID,q->password);
		q->next=h->next;
		h->next=q;
	}
	fclose(fp1);
	system("cls");
	pnew=(struct studentpassword*)malloc(sizeof(struct studentpassword));
	system("cls");
    gotoxy(15,3);
	printf("===============================================");
	gotoxy(15,4);
	printf("|");
	gotoxy(61,4);
	printf("|");
	gotoxy(28,5);
	printf("请注册学生账号");
	gotoxy(15,5);
	printf("|");
	gotoxy(61,5);
	printf("|");
	gotoxy(28,7);
	printf("请输入ID<8位>:");
	gotoxy(15,6);
	printf("|");
	gotoxy(61,6);
	printf("|");
	gotoxy(28,9);
	printf("请输入密码<6位>:");
	gotoxy(15,7);
	printf("|");
	gotoxy(61,7);
	printf("|");
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
	gotoxy(15,11);
	printf("|");
	gotoxy(61,11);
	printf("|");
	gotoxy(15,12);
	printf("|");
	gotoxy(61,12);
	printf("|");
	gotoxy(15,13);
	printf("|");
	gotoxy(61,13);
	printf("|");
	gotoxy(15,14);
    printf("===============================================");
	while(1)
	{
	   gotoxy(42,7);
	   scanf("%s",pnew->ID);
	   x=strlen(pnew->ID);
	   if(x!=8)
	   {
           gotoxy(40,8);
		   printf("该账号不符合要求");
		   gotoxy(42,7);
		   printf("                   ");
	   }
	   else
	   {
		   for(t=h->next;t!=NULL;t=t->next)
		   {
			   if(strcmp(t->ID,pnew->ID)==0)
			   {
				   gotoxy(40,8);
				   printf("该账号已存在!"); 
				   gotoxy(42,7);
				   printf("              ");
				   break;
			   }
		   }
		   if(t==NULL)
			   break; 
	   }
	}
	while(1)
	{  
       gotoxy(35,8);
	   printf("                    ");
	   gotoxy(44,9);
	   scanf("%s",pnew->password);
	   s=strlen(pnew->password);
	   if(s!=6)
	   {
		   gotoxy(28,11);
		   printf("密码不满足规定长度，请重新输入");
		   gotoxy(44,9);
		   printf("                              ");
	   }
	   else
		   break;
	}
	pnew->next=NULL;
	head=pnew;
	fp=fopen("f:\\studentpassword.txt","at+"); //追加账号信息 
	for(p=head;p!=NULL;p=p->next)
	   fprintf(fp,"%s %s ",p->ID,p->password);
	gotoxy(28,11);
	printf("                            ");
	gotoxy(32,13);
    printf("注册成功\n");
	fclose(fp);
	gotoxy(28,16);
	printf("按任意键返回主菜单\n");
	getch();
	return head;
}