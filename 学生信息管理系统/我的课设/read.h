struct student *read()// ��ȡѧ����Ϣ
{
	int i;
	struct student *p,*h;
	FILE *fp;
	if((fp=fopen("f:\\aa.txt","rt"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�������Զ��˳�\n");
		Sleep(2000);
		exit(1);
	}
	h=(struct student *)malloc(sizeof(struct student));
	h->next=NULL;
	readcount();
	for(i=0;i<count;i++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		fread(p,sizeof(struct student),1,fp);
	    p->next=h->next;
		h->next=p;
	}
	fclose(fp);
	return h;
}