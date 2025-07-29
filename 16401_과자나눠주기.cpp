#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 우선 정렬하고, 가장 짧은 길이(==1)와 가장 큰 길이의 mid 값부터 시작
// 해당 길이로 나눠줄 수 있으면 left=mid+1로 해서 다시 mid 길이 조사
int main()
{
	int M, N, stick;
	int left, right, mid, count, result = 0;
	vector<int> sticks;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> stick;
		sticks.push_back(stick);
	}
	sort(sticks.begin(), sticks.end());

	left = 1; right = sticks[N - 1];

	while (left <= right)
	{
		count = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < N; i++)
		{
			count += sticks[i] / mid;
			if (count >= M)
			{
				result = mid;
				left = mid + 1;
				break;
			}
		}
		if (count < M)
		{
			right = mid - 1;
		}
	}
	cout << result;

	return 0;
}