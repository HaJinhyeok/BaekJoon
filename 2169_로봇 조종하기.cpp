#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> area(N, vector<int>(M));
	// (i, j) 칸에 대해, 왼쪽에서 오는 경우 / 위에서 내려온 경우 / 오른쪽에서 온 경우
	// 바텀업
	// 좌스캔 우스캔 -> 좌에서 우로 한 번 보내고,
	// 우에서 좌로 한 번 다시 보내서 각 위치에 도달할 때의 최댓값을 DP 테이블에 업데이트
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> area[i][j];
		}
	}
	// DP 테이블 생성
	vector<vector<int>> table(N, vector<int>(M));
	table[0][0] = area[0][0];
	for (int j = 1; j < M; j++)
	{
		table[0][j] = table[0][j - 1] + area[0][j];
	}
	for (int i = 1; i < N; i++)
	{
		// 우측으로 탐색
		vector<int> leftToRight(M);
		leftToRight[0] = table[i - 1][0] + area[i][0];
		for (int j = 1; j < M; j++)
		{
			leftToRight[j] = max(leftToRight[j - 1], table[i - 1][j]) + area[i][j];
		}
		// 좌측으로 탐색
		vector<int> rightToLeft(M);
		rightToLeft[M - 1] = table[i - 1][M - 1] + area[i][M - 1];
		for (int j = M - 2; j >= 0; j--)
		{
			rightToLeft[j] = max(rightToLeft[j + 1], table[i - 1][j]) + area[i][j];
		}
		// 우측으로 탐색
		for (int j = 0; j < M; j++)
		{
			table[i][j] = max(leftToRight[j], rightToLeft[j]);
		}
	}
	cout << table[N - 1][M - 1];

	return 0;
}