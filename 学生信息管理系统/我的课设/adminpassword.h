struct studentpassword *adminpassword()//ע��ѧ���˺�
{
	struct studentpassword *pnew,*head=NULL,*p,*h,*q,*t;
	int s,x;
	FILE *fp,*fp1;
	fp1=fopen("f:\\studentpassword.txt","rt");  //��ȡ�˺���Ϣ
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
	printf("��ע��ѧ���˺�");
	gotoxy(15,5);
	printf("|");
	gotoxy(61,5);
	printf("|");
	gotoxy(28,7);
	printf("������ID<8λ>:");
	gotoxy(15,6);
	printf("|");
	gotoxy(61,6);
	printf("|");
	gotoxy(28,9);
	printf("����������<6λ>:");
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
		   printf("���˺Ų�����Ҫ��");
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
				   printf("���˺��Ѵ���!"); 
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
		   printf("���벻����涨���ȣ�����������");
		   gotoxy(44,9);
		   printf("                              ");
	   }
	   else
		   break;
	}
	pnew->next=NULL;
	head=pnew;
	fp=fopen("f:\\studentpassword.txt","at+"); //׷���˺���Ϣ 
	for(p=head;p!=NULL;p=p->next)
	   fprintf(fp,"%s %s ",p->ID,p->password);
	gotoxy(28,11);
	printf("                            ");
	gotoxy(32,13);
    printf("ע��ɹ�\n");
	fclose(fp);
	gotoxy(28,16);
	printf("��������������˵�\n");
	getch();
	return head;
}