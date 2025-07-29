#include <iostream>
#include <vector>

using namespace std;

int CleaningUp(vector<vector<int>>& space, int x, int y, int dir);

// 0 - û�ҵ��� ���� �� ĭ, 1 - ��, 2 - û�� �Ϸ�� �� ĭ
int main()
{
	int row, col, dir, x, y;
	int i, j;
	cin >> row >> col;
	cin >> x >> y >> dir;
	vector<vector<int>> space(row, vector<int>(col));
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cin >> space[i][j];
		}
	}

	cout << CleaningUp(space, x, y, dir);

	return 0;
}

int CleaningUp(vector<vector<int>>& space, int x, int y, int dir)
{
	// dir: 0-��, 1-��, 2-��, 3-��
	int count = 0, row = space.size(), col = space[0].size();
	bool isPossible = true;
	bool checkEmpty[4];
	while (isPossible)
	{
		if (space[x][y] == 0)
		{
			space[x][y] = 2;
			count++;
			/*for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << space[i][j] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';*/
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				checkEmpty[i] = false;
			}
			// ��
			if (x > 0 && space[x - 1][y] == 0)
				checkEmpty[0] = true;
			// ��
			if (y < col - 1 && space[x][y + 1] == 0)
				checkEmpty[1] = true;
			// ��
			if (x < row - 1 && space[x + 1][y] == 0)
				checkEmpty[2] = true;
			// ��
			if (y > 0 && space[x][y - 1] == 0)
				checkEmpty[3] = true;
			// û�ҵ��� ���� �� ĭ�� �ִ� ���
			if (checkEmpty[0] || checkEmpty[1] || checkEmpty[2] || checkEmpty[3])
			{
				while (true)
				{
					if (dir == 0) dir += 4;
					// �ݽð� ȸ��
					dir--;
					if (dir == 0 && checkEmpty[dir])
					{
						x--;
						break;
					}
					else if (dir == 1 && checkEmpty[dir])
					{
						y++;
						break;
					}
					else if (dir == 2 && checkEmpty[dir])
					{
						x++;
						break;
					}
					else if (dir == 3 && checkEmpty[dir])
					{
						y--;
						break;
					}
					else
					{
						// �տ� û�ҵ��� ���� �� ĭ ���� ������ ����
						continue;
					}
				}
				
			}
			// û�ҵ��� ���� �� ĭ�� ���� ���
			else
			{
				if (dir == 0)
				{
					// ���� Ȯ��
					if (x < row - 1 && space[x + 1][y] != 1)
						x++;
					else
						isPossible = false;
				}
				else if (dir == 1)
				{
					// ���� Ȯ��
					if (y > 0 && space[x][y - 1] != 1)
						y--;
					else
						isPossible = false;
				}
				else if (dir == 2)
				{
					// ���� Ȯ��
					if (x > 0 && space[x - 1][y] != 1)
						x--;
					else
						isPossible = false;
				}
				else if (dir == 3)
				{
					// ���� Ȯ��
					if (y < col - 1 && space[x][y + 1] != 1)
						y++;
					else
						isPossible = false;
				}
			}
		}
	}

	return count;
}

/*
1. ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
2. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���
2-1. �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �� �ִٸ� �� ĭ �����ϰ� 1������ ���ư���.
2-2. �ٶ󺸴� ������ ���� ĭ�� ���̶� ������ �� ���ٸ� �۵��� �����.
3. ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ� ���,
3-1. �ݽð� �������� 90�� ȸ���Ѵ�.
3-2. �ٶ󺸴� ������ �������� ���� ĭ�� û�ҵ��� ���� �� ĭ�� ��� �� ĭ �����Ѵ�.
3-3. 1������ ���ư���.
*/ 