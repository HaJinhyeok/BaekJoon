#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	int N, M, enter;
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		vector<int> first(N);
		vector<int> second(M);
		int countDuple = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> enter;
			first[i] = enter;
		}
		for (int j = 0; j < M; j++)
		{
			cin >> enter;
			second[j] = enter;
		}
		int sk = 0, sy = 0;
		while (sk < N && sy < M)
		{
			if (first[sk] == second[sy])
			{
				countDuple++;
				sk++;
				sy++;
			}
			else if (first[sk] > second[sy])
			{
				sy++;
			}
			else
			{
				sk++;
			}
		}

		cout << countDuple << '\n';
	}
	return 0;
}