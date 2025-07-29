#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// space[x][y]에 대하여,
// 이동은 (+1, -1) or (+1, 0) or (+1, +1) 세 방향만 가능
// 직전에 움직인 방향과 똑같은 방향으로 이동은 불가
// 직전에 움직인 방향 정보를 제외한 나머지 두 방향에 대하여
// 백트래킹 실시

enum direction
{
	left = -1,
	mid,
	right,
	start,
};

int MinGas(vector<vector<int>>& space, int currentSum, int posX, int posY, direction dir);

int main()
{
	int N, M;
	cin >> N >> M;
	int minimum = INT_MAX;
	vector <vector<int>> space(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> space[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		minimum = min(minimum, MinGas(space, 0, 0, i, direction::start));
	}
	cout << minimum;
	return 0;
}

int MinGas(vector<vector<int>>& space, int currentSum, int posX, int posY, direction dir)
{
	int width = space[0].size();
	int height = space.size();
	if (posY < 0 || posY >= width)
		return 987654321;
	if (posX == height - 1)
		return currentSum + space[posX][posY];

	switch (dir)
	{
		// 직전에 왼쪽 이동이었으면
	case direction::left:
		return min(MinGas(space, currentSum + space[posX][posY], posX + 1, posY, direction::mid), MinGas(space, currentSum + space[posX][posY], posX + 1, posY + 1, direction::right));
		break;
	case direction::mid:
		return min(MinGas(space, currentSum + space[posX][posY], posX + 1, posY - 1, direction::left), MinGas(space, currentSum + space[posX][posY], posX + 1, posY + 1, direction::right));
		break;
	case direction::right:
		return min(MinGas(space, currentSum + space[posX][posY], posX + 1, posY, direction::mid), MinGas(space, currentSum + space[posX][posY], posX + 1, posY - 1, direction::left));
		break;
	case direction::start:
		return min(MinGas(space, currentSum + space[posX][posY], posX + 1, posY - 1, direction::left), min(MinGas(space, currentSum + space[posX][posY], posX + 1, posY, direction::mid), MinGas(space, currentSum + space[posX][posY], posX + 1, posY + 1, direction::right)));
	default:
		break;
	}
}