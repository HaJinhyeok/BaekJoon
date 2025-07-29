#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int enter, left, right;
	int i, j, k, max;
	cin >> enter;
	for (i = 0; i < enter; i++)
	{
		cin >> left >> right;
		vector<int> myVec(right - left + 1, 0);
		max = 1;
		for (j = left; j <= right; j++)
		{
			for (k = 1; k * k <= j; k++)
			{
				if (j % k == 0)
				{
					myVec[j - left] += 2;
					if (k * k == j)
					{
						myVec[j - left] -= 1;
					}
				}
			}
		}
		for (j = 0; j < right - left + 1; j++)
		{
			max = (max < myVec[j]) ? myVec[j] : max;
		}
		cout << max << '\n';
	}

	return 0;
}