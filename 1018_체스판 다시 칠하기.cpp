#include<iostream>
#include<vector>

using namespace std;

int CheckReColor(vector<vector<char> > chessBoard, int x, int y);

int main()
{
	int N, M; // N by M matrix
	int minReColored = 65; // 8 by 8 board를 다시 칠하는 최악의 수는 모두를 재색칠하는 64
	int i, j, checkResult;

	cin >> N >> M;
	vector<vector<char> > ChessBoard(N, vector<char>(M));
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> ChessBoard[i][j];
		}
	}


	for (i = 0; i < N - 7; i++)
	{
		for (j = 0; j < M - 7; j++)
		{
			checkResult = CheckReColor(ChessBoard, i, j);
			minReColored = (minReColored < checkResult) ? minReColored : checkResult;
		}
	}

	cout << minReColored;

	return 0;
}
int CheckReColor(vector<vector<char> > chessBoard, int x, int y)
{
	int reColored1 = 0, reColored2 = 0;
	int i, j, idx = 0;

	// 8 by 8로 잘랐을 때, (0,0)이 B일 때와 W일 때 각각의 경우에서 다시 칠해야 하는 개수 구하기
	// 'B'부터 해보자 - index가 짝수이면 B로 칠해져있어야 하고, 홀수이면 W로 칠해져있어야 한다.
	for (i = x; i < x + 8; i++)
	{
		for (j = y; j < y + 8; j++)
		{
			if (idx % 2 == 0 && chessBoard[i][j] == 'W') reColored1++;
			else if (idx % 2 == 1 && chessBoard[i][j] == 'B') reColored1++;
			idx++;
		}
		// 매 행의 마지막 칸과 그 다음 행의 첫째 칸은 같아야 하므로 index를 하나 더해준다.
		idx++;
	}
	// (0,0) 기준을 'W'로 잡을 때 - index가 짝수이면 W로 칠해져있어야 하고, 홀수이면 B로.
	idx = 0;
	for (i = x; i < x + 8; i++)
	{
		for (j = y; j < y + 8; j++)
		{
			if (idx % 2 == 0 && chessBoard[i][j] == 'B') reColored2++;
			else if (idx % 2 == 1 && chessBoard[i][j] == 'W') reColored2++;
			idx++;
		}
		idx++;
	}

	return (reColored1 < reColored2) ? reColored1 : reColored2;
}