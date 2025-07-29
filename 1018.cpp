#include<iostream>
#include<vector>

using namespace std;

int CheckReColor(vector<vector<char> > chessBoard, int x, int y);

int main()
{
	int N, M; // N by M matrix
	int minReColored = 65; // 8 by 8 board�� �ٽ� ĥ�ϴ� �־��� ���� ��θ� ���ĥ�ϴ� 64
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

	// 8 by 8�� �߶��� ��, (0,0)�� B�� ���� W�� �� ������ ��쿡�� �ٽ� ĥ�ؾ� �ϴ� ���� ���ϱ�
	// 'B'���� �غ��� - index�� ¦���̸� B�� ĥ�����־�� �ϰ�, Ȧ���̸� W�� ĥ�����־�� �Ѵ�.
	for (i = x; i < x + 8; i++)
	{
		for (j = y; j < y + 8; j++)
		{
			if (idx % 2 == 0 && chessBoard[i][j] == 'W') reColored1++;
			else if (idx % 2 == 1 && chessBoard[i][j] == 'B') reColored1++;
			idx++;
		}
		// �� ���� ������ ĭ�� �� ���� ���� ù° ĭ�� ���ƾ� �ϹǷ� index�� �ϳ� �����ش�.
		idx++;
	}
	// (0,0) ������ 'W'�� ���� �� - index�� ¦���̸� W�� ĥ�����־�� �ϰ�, Ȧ���̸� B��.
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