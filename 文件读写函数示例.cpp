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
	printf("д�ļ�����...\n");
	printf("������Ҫ���ļ�������·�����ļ�����");
	gets(filename);
	fp=fopen(filename,"a+");
	if(fp==NULL)
	{	printf("\n���ļ�ʧ�ܣ�%s���ܲ�����\n",filename);
		exit(1);
	}
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n%s�ļ��򿪣�\n",fsize);
	printf("\n�ļ�����Ϊ��");
	while((fgets(temp,LEN,fp))!=NULL)
		printf("%s",temp);
	while(1)
	{	printf("\n\n�����Ƿ�Ҫ�������(Y/N):");
		if(toupper(getchar())=='Y')
		{	printf("\n\n������Ҫ��ӵ����ݣ�");
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
	{	printf("\n\n���ļ�ʧ�ܣ�%s���ܲ�����\n",filename);
		exit(1);
	} 
	fno=fileno(fp);
	fsize=filelength(fno);
	printf("\n\n%s�ļ��򿪣�\n", filename);
	printf("\n�ļ���С %d Bytes\n", fsize);
	printf("\n�ļ�����Ϊ��");
	while((fgets(temp,LEN,fp))!=NULL)
		printf("%s", temp);
	fclose(fp);
	printf("\n\n"); 
} 
