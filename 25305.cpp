#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N, k, score, i;
	vector<int> scoreList;
	cin >> N >> k;
	for (i = 0; i < N; i++)
	{
		cin >> score;
		scoreList.push_back(score);
	}
	sort(scoreList.begin(), scoreList.end());
	cout << scoreList[N - k];

	return 0;
}