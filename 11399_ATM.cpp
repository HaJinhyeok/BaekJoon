#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, i;
	cin >> N;
	vector<int> takeOut(N);
	for (i = 0; i < N; i++)
	{
		cin >> takeOut[i];
	}
	sort(takeOut.begin(), takeOut.end());
	for (i = 0; i < N; i++)
	{
		if (i != 0) takeOut[i] += takeOut[i - 1];
	}
	for (i = 0; i < N; i++)
	{
		if (i != 0) takeOut[i] += takeOut[i - 1];
	}
	cout << takeOut[N - 1];
	return 0;
}