#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>

typedef struct _node
{
	struct _node* prev;
	struct _node* next;
	int numInBalloon;
	int numOfBalloon;
}NODE;

typedef struct
{
	// head tail 없애고 current node만 가리켜도 가능할듯
	// 처음 풍선 N개 연결할 땐 current 뒤에 하나 붙이고 붙인 걸 current로 지정해주는 식으로
	NODE* currentBalloon;
	unsigned int sizeOfDeque;
}CircularDeque;

int main()
{
	CircularDeque myDeq;
	myDeq.currentBalloon = NULL;
	myDeq.sizeOfDeque = 0;

	int N, i, data, count;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &data);
		NODE* tmp = (NODE*)malloc(sizeof(NODE));
		tmp->numInBalloon = data;
		tmp->numOfBalloon = i + 1;

		// 첫 풍선 넣을 때
		if (myDeq.sizeOfDeque == 0)
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			myDeq.currentBalloon = tmp;
		}
		else 
		{
			tmp->prev = myDeq.currentBalloon;
			tmp->next = myDeq.currentBalloon->next;
			myDeq.currentBalloon->next = tmp;
			myDeq.currentBalloon->next->prev = tmp;
			myDeq.currentBalloon = tmp;
		}
		myDeq.sizeOfDeque++;
	}

	count = myDeq.currentBalloon->numInBalloon;

	while (myDeq.sizeOfDeque != 0)
	{
		NODE* popBalloon = myDeq.currentBalloon;
		// 마지막 풍선 터뜨릴 때
		if (myDeq.sizeOfDeque == 1)
		{
			myDeq.currentBalloon = NULL;
		}
		else
		{
			myDeq.currentBalloon->prev->next = myDeq.currentBalloon->next;
			myDeq.currentBalloon->next->prev = myDeq.currentBalloon->prev;
			if (count > 0)
			{
				for (i = 0; i < count; i++)
				{
					myDeq.currentBalloon = myDeq.currentBalloon->next;
				}
			}
			else
			{
				for (i = 0; i > count; i--)
				{
					myDeq.currentBalloon = myDeq.currentBalloon->prev;
				}
			}
			count = myDeq.currentBalloon->numInBalloon;
		}
		printf("%d", popBalloon->numOfBalloon);
		free(popBalloon);
	}

	return 0;
}
// font: dejavu sans mono