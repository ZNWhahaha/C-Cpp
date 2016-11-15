#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	char num[10];
	char name[20];
	int  score[3];
	int grades;
	struct student *next;
};
typedef struct student DATE;
void Menu(){
	
	printf("*************************��ӭ����ѧ���ɼ�����ϵͳ*************************\n\n\n");
	printf("                      1---ѧ����Ϣ���ݵ�¼��\n");
	printf("                      2---��ʾ���е�ѧ����Ϣ\n");
	printf("                      3---ѧ����Ϣ����׷��\n");
	printf("                      4---ѧ����Ϣ�����޸�\n");
	printf("                      5---ѧ����Ϣ����ɾ��\n");
	printf("                      6---ѧ����Ϣ���ݲ�ѯ\n");
	printf("                      0---�˳�ϵͳ\n"); 
	printf("\n\n\n***************************************************************************");
	printf("\n����0-6��ѡ���Իس�������\n");
}
int icount;
DATE *Creat(){	
	FILE *fp;						//ѧ��������Ϣ¼�� 
	DATE *head=NULL;
	DATE *p1,*p2;
	char filename[50];
	int i,sum=0;
	printf("д�ļ�����......\n");
	printf("������Ҫ���ļ�������·�����ļ���:");
	scanf("%s",filename);
	fp=fopen(filename,"wt");
	if(fp==NULL){
		printf("\n�ļ���ʧ�ܣ�%s���ܲ�����\n",filename);
	//	getch();
		exit(0);
	}
	p1=p2=(DATE *)malloc(sizeof(DATE));
	icount=0;
	printf("������ѧ������Ϣ(�������ѧ��ѧ��Ϊ'#',��ֹͣ����,�����س���ѡ����������)��\n");
	printf("������ѧ����ѧ�ţ�");
	scanf("%s",p1->num);
	do{
		icount++;
		printf("\n������ѧ����������");
		scanf("%s",p1->name);
		printf("��ֱ�����ѧ���ĸ�����Ӣ�������ɼ���");
		sum=0;
		for(i=0;i<3;i++){
			scanf("%d",&p1->score[i]);
			sum+=p1->score[i];
		} 
		p1->grades=sum; 
		printf("ѧ���ɼ��ܷ֣�%d\n",p1->grades);
		if(icount==1){
			p1->next=head;
			p2=p1;
		}
		else{
			p1->next=NULL;
			p2->next=p1;
			p2=p1;
		}
		fprintf(fp,"%s %s %d %d %d %d",p1->num,p1->name,p1->score[0],p1->score[1],p1->score[2],p1->grades);
//		fwrite(p1,sizeof(DATE),1,fp);
		p1=(DATE *)malloc(sizeof(DATE));
		printf("������ѧ����ѧ�ţ�");
		scanf("%s",p1->num);
	}while(strcmp("#\0",p1->num));
	fclose(fp);
	free(p1);
	return(head); 
} 
DATE *Print(){								//��ѧ����Ϣ���ļ���ȡ�����浽������ 
	DATE *pt,*head=NULL,*pi;
	FILE *fp;
	pt=pi=(DATE *)malloc(sizeof(DATE));
	fp=fopen("students_information.txt","rt");
	if(fp==NULL){
		printf("\n�ļ���ʧ�ܣ�student_information.txt���ܲ�����\n");
	//	getch();
		exit(0);
	}
	int n=0,i;	
	head=pt;
	pt->next=NULL;
	while(fscanf(fp,"%s %s %d %d %d %d",pt->num,pt->name,&pt->score[0],&pt->score[1],&pt->score[2],&pt->grades)!=EOF){
		n++;
		pi=pt;
		pt=(DATE *)malloc(sizeof(DATE));
		pi->next=pt;
		pt->next=NULL;
	}
	fclose(fp);
	return (head);
}
void Input(){							//��ʾ����ѧ����������Ϣ 
	DATE *p,*phead;
	phead=Print();
	p=phead;
	while(p!=NULL){
		printf("ѧ�ţ�%s",p->num);
		printf("������%s",p->name);
		printf("������Ӣ��������%d\t%d\t%d\t",p->score[0],p->score[1],p->score[2]);
		printf("�ܷ֣�%d",p->grades);
		p=p->next;
	}
}
Add(){								//ѧ��������Ϣ��׷�� 
	
	
	
	
}
Change(){							//ѧ��������Ϣ�޸� 
	
	
	
	
	
}
Delete(){							//ѧ��������Ϣɾ�� 
	
	
	
	
	
}
Search(){							//ѧ��������Ϣ��ѯ 
	
	
	
	
	
} 
main(){
	int choice;
	DATE *phead;
	Menu();
	scanf("%d",&choice);
	do{
		switch(choice){
			case 1:phead=Creat();	break;
			case 2:Input();	break;
			case 3:Add();	break;
			case 4:Change();break;
			case 5:Delete();break;
			case 6:Search();break;
			case 0:         break;
		}
		printf("�Ƿ��������,�����Ҫ�˳�ϵͳ����ѡ��'0'�������س���\n");
		printf("��ѡ��");
		scanf("%d",&choice); 	
	}while(choice!=0);
}
