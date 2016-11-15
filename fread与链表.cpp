struct stu{ 
	int num;                 /*学号*/ 
	char name[10];           /*名字*/ 
	char clas[10];           /*班级*/ 
	float score[5];          /*五类学分*/ 
    struct stu *next;         
}; 
int n;      /*全局变量 用于计算链表节点数*/ 
 
struct stu *read()                                                   /*读取*/ 
{ 
	struct stu A; 
	struct stu *P; 
	int i=1; 
	FILE *FP; 
	if((FP=fopen("F:\\XX.in","rb"))==NULL) 
	{ 
		printf("\t无已存数据！\n"); 
		printf("\t按任意键返回主菜单...\n"); 
		i=0; 
		head=NULL; 
		P=NULL; 
		getch(); 
	} 
	if(i) 
	   {     
		   fseek(FP,0,0); 
		   fread(&A,LEN,1,FP); 
			head=&A; 
			P=head; 
		} 
	n=0; 
	while(P!=NULL) 
	{ 
		P=P->next; 
		n++; 
	} 
	return(head); 
	 
} 

FP=fopen("F:\\XX.in","wb+");                    /*将数据以二进制形式储存便于下次读取*/ 
	P=head; 
	while(P!=NULL) 
	{ 
	   fwrite(P,LEN,1,FP); 
		P=P->next; 
	} 
	fclose(FP); 
	printf("                            \n"); 
	printf("                            \n"); 
	printf("\t保存成功！\n"); 
	printf("\t按任意键返回主菜单...\n"); 
	getchar(); 
	system("cls"); 
}
