#include<iostream>
#include<vector>

using namespace std;
int CountIslands(vector<vector<int>>& land);
void CheckConnected(vector<vector<int>>& land, int x, int y, vector<vector<bool>>& isVisited);

int main()
{
	int width = -1, height = -1;
	while (true)
	{
		cin >> width >> height;
		if (width == 0 && height == 0)
			break;
		vector<vector<int>> landInfo(height, vector<int>(width));
		for (int i = 0;i < height;i++)
		{
			for (int j = 0;j < width;j++)
			{
				cin >> landInfo[i][j];
			}
		}
		cout << CountIslands(landInfo) << '\n';
	}
	return 0;
}

int CountIslands(vector<vector<int>>& land)
{
	int count = 0;
	int height = land.size();
	int width = land[0].size();
	vector<vector<bool>> isVisited(height, vector<bool>(width));
	for (int i = 0;i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			if (land[i][j] == 1 && !isVisited[i][j])
			{
				count++;
				CheckConnected(land, i, j, isVisited);
			}
		}
	}
	return count;
}

void CheckConnected(vector<vector<int>>& land, int x, int y, vector<vector<bool>>& isVisited)
{
	if (x < 0 || x > land.size() - 1)
		return;
	if (y < 0 || y > land[0].size() - 1)
		return;
	if (land[x][y] == 0 || isVisited[x][y])
		return;

	isVisited[x][y] = true;
	CheckConnected(land, x - 1, y - 1, isVisited);
	CheckConnected(land, x, y - 1, isVisited);
	CheckConnected(land, x + 1, y - 1, isVisited);
	CheckConnected(land, x - 1, y, isVisited);
	CheckConnected(land, x + 1, y, isVisited);
	CheckConnected(land, x - 1, y + 1, isVisited);
	CheckConnected(land, x, y + 1, isVisited);
	CheckConnected(land, x + 1, y + 1, isVisited);
}