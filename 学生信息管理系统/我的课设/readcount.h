void readcount()//��ȡѧ������
{
	FILE *fp;
	fp=fopen("f:\\bb.txt","rt");
	fscanf(fp,"%d",&count);
	fclose(fp);
}