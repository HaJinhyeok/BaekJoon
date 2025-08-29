#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int>> coordinates;
int	N;

pair<int, int> FindStartChoco(const vector<vector<char>>& choco);
int CountConnectedChoco(const vector<vector<char>>& choco, vector<vector<bool>>& check, int x, int y, const tuple<int, int, bool>& cut);
bool CheckConnection(const vector<vector<char>>& choco, int num);
bool CheckSecondCondition(vector<vector<char>>& choco, int num);

// 1. ���ݸ� �־���
// 2. (x,y)�� ��ġ�� ���� ���ݸ� �ϳ� ������
// 2-1. �� ���� ���� ���ݸ� ���̸� �߶��� �� connected�̸� false
// 2-2. ��� ��ġ�� �߶� unconnected�̸� true, (x,y) ����

int main()
{
	int count = 0;
	string input;
	cin >> N;
	vector<vector<char>> chocolate(N, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < N; j++)
		{
			chocolate[i][j] = input[j];
			if (input[j] == '#')
			{
				count++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chocolate[i][j] == '#')
			{
				chocolate[i][j] = '.';
				if (CheckSecondCondition(chocolate, count - 1) == true)
				{
					coordinates.push_back({ i, j });
				}
				chocolate[i][j] = '#';
			}
		}
	}

	cout << coordinates.size();
	for (auto [a, b] : coordinates)
	{
		cout << '\n' << a + 1 << ' ' << b + 1;
	}
	return 0;
}

pair<int, int> FindStartChoco(const vector<vector<char>>& choco)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (choco[i][j] == '#')	return { i, j };
		}
	}
}

int CountConnectedChoco(const vector<vector<char>>& choco, vector<vector<bool>>& check, int x, int y, const tuple<int, int, bool>& cut)
{
	cout << "Current Cut: (" << get<0>(cut) << ", " << get<1>(cut) << ", " << get<2>(cut) << ")\n";
	if (x < 0 || y < 0 || x >= N || y >= N)	return 0;
	if (choco[x][y] == '.')	return 0;
	if (check[x][y] == true) return 0;
	int result = 1;
	check[x][y] = true;


	if (get<2>(cut) == false)
	{
		if (y != get<1>(cut))
		{
			result += CountConnectedChoco(choco, check, x, y + 1, cut);
		}
		if (y - 1 != get<1>(cut))
		{
			result += CountConnectedChoco(choco, check, x, y - 1, cut);
		}
		result += CountConnectedChoco(choco, check, x + 1, y, cut) + CountConnectedChoco(choco, check, x - 1, y, cut);
	}
	else if (get<2>(cut) == true)
	{
		if (x != get<0>(cut))
		{
			result += CountConnectedChoco(choco, check, x + 1, y, cut);
		}
		if (x - 1 != get<0>(cut))
		{
			result += CountConnectedChoco(choco, check, x - 1, y, cut);
		}
		result += CountConnectedChoco(choco, check, x, y + 1, cut) + CountConnectedChoco(choco, check, x, y - 1, cut);
	}

	return result;
}

// 2�ܰ迡�� ���� ���ݸ��� ������ ���ݸ� �迭�� �޾ƿ� 2���� �������� �������� üũ
bool CheckConnection(const vector<vector<char>>& choco, int num)
{
	int count = 0;
	vector<vector<bool>> check(N, vector<bool>(N, false));
	pair<int, int> start = FindStartChoco(choco);

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (choco[i][j] == '#' && choco[i + 1][j] == '#')
			{
				count = CountConnectedChoco(choco, check, start.first, start.second, { i, j, true });
				// (����� ���� ���ݸ��� ���� != ���� �����ִ� ��ü ���� ���ݸ��� ����) �̸� unconnected
				if (count == num)
				{
					return true;
				}
			}
			if (choco[i][j] == '#' && choco[i][j + 1] == '#')
			{
				count = CountConnectedChoco(choco, check, start.first, start.second, { i, j, false });
				if (count == num)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool CheckSecondCondition(vector<vector<char>>& choco, int num)
{
	cout << "---Current Chocolate---\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << choco[i][j];
		}
		cout << '\n';
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (choco[i][j] == '#')
			{
				choco[i][j] = '.';
				// �߶��µ� connected�̸� 2�ܰ� ���� ����
				// (x,y)�� (x+1,y) ���̸� �ڸ��� cut�� {x,y,true}
				// (x,y)�� (x,y+1) ���̸� �ڸ��� cut�� {x,y,false}
				if (CheckConnection(choco, num - 1) == true)
					return false;
				choco[i][j] = '#';
			}
		}
	}
	return true;
}