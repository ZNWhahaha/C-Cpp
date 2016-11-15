void savecount()//保存学生个数
{
	FILE *fp;
	fp=fopen("f:\\bb.txt","wt");
	fprintf(fp,"%d",count);
	fclose(fp);
}