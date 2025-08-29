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

// 1. 초콜릿 주어짐
// 2. (x,y)에 위치한 단위 초콜릿 하나 떼먹음
// 2-1. 두 개의 단위 초콜릿 사이를 잘랐을 때 connected이면 false
// 2-2. 어느 위치를 잘라도 unconnected이면 true, (x,y) 저장

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

// 2단계에서 단위 초콜릿이 떼어진 초콜릿 배열을 받아와 2개의 조각으로 나뉘는지 체크
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
				// (연결된 단위 초콜릿의 개수 != 현재 남아있는 전체 단위 초콜릿의 개수) 이면 unconnected
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
				// 잘랐는데 connected이면 2단계 충족 실패
				// (x,y)와 (x+1,y) 사이를 자르면 cut은 {x,y,true}
				// (x,y)와 (x,y+1) 사이를 자르면 cut은 {x,y,false}
				if (CheckConnection(choco, num - 1) == true)
					return false;
				choco[i][j] = '#';
			}
		}
	}
	return true;
}