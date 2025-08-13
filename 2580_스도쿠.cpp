#include <iostream>
#include <vector>

using namespace std;

const int n = 9;
int sudoku[n][n];
// n-th row�� ���� i(1<=i<=9)�� �����ϴ��� ���� ��� 2���� �迭 row[n][i]
bool row[n][n+1];
// n-th column�� ���� i(1<=i<=9)�� �����ϴ��� ���� ��� 2���� �迭 column[n][i]
bool column[n][n+1];
// n-th block�� ���� i(1<=i<=9)�� �����ϴ��� ���� ��� 2���� �迭 block[n][i]
bool block[n][n+1];

// x-th row, y-th column ĭ�� �� ��° block���� return
int GetBlockNum(int x, int y)
{
	return (x / 3) * 3 + y / 3;
}

// 0~80�� ���� ĭ�� ���ڸ� ä������ ��Ʈ��ŷ
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