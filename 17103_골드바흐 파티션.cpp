#include<iostream>
#define MAX 1000000

using namespace std;

bool isPrime[MAX + 1];

unsigned int GoldbachPartition(bool isPrime[], int N)
{
	unsigned int numOfPartition = 0;
	for (int i = 2; i <= N / 2; i++)
	{
		if (isPrime[i])
		{
			if (isPrime[N - i]) numOfPartition++;
		}
	}

	return numOfPartition;
}

int main()
{
	int Test, N, i, j;
	fill_n(isPrime, MAX + 1, true);

	// 에라토스테네스의 체
	for (i = 2; i <= MAX; i++)
	{
		if (!isPrime[i]) continue;
		for (j = i * 2; j <= MAX; j += i) isPrime[j] = false;
	}

	cin >> Test;
	while (Test--)
	{
		cin >> N;
		cout << GoldbachPartition(isPrime, N) << '\n';
	}
	return 0;
}