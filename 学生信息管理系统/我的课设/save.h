void save(struct student *phead)//添加保存学生信息
{
	struct student *p;
	FILE *fp;
	if((fp=fopen("f:\\aa.txt","at+"))==NULL)
	{
		printf("文件打开失败，两秒后自动退出\n");
		Sleep(2000);
		exit(1);
	}
	for(p=phead->next;p!=NULL;p=p->next)
		fwrite(p,sizeof(struct student),1,fp);
	savecount();
	fclose(fp);
}