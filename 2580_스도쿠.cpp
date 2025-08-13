#include <iostream>
#include <vector>

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
		return Backtracking(idx + 1);
	for (int i = 1; i <= 9; i++)
	{
		if (!row[x][i] && !column[y][i] && !block[GetBlockNum(x, y)][i])
		{
			sudoku[x][y] = i;
			row[x][i] = true;
			column[y][i] = true;
			block[GetBlockNum(x, y)][i] = true;
			if (Backtracking(idx + 1))
			{
				return true;
			}
			sudoku[x][y] = 0;
			row[x][i] = false;
			column[y][i] = false;
			block[GetBlockNum(x, y)][i] = false;
		}
	}
	return false;
}

int main()
{
	int enter;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> enter;
				sudoku[i][j]=enter;
				row[i][enter] = true;
				column[j][enter] = true;
				block[GetBlockNum(i, j)][enter] = true;
		}
	}
	Backtracking(0);
	return 0;
}