#include <iostream>
#include <vector>

using namespace std;

int trackingList[8];

void BackTracking(int N, int M, int depth, vector<bool>& isChecked);

int main()
{
	int N, M;
	int depth = 0;
	cin >> N >> M;
	vector<bool> isChecked(N);
	BackTracking(N, M, depth, isChecked);
	return 0;
}

void BackTracking(int N, int M, int depth, vector<bool>& isChecked)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << trackingList[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		int size = isChecked.size();
		for (int i = 0; i < size; i++)
		{
			if (!isChecked[i])
			{
				trackingList[depth] = i + 1;
				isChecked[i] = true;
				depth++;
				BackTracking(N, M, depth, isChecked);
				depth--;
				isChecked[i] = false;
			}
		}
	}
}