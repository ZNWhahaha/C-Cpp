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



//测试代码，不用理会
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
					printf("数组排序错误！\n");
				EXIT;
			}
		}
		if (count == 2)
			printf("数组排序正确！\n");
	}
	void testListInsert() {
		U* head = _list.head;
		for (head = _list.head; head != NULL; head = head->next)
			curSize++;
		if (curSize != size) {
			printf("链表插入错误!\n");
#ifdef DEBUG
			printf("实际插入数据数量:%d \n应该插入数据数量:%d\n", curSize, size);
#endif
			EXIT;
		}
		printf("链表插入正确！\n");
	}
	void testListSort() {
		U* lt;
		for (lt = _list.head; lt != _list.tail; lt = lt->next) {
			if (lt->data > lt->next->data) {
				printf("链表排序错误\n");
				EXIT;
			}
		}
		printf("链表排序正确!\n");
	}
	void testRmEvenNum() {
		U* lt;
		for (lt = _list.head; lt != NULL; lt = lt->next)
		if (lt->data % 2 == 0) {
			printf("删除偶数错误！\n");
			EXIT;
		}
		printf("删除偶数正确!\n");
	}
	void testDestroy() {
		if (_list.head != NULL || _list.tail != NULL) {
			printf("删除链表错误！\n");
			EXIT;
		}
		printf("删除链表正确");
	}
};












//以下为面试代码
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
	任务一： 编写冒泡排序算法（升序）。
	对数组key，从 [begin, end) 范围内的数，进行排序
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
	任务二： 编写链表插入函数；
	功能： 将数据data插入到list中，每次都插入到尾端（需动态申请内存）
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
	任务三：编写函数对链表进行排序（升序，使用选择排序）
	功能： 对list中存储的数据进行排序，
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
	任务四： 编写函数打印链表中的数据
	功能： 将链表中储存的数据依次打印，显示在屏幕上
	*/
}


void findAndRemove(List* list) {
	/*
	任务五：编写函数删除链表中的偶数
	功能： 删除list中存储的所有偶数
	*/
}


void destroy(List* list) {
	/*
	任务六： 编写析构链表函数：
	功能： 将链表中的所有节点释放掉
	*/
}




int main() {
	const int arraySize = 100;
	const int mid = arraySize / 2;
	int key[arraySize], i;
	List testList;
	testList.head = NULL; //链表头指针初始化
	testList.tail = NULL; //链表尾指针初始化
	srand(time(NULL));

	for (i = 0; i<arraySize; i++) {//随机生成100个数，范围为0~1000
		key[i] = rand() * 17 % 10000;
	}

	TestList<List, ListNode> TL(testList, key, arraySize);  //测试类不用理会

	/*
	对数组key中的数分两次使用冒泡排序，每次排序完成就插入到链表中
	*/
	bubbleSort(key, 0, mid);                //对前一半个数进行冒泡排序
	TL.testArraySort(key, 0, mid);          //对排序结果进行测试

	for (i = 0; i<mid; i++)                   //将排序好的数逐个插入到链表中
		insertData(&testList, key[i]);

	bubbleSort(key, mid, arraySize);        //对数组剩下一半的数进行排序
	TL.testArraySort(key, mid, arraySize);  //对排序结果测试

	for (i = mid; i<arraySize; i++)           //将排序好的数逐个插入到链表中
		insertData(&testList, key[i]);
	TL.testListInsert();                    //测试链表插入

	selectionSort(&testList);               //对链表中的数进行排序
	TL.testListSort();                      //测试链表排序

	printf("\n\n打印链表：\n");
	printList(&testList);                   //打印链表中的数据

	findAndRemove(&testList);               //删除链表中所有偶数
	TL.testRmEvenNum();                     //测试删除结果

	destroy(&testList);                     //释放链表中的数据
	TL.testDestroy();                       //测试析构结果

	return 0;
}



