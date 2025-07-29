#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Data int

//1 X: ���� X�� ���� �տ� �ִ´�. (1 �� X �� 100, 000)
//2 X : ���� X�� ���� �ڿ� �ִ´�. (1 �� X �� 100, 000)
//3 : ���� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�.
//4 : ���� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�.
//5 : ���� ����ִ� ������ ������ ����Ѵ�.
//6 : ���� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
//7 : ���� ������ �ִٸ� �� ���� ������ ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�.
//8 : ���� ������ �ִٸ� �� ���� ������ ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�.

typedef struct _node{
	Data data;
	struct _node* front;
	struct _node* back;
}NODE;

typedef struct {
	NODE* head;
	NODE* tail;
	unsigned int sizeOfDeque;
}MYDEQUE;

void pushFront(MYDEQUE* myDeq, const int num);
void pushBack(MYDEQUE* myDeq, const int num);
int popFront(MYDEQUE* myDeq);
int popBack(MYDEQUE* myDeq);

int main()
{
	int numOfOrder;
	char myEnter[10];
	char* toInt;
	MYDEQUE pDeq;
	pDeq.sizeOfDeque = 0;
	pDeq.head = NULL;
	pDeq.tail = NULL;

	scanf("%d", &numOfOrder);
	getchar(); // ���� �����

	for (int i = 0; i < numOfOrder; i++)
	{
		gets(myEnter);
		switch (myEnter[0])
		{
		case '1':
			toInt = &(myEnter[2]);
			pushFront(&pDeq, atoi(toInt));
			break;
		case '2':
			toInt = &(myEnter[2]);
			pushBack(&pDeq, atoi(toInt));
			break;
		case '3':
			printf("%d\n", popFront(&pDeq));
			break;
		case '4':
			printf("%d\n", popBack(&pDeq));
			break;
		case '5':
			printf("%d\n", pDeq.sizeOfDeque);
			break;
		case '6':
			if (pDeq.sizeOfDeque == 0) printf("1\n");
			else printf("0\n");
			break;
		case '7':
			if (pDeq.sizeOfDeque == 0) printf("-1\n");
			else printf("%d\n", pDeq.head->data);
			break;
		case '8':
			if (pDeq.sizeOfDeque == 0) printf("-1\n");
			else printf("%d\n", pDeq.tail->data);
			break;
		default:
			break;
		}
	}
	return 0;
}
void pushFront(MYDEQUE* myDeq, const int num)
{
	NODE* tmp = (NODE*)malloc(sizeof(NODE));
	tmp.data = num;
	myDeq->sizeOfDeque++;
}
void pushBack(MYDEQUE* myDeq, const int num)
{
	
	myDeq->sizeOfDeque++;
}
int popFront(MYDEQUE* myDeq)
{
	if (myDeq->sizeOfDeque == 0)	return-1;
	int result;
	myDeq->sizeOfDeque--;

	return result;
}
int popBack(MYDEQUE* myDeq)
{
	if (myDeq->sizeOfDeque == 0)	return -1;
	int result;
	myDeq->sizeOfDeque--;

	return result;
}