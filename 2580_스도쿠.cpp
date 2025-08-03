#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

const int n = 9;
int sudoku[n][n];
// n-th row에 숫자 i(1<=i<=9)가 존재하는지 정보 담는 2차원 배열 row[n][i]
bool row[n][n+1];
// n-th column에 숫자 i(1<=i<=9)가 존재하는지 정보 담는 2차원 배열 column[n][i]
bool column[n][n+1];
// n-th block에 숫자 i(1<=i<=9)가 존재하는지 정보 담는 2차원 배열 block[n][i]
bool block[n][n+1];

// x-th row, y-th column 칸이 몇 번째 block인지 return
int GetBlockNum(int x, int y)
{
	return (x / 3) * 3 + y / 3;
}

// 0~80번 까지 칸에 숫자를 채워가며 백트래킹
bool Backtracking(int idx)
{
	if (idx >= 81)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}
	int x = idx / n;
	int y = idx % n;
	if (sudoku[x][y] > 0)
		return true;
}

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