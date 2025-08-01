#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;
// 처음 입력받을 때 0인 위치 저장할 벡터 하나,
// priority_queue 하나?

// (x,y) 위치를 기준으로 스도쿠 조건 만족하는지 검사
bool IsPossible(int** board, int x, int y)
{
	int sum = 0;
	bool isChecking = true;
	// 가로
	for (int i = 0; i < 9; i++)
	{
		// 아직 빈칸이 있으면 일단 보류. 한 줄이 다 채워져야 확인되기 때문
		if (board[x][i] == 0)
		{
			isChecking = false;
			break;
		}
		sum += board[x][i];
	}
	if (isChecking && sum != 45)
		return false;
	// 세로
	sum = 0;
	isChecking = true;
	for (int i = 0; i < 9; i++)
	{
		if (board[i][y] == 0)
		{
			isChecking = false;
			break;
		}
		sum += board[i][y];
	}
	if (sum != 45)
		return false;
	// 블록 단위
}

int main()
{
	int sudokuBoard[9][9];
	vector<pair<int, int>> zeroList;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudokuBoard[i][j];
			// 값이 0인 칸의 위치, 본인 포함 가로 및 세로에 0이 몇 칸, 3 by 3 matrix에 0 몇 칸인지 저장
			if (sudokuBoard[i][j] == 0)
			{
				zeroList.emplace_back(make_pair(i, j));
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudokuBoard[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}