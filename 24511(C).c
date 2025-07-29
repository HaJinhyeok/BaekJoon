#pragma warning(disable: 4996)
#include<stdio.h>
#include<malloc.h>

typedef struct
{
	// 0�̸� ť, 1�̸� ����
	int QorS;
	int data;
}QueueStack;
int InsertPop(QueueStack* qs, int givenData)
{
	int result;
	if (!qs->QorS) // ť�̸�
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
	// ���� ��¥ �����ϸ� �ð��ʰ����ϱ� ��¥ �����ϴ°� �ƴ϶� �ܼ�ȭ���Ѿ��ϴ°ſ���
	// �� C++�� ¥�ô� ����
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