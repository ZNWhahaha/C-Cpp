struct stu{ 
	int num;                 /*ѧ��*/ 
	char name[10];           /*����*/ 
	char clas[10];           /*�༶*/ 
	float score[5];          /*����ѧ��*/ 
    struct stu *next;         
}; 
int n;      /*ȫ�ֱ��� ���ڼ�������ڵ���*/ 
 
struct stu *read()                                                   /*��ȡ*/ 
{ 
	struct stu A; 
	struct stu *P; 
	int i=1; 
	FILE *FP; 
	if((FP=fopen("F:\\XX.in","rb"))==NULL) 
	{ 
		printf("\t���Ѵ����ݣ�\n"); 
		printf("\t��������������˵�...\n"); 
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

FP=fopen("F:\\XX.in","wb+");                    /*�������Զ�������ʽ��������´ζ�ȡ*/ 
	P=head; 
	while(P!=NULL) 
	{ 
	   fwrite(P,LEN,1,FP); 
		P=P->next; 
	} 
	fclose(FP); 
	printf("                            \n"); 
	printf("                            \n"); 
	printf("\t����ɹ���\n"); 
	printf("\t��������������˵�...\n"); 
	getchar(); 
	system("cls"); 
}
