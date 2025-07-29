#include<iostream>
#include<deque>
#define MAX 100001
using namespace std;

int isQ[MAX] = { 0, };

int main()
{
	int N, bQS, data, M, i;
	cin >> N;
	deque<int> myDeq;
	for (i = 1; i <= N; i++)
	{
		cin >> bQS;
		if (bQS == 0)
		{
			isQ[i] = 1;
		}
	}
	for (i = 1; i <= N; i++)
	{
		cin >> data;
		if (isQ[i] == 1) myDeq.push_front(data);
	}
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> data;
		myDeq.push_back(data);
	}
	for (i = 0; i < M; i++)
	{
		cout << myDeq[i] << ' ';
	}

	return 0;
}