#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �켱 �����ϰ�, ���� ª�� ����(==1)�� ���� ū ������ mid ������ ����
// �ش� ���̷� ������ �� ������ left=mid+1�� �ؼ� �ٽ� mid ���� ����
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