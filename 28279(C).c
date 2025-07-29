#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define Data int

//1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100, 000)
//2 X : 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100, 000)
//3 : 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
//4 : 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
//5 : 덱에 들어있는 정수의 개수를 출력한다.
//6 : 덱이 비어있으면 1, 아니면 0을 출력한다.
//7 : 덱에 정수가 있다면 맨 앞의 정수를 출력한다.없다면 - 1을 대신 출력한다.
//8 : 덱에 정수가 있다면 맨 뒤의 정수를 출력한다.없다면 - 1을 대신 출력한다.

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
	getchar(); // 버퍼 비우기용

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