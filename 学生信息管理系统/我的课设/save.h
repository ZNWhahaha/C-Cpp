void save(struct student *phead)//��ӱ���ѧ����Ϣ
{
	struct student *p;
	FILE *fp;
	if((fp=fopen("f:\\aa.txt","at+"))==NULL)
	{
		printf("�ļ���ʧ�ܣ�������Զ��˳�\n");
		Sleep(2000);
		exit(1);
	}
	for(p=phead->next;p!=NULL;p=p->next)
		fwrite(p,sizeof(struct student),1,fp);
	savecount();
	fclose(fp);
}