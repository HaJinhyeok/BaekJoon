#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
	int K, N, result = 1;
	cin >> K >> N;
	vector<ll> lines(K);
	for (int i = 0;i < K;i++)
	{
		cin >> lines[i];
	}
	sort(lines.begin(), lines.end());
	ll left = 1, right = lines[K - 1];
	ll mid;
	int count = 0;
	while (left <= right)
	{
		count = 0;
		mid = (left + right) / 2;
		for (int i = 0;i < K;i++)
		{
			count += lines[i] / mid;
			if (count >= N)
			{
				result = mid;
				left = mid + 1;
				break;
			}
		}
		if (count < N)
		{
			right = mid - 1;
		}
		else
		{
			result = mid;
			left = mid + 1;		
		}
	}
	cout << result;

	return 0;
}