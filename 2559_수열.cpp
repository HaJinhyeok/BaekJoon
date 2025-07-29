#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	int maxSum, currentSum = 0;
	cin >> N >> K;
	vector<int> temperature(N);
	for (int i = 0;i < N;i++)
	{
		cin >> temperature[i];
	}
	for (int i = 0;i < K;i++)
	{
		currentSum += temperature[i];
	}
	maxSum = currentSum;
	for (int i = K;i < N;i++)
	{
		currentSum -= temperature[i - K];
		currentSum += temperature[i];
		maxSum = currentSum > maxSum ? currentSum : maxSum;
	}

	cout << maxSum;
	return 0;
}