void readcount()//读取学生个数
{
	FILE *fp;
	fp=fopen("f:\\bb.txt","rt");
	fscanf(fp,"%d",&count);
	fclose(fp);
}