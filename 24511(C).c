#pragma warning(disable: 4996)
#include<stdio.h>
#include<malloc.h>

typedef struct
{
	// 0이면 큐, 1이면 스택
	int QorS;
	int data;
}QueueStack;
int InsertPop(QueueStack* qs, int givenData)
{
	int result;
	if (!qs->QorS) // 큐이면
	{
		result = qs->data;
		qs->data = givenData;
	}
	else
	{
		result = givenData;
	}
	return result;
}
int main()
{
	// ㅅㅂ 진짜 구현하면 시간초과나니까 진짜 구현하는게 아니라 단순화시켜야하는거였네
	// 걍 C++로 짜련다 ㅅㄱ
	int N, M, i, j, givenData;
	scanf("%d", &N);
	QueueStack* qsList = (QueueStack*)malloc(N * sizeof(QueueStack));
	for (i = 0; i < N; i++) scanf("%d", &qsList[i].QorS);
	for (i = 0; i < N; i++) scanf("%d", &qsList[i].data);

	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d", &givenData);
		for (j = 0; j < N; j++)
		{
			givenData = InsertPop(&qsList[j], givenData);
		}
		printf("%d ", givenData);
	}

	return 0;
}