void savecount()//����ѧ������
{
	FILE *fp;
	fp=fopen("f:\\bb.txt","wt");
	fprintf(fp,"%d",count);
	fclose(fp);
}