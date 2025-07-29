#include <iostream>
#include <vector>

using namespace std;

int trackingList[9];

void BackTracking(int N, int M, int depth, vector<bool>& isChecked);

int main()
{
	int N, M;
	int depth = 0;
	cin >> N >> M;
	vector<bool> isChecked(N + 1);
	BackTracking(N, M, depth, isChecked);
	return 0;
}


void BackTracking(int N, int M, int depth, vector<bool>& isChecked)
{
	if (depth == M)
	{
		for (int i = 1; i <= M; i++)
		{
			cout << trackingList[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		int size = isChecked.size();
		for (int i = depth + 1; i < size; i++)
		{
			// 오름차순이어야하기 때문에 크기 비교 필요
			if (!isChecked[i] && trackingList[depth] < i)
			{
				trackingList[++depth] = i;
				isChecked[i] = true;
				BackTracking(N, M, depth, isChecked);
				depth--;
				isChecked[i] = false;
			}
		}
	}
}