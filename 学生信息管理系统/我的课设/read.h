struct student *read()// 读取学生信息
{
	int i;
	struct student *p,*h;
	FILE *fp;
	if((fp=fopen("f:\\aa.txt","rt"))==NULL)
	{
		printf("文件打开失败，两秒后自动退出\n");
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