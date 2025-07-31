#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsExist(vector<int>& pq, int target)
{
	int left = 0;
	int right = pq.size() - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
 		if (pq[mid] == target)
		{
			return true;
		}
		else if (pq[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M, enter;
	vector<int> numbers;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> enter;
		numbers.push_back(enter);
	}
	sort(numbers.begin(), numbers.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> enter;
		if (IsExist(numbers, enter))
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}

	return 0;
}