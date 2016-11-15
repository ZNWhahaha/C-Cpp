#include<stdio.h>
#define N 3
struct student{
	int num;
	char name[20];
	int major;
	int Class;
	int score[3];
}students[10];
void Input(struct student *p){

printf("请输入编号，姓名，专业编号，班级，三门成绩\n");
scanf("%d %s %d %d %d %d %d",&p->num,p->name,&p->major,&p->Class,&p->score[0],&p->score[1],&p->score[2]);
}
void Output(struct student *p)
{
  printf("%d  %s  %d  %d  %d  %d  %d\n",p->num,p->name,p->major,p->Class,p->score[0],p->score[1],p->score[2]);
}
void Save(struct student *p,int n)
{
	FILE *fp;
    int i;
	char filename[20];
	printf("请输入要保存的文件名\n");
	gets(filename);
	if((fp=fopen(filename,"wb"))==NULL)
{
		printf("cannot open the file\n");
		return;
};
	for(i=0;i<N;i++){
		if(fwrite(p++,sizeof(struct student),1,fp)!=1)
		printf("file write error\n");
	}
	fclose(fp);
}
struct student fetch(int n)
{
	struct student tem;
	FILE *fp;
	char filename[20];
	printf("请输入要打开的文件名\n");
	gets(filename);
	fp=fopen(filename,"rb");
	fseek(fp,sizeof(n*sizeof(struct student)),0);
	fread(&tem,sizeof(struct student),1,fp);
	fclose(fp);
	return tem;
}
void Max(){
	int i,j,k=0;
	struct student max;
	printf("请输入要查找的课程(0~2)\n");
	scanf("%d",&i);
	max=students[0];
	for(j=0;j<N;j++)
	{
		if(max.score[i]<students[j].score[i])
		{
		 max=students[j];
		 k=j;
		}
	}
	printf("%d课程的最高分是%f,最高分同学的姓名是%s\n",i,max.score[i],max.name);
	printf("\n");
}
void sort_select()
{
	int i,j=0,a=0,t,n;
	int k[N];
	printf("请输入专业编号\n");
	scanf("%d",&i);
	for(j=0;j<N;j++)
	{
		if(students[j].major==i)
		{
			k[a]=(students[j].score[0]+students[j].score[1]+students[j].score[2])/3;
			a++;
		}
	}
	for(i=0;i<a-1;i++)
	{
		n=i;
		for(j=i+1;j<a;j++)
		{if(k[j]<k[n])
		n=j;
		t=k[n];
		k[n]=k[i];
		k[i]=t;
		}
	}
	printf("排序后的结果为\n");
	for(i=0;i<a;i++)
		printf("%d",k[i]);
	printf("\n");
}
void sort_buble()
{
	int i,j=0,a=0,k[N],t;
	printf("请输入要查询的班级代号\n");
	scanf("%d",&i);
	for(j=0;j<N;j++)
	{
	 if(students[j].Class==i)
	 {
		 k[a]=(students[j].score[0]+students[j].score[1]+students[j].score[2])/3;
		 a++;
	 }
	}
	for(i=0;i<a-1;i++)
	 for(j=0;j<a-1-j;j++)
	  if(k[j]<k[j+1])
	  {
	  t=k[j+1];
	  k[j+1]=k[j];
	  k[j]=t;
}
for(i=0;i<a;i++)
printf("%d",k[i]);
printf("\n");
}
void sort_insert()
{
	int a,b[N],c=0,i,j,k,n;
	printf("请输入要排序的课程代号\n");
	scanf("%d",&i);
	printf("请输入要排序的班级代号\n");
	scanf("%d",&a);
	for(j=0;j<N;j++)
	{
		if(students[j].Class==a)
		{
			b[c]=students[j].score[i];
			c++;
		}
	}
	for(j=1;j<c;j++)
	 for(k=j;k>0;k--)
	if(b[k]<b[k-1])
	{
		n=b[k];
		b[k]=b[k-1];
		b[k-1]=n;
	}
	printf("排序后的结果为\n");
	for(j=0;j<c;j++)
	printf("%d",b[j]);
	printf("\n");
}
void Search()
{
 int i,j,k;
 printf("请输入要查询的班级代号\n");
 scanf("%d",&j);
 printf("请输入总分标准\n");
 scanf("%d",&k);
 for(i=0;i<N;i++)
 {
	 if(students[i].Class==j&&(students[i].score[0]+students[i].score[1]+students[i].score[2])>=k)
	 {
		 printf("%d%s%d%d%d\n",students[i].num,students[i].name,students[i].score[0],students[i].score[1],students[i].score[2]);
	 }
 }
}
main()
{
	int i,j,k;
	struct student tem;
	printf("\n请输入功能编号\n");
	while(1){
printf("1-输入信息;2-输出信息；3-文件保存;4-随机读取;5-求某门课程最高分及最高分姓名;6-专业平均成绩排序;7-班级平均成绩排序;8-班级某课程直接插入排序;9-综合查找\n");
 scanf("%d",&i);
        switch(i)
        {case 1:
            {for(j=0;j<N;j++)

            Input(students+j);
            break;
			}
		case 2:
			{getchar();
			for(j=0;j<N;j++)
				Output(students+j);
			break;
			}
        case 3:{
              getchar();
              Save(students,sizeof(struct student));
              break;
			   }
        case 4:
            {
                printf("请输入您想查看的学生的信息\n");
				scanf("%d",&k);
				getchar();
				tem=fetch(k-1);
				Output(&tem);
                break;
            }
        case 5:
            {

                Max();
                break;
            }       
		case 6:
			{
               sort_select();
                break;
			}
        case 7:
            {

                sort_buble();
                break;
            }
        case 8:
            {
                sort_insert();
                break;
            }
        case 9:
            {
                Search();
                break;
            }
        default:{
        break;
        }
    }

    if((i<1)||(i>9))
        break;
        }
}
