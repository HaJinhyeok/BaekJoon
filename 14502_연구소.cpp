#include <iostream>
#include <vector>

using namespace std;

int CalculateSafeZone(vector<vector<int> >& space);
int BruteForce(vector<vector<int>>& space);
void VirusSpread(vector<vector<int>>& tmpSpace, int x, int y, int row, int col);
void PrintSpace(vector<vector<int>>& tmpSpace);

int main()
{
	// 1. N by M �ʿ��� ���� ������ ũ�⸦ ���ϴ� �Լ�
	// 2. �� ���� �� 3���� ĭ�� �����ϴ� brute force �Լ�
	int row, col, enter;
	cin >> row >> col;
	vector<vector<int>> laboratory(row, vector<int>(col));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> enter;
			laboratory[i][j] = enter;
		}
	}
	cout << BruteForce(laboratory);

	return 0;
}
int CalculateSafeZone(vector<vector<int> >& space)
{
	// space ������ ���� for���� ���� ���ڰ� 0�� ĭ�� ������ count++
	// ���ڰ� 2�� ĭ�� ������ �����¿��� 0�� ĭ�� 2�� �ٲٰ� count--
	int count = 0;
	int row = space.size(), col = space[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (space[i][j] == 2)
			{
				if (i > 0 && space[i - 1][j] == 0)
				{
					VirusSpread(space, i - 1, j, row, col);
				}
				if (i < row - 1 && space[i + 1][j] == 0)
				{
					VirusSpread(space, i + 1, j, row, col);
				}
				if (j > 0 && space[i][j - 1] == 0)
				{
					VirusSpread(space, i, j - 1, row, col);
				}
				if (j < col - 1 && space[i][j + 1] == 0)
				{
					VirusSpread(space, i, j + 1, row, col);
				}
			}
		}
	}
	// �� ���� ī��Ʈ
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (space[i][j] == 0)
				count++;
		}
	}
	return count;
}
int BruteForce(vector<vector<int>>& space)
{
	// space ���� �� �������� ��ǥ�� pair ���·� vector�� ����
	vector<pair<int, int>> posEmpty;
	// �ùķ��̼� ���� �ӽ� ����� ����
	vector<vector<int>> tmpSpace;
	tmpSpace.assign(space.size(), vector<int>(space[0].size()));
	// �� ���� �� ���� ����
	pair<int, int> first, second, third;
	int row = space.size(), col = space[0].size();
	int result = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (space[i][j] == 0)
				posEmpty.emplace_back(make_pair(i, j));
		}
	}
	// ����, �� �߿��� 3���� ������ ������ �� ���� CalculateSafeZone ����
	int len = posEmpty.size();
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len - 1; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				// ���̷��� Ȯ�� �ùĿ� tmpSpace�� ���� space ����
				copy(space.begin(), space.end(), tmpSpace.begin());
				// ���� �� �� ����
				first = posEmpty[i];
				second = posEmpty[j];
				third = posEmpty[k];
				// ������ ���� 1(��)�� �ٲٱ�
				tmpSpace[first.first][first.second] = 1;
				tmpSpace[second.first][second.second] = 1;
				tmpSpace[third.first][third.second] = 1;
				// �� ���� ���
				result = max(result, CalculateSafeZone(tmpSpace));
				// ������ ���� �ٽ� 0(�� ����)���� �ٲٱ�
				/*space[first.first][first.second] = 0;
				space[second.first][second.second] = 0;
				space[third.first][third.second] = 0;*/
			}
		}
	}
	return result;
}
void VirusSpread(vector<vector<int>>& tmpSpace, int x, int y, int row, int col)
{
	tmpSpace[x][y] = 2;
	// PrintSpace(tmpSpace);
	if (x > 0 && tmpSpace[x - 1][y] == 0)
	{
		VirusSpread(tmpSpace, x - 1, y, row, col);
	}
	if (x < row - 1 && tmpSpace[x + 1][y] == 0)
	{
		VirusSpread(tmpSpace, x + 1, y, row, col);
	}
	if (y > 0 && tmpSpace[x][y - 1] == 0)
	{
		VirusSpread(tmpSpace, x, y - 1, row, col);
	}
	if (y < col - 1 && tmpSpace[x][y + 1] == 0)
	{
		VirusSpread(tmpSpace, x, y + 1, row, col);
	}
}
void PrintSpace(vector<vector<int>>& tmpSpace)
{
	int row = tmpSpace.size(), col = tmpSpace[0].size();
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			cout << tmpSpace[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}