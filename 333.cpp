#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

struct ListNode {
	int data;
	ListNode* next;
};

struct List {
	ListNode* head;
	ListNode* tail;
};



//���Դ��룬�������
#include <vector>
#include <list>
using namespace std;

#undef DEBUG

template <class T, class U>
class TestList {
public:
#define EXIT return
	//#define EXIT exit(1)

private:
	T& _list;
	vector<int> _vct;
	const int size;
	int curSize;

public:
	TestList(T& l, int a[], const int s) :_list(l), size(s), curSize(0) {
		int i;
		for (i = 0; i<size; i++) {
			_vct.push_back(a[i]);
		}
	}
	void testArraySort(int a[], int begin, int end) {
		vector<int> tmp;
		static int count = 0;
		count++;
		int i, size = end - begin;
		for (i = begin; i<end; i++)
			tmp.push_back(a[i]);
		sort(tmp.begin(), tmp.end());
		for (i = 0; i<size; i++) {
			if (tmp[i] != a[i + begin]) {
				if (count == 2)
					printf("�����������\n");
				EXIT;
			}
		}
		if (count == 2)
			printf("����������ȷ��\n");
	}
	void testListInsert() {
		U* head = _list.head;
		for (head = _list.head; head != NULL; head = head->next)
			curSize++;
		if (curSize != size) {
			printf("����������!\n");
#ifdef DEBUG
			printf("ʵ�ʲ�����������:%d \nӦ�ò�����������:%d\n", curSize, size);
#endif
			EXIT;
		}
		printf("���������ȷ��\n");
	}
	void testListSort() {
		U* lt;
		for (lt = _list.head; lt != _list.tail; lt = lt->next) {
			if (lt->data > lt->next->data) {
				printf("�����������\n");
				EXIT;
			}
		}
		printf("����������ȷ!\n");
	}
	void testRmEvenNum() {
		U* lt;
		for (lt = _list.head; lt != NULL; lt = lt->next)
		if (lt->data % 2 == 0) {
			printf("ɾ��ż������\n");
			EXIT;
		}
		printf("ɾ��ż����ȷ!\n");
	}
	void testDestroy() {
		if (_list.head != NULL || _list.tail != NULL) {
			printf("ɾ���������\n");
			EXIT;
		}
		printf("ɾ��������ȷ");
	}
};












//����Ϊ���Դ���
/*
struct ListNode {
int data;
ListNode* next;
};

struct List {
ListNode* head;
ListNode* tail;
};

*/

void bubbleSort(int key[], int begin, int end)
{
	/*
	����һ�� ��дð�������㷨�����򣩡�
	������key���� [begin, end) ��Χ�ڵ�������������
	*/
	int i,j,t;
	for(i=begin;i<=end-1;i++)
	{	for(j=begin;j<=end-1-i;j++)
			if(key[i]>key[j])
			{	t=key[i];
				key[i]=key[j];
				key[j]=t;	
			}
	}
}


void insertData(List* list, int data) {
	/*
	������� ��д������뺯����
	���ܣ� ������data���뵽list�У�ÿ�ζ����뵽β�ˣ��趯̬�����ڴ棩
	*/
	struct ListNode *x;
	x=(struct ListNode *)malloc(sizeof(struct ListNode));
	x->data=data;
	x->next=NULL;
	list->tail->next=x;
	list->tail=x;
	free(x);
}


void selectionSort(ListNode *head) {
	/*
	����������д���������������������ʹ��ѡ������
	���ܣ� ��list�д洢�����ݽ�������
	*/
	struct ListNode *t,*i,*j;
	for(i=head;i!=NULL;i=i->next)
	{	for(j=head;j!=NULL;j=j->next)
		{	if((i->data)>(j->data))
			{	t=i->next;
				i->next=j->next;
				j->next=t;
			}
		}
	}
}


void printList(List* list) {
	/*
	�����ģ� ��д������ӡ�����е�����
	���ܣ� �������д�����������δ�ӡ����ʾ����Ļ��
	*/
}


void findAndRemove(List* list) {
	/*
	�����壺��д����ɾ�������е�ż��
	���ܣ� ɾ��list�д洢������ż��
	*/
}


void destroy(List* list) {
	/*
	�������� ��д������������
	���ܣ� �������е����нڵ��ͷŵ�
	*/
}




int main() {
	const int arraySize = 100;
	const int mid = arraySize / 2;
	int key[arraySize], i;
	List testList;
	testList.head = NULL; //����ͷָ���ʼ��
	testList.tail = NULL; //����βָ���ʼ��
	srand(time(NULL));

	for (i = 0; i<arraySize; i++) {//�������100��������ΧΪ0~1000
		key[i] = rand() * 17 % 10000;
	}

	TestList<List, ListNode> TL(testList, key, arraySize);  //�����಻�����

	/*
	������key�е���������ʹ��ð������ÿ��������ɾͲ��뵽������
	*/
	bubbleSort(key, 0, mid);                //��ǰһ���������ð������
	TL.testArraySort(key, 0, mid);          //�����������в���

	for (i = 0; i<mid; i++)                   //������õ���������뵽������
		insertData(&testList, key[i]);

	bubbleSort(key, mid, arraySize);        //������ʣ��һ�������������
	TL.testArraySort(key, mid, arraySize);  //������������

	for (i = mid; i<arraySize; i++)           //������õ���������뵽������
		insertData(&testList, key[i]);
	TL.testListInsert();                    //�����������

	selectionSort(&testList);               //�������е�����������
	TL.testListSort();                      //������������

	printf("\n\n��ӡ����\n");
	printList(&testList);                   //��ӡ�����е�����

	findAndRemove(&testList);               //ɾ������������ż��
	TL.testRmEvenNum();                     //����ɾ�����

	destroy(&testList);                     //�ͷ������е�����
	TL.testDestroy();                       //�����������

	return 0;
}



