#include <iostream>
#include <vector>

using namespace std;

int CalculateSafeZone(vector<vector<int> >& space);
int BruteForce(vector<vector<int>>& space);
void VirusSpread(vector<vector<int>>& tmpSpace, int x, int y, int row, int col);
void PrintSpace(vector<vector<int>>& tmpSpace);

int main()
{
	// 1. N by M 맵에서 안전 구역의 크기를 구하는 함수
	// 2. 빈 공간 중 3개의 칸을 선택하는 brute force 함수
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
	// space 내에서 이중 for문을 돌며 숫자가 0인 칸이 있으면 count++
	// 숫자가 2인 칸이 있으면 상하좌우의 0인 칸을 2로 바꾸고 count--
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
	// 빈 공간 카운트
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
	// space 내의 빈 공간들의 좌표를 pair 형태로 vector에 저장
	vector<pair<int, int>> posEmpty;
	// 시뮬레이션 돌릴 임시 실험실 공간
	vector<vector<int>> tmpSpace;
	tmpSpace.assign(space.size(), vector<int>(space[0].size()));
	// 세 개의 빈 공간 선택
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
	// 이후, 이 중에서 3개의 공간을 선택해 한 번씩 CalculateSafeZone 실행
	int len = posEmpty.size();
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len - 1; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				// 바이러스 확산 시뮬용 tmpSpace에 원래 space 복사
				copy(space.begin(), space.end(), tmpSpace.begin());
				// 공간 세 개 선택
				first = posEmpty[i];
				second = posEmpty[j];
				third = posEmpty[k];
				// 선택한 공간 1(벽)로 바꾸기
				tmpSpace[first.first][first.second] = 1;
				tmpSpace[second.first][second.second] = 1;
				tmpSpace[third.first][third.second] = 1;
				// 빈 공간 계산
				result = max(result, CalculateSafeZone(tmpSpace));
				// 선택한 공간 다시 0(빈 공간)으로 바꾸기
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