#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;
// ó�� �Է¹��� �� 0�� ��ġ ������ ���� �ϳ�,
// priority_queue �ϳ�?

// (x,y) ��ġ�� �������� ������ ���� �����ϴ��� �˻�
bool IsPossible(int** board, int x, int y)
{
	int sum = 0;
	bool isChecking = true;
	// ����
	for (int i = 0; i < 9; i++)
	{
		// ���� ��ĭ�� ������ �ϴ� ����. �� ���� �� ä������ Ȯ�εǱ� ����
		if (board[x][i] == 0)
		{
			isChecking = false;
			break;
		}
		sum += board[x][i];
	}
	if (isChecking && sum != 45)
		return false;
	// ����
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
	// ��� ����
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
			// ���� 0�� ĭ�� ��ġ, ���� ���� ���� �� ���ο� 0�� �� ĭ, 3 by 3 matrix�� 0 �� ĭ���� ����
			if (sudokuBoard[i][j] == 0)
			{
				zeroList.emplace_back(make_pair(i, j));
			}
		}
	}

	// ��� ���
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudokuBoard[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}