#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;
// ó�� �Է¹��� �� 0�� ��ġ ������ ���� �ϳ�,
// priority_queue �ϳ�?


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