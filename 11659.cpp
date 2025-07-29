#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, i, j, nEnter;
	vector<int> mySum;
	cin >> N >> M;
	// 누적 합 Sn을 구하기
	// Sj-Si
	mySum.push_back(0);
	for (int k = 0; k < N; k++)
	{
		cin >> nEnter;
		mySum.push_back(mySum[k] + nEnter);
	}
	while (M--)
	{
		cin >> i >> j;
		cout << mySum[j] - mySum[i - 1] << '\n';
	}
	return 0;
}