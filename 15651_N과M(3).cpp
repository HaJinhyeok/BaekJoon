#include <iostream>
#include <vector>

using namespace std;

int trackingList[8];

void BackTracking(int N, int M, int depth);

int main()
{
	int N, M;
	int depth = 0;
	cin >> N >> M;
	BackTracking(N, M, depth);
	return 0;
}

void BackTracking(int N, int M, int depth)
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
		for (int i = 0; i < N; i++)
		{
			trackingList[depth] = i + 1;
			depth++;
			BackTracking(N, M, depth);
			depth--;
		}
	}
}