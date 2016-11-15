#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<io.h>
#define LEN 100
main()
{	FILE *fp;
	char filename[LEN], data[LEN], temp[LEN];
	int fno, fsize, i;
	char ch;
	printf("写文件程序...\n");
	printf("请输入要打开文件的完整路径及文件名：");
	gets(filename);
	fp=fopen(filename,"a+");
	if(fp==NULL)
	{	printf("\n打开文件失败，%s可能不存在\n",filename);
		exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n%s文件打开！\n",fsize);
	printf("\n文件内容为：");
	while((fgets(temp,LEN,fp))!=NULL)
		printf("%s",temp);
	while(1)
	{	printf("\n\n请问是否要添加数据(Y/N):");
		if(toupper(getchar())=='Y')
		{	printf("\n\n请输入要添加的数据：");
			gets(data);
			fputs(data,fp);
		}
		else
		{	fclose(fp);
			break;
		}
	}
	fp=fopen(filename,"r");
	if(fp==NULL)
	{	printf("\n\n打开文件失败，%s可能不存在\n",filename);
		exit(1);
	} 
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n\n%s文件打开！\n", filename);
	printf("\n文件大小 %d Bytes\n", fsize);
	printf("\n文件内容为：");
	while((fgets(temp,LEN,fp))!=NULL)
		printf("%s", temp);
	fclose(fp);
	printf("\n\n"); 
} 
