#include <iostream>
#include <vector>

using namespace std;

int CountSafeZone(vector<vector<int>>& area, int height, int N);
void CheckSafeZone(vector<vector<int>>& area, vector<vector<bool>>& checkArea, int x, int y, int height, int N);

int main()
{
	int N, count = 0, tmpResult;
	int maxHeight = 1;
	cin >> N;
	vector<vector<int>> area(N, vector<int>(N));
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> area[i][j];
			maxHeight = area[i][j] > maxHeight ? area[i][j] : maxHeight;
		}
	}
	for (int i = 0;i < maxHeight;i++)
	{
		// 물 높이 == i일 때 안전지역 개수 구하는 함수
		tmpResult = CountSafeZone(area, i, N);
		count = tmpResult > count ? tmpResult : count;
	}
	cout << count;
	return 0;
}

int CountSafeZone(vector<vector<int>>& area, int height, int N)
{
	int count = 0;
	vector<vector<bool>> checkArea(N, vector<bool>(N));
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			// 수위보다 높고, 아직 체크 안된 곳이면
			if (area[i][j] > height && !checkArea[i][j])
			{
				// 카운트하고, 안전구역 체크
				count++;
				CheckSafeZone(area, checkArea, i, j, height, N);
			}
		}
	}

	return count;
}

void CheckSafeZone(vector<vector<int>>& area, vector<vector<bool>>& checkArea, int x, int y, int height, int N)
{
	// 이미 체크됐거나, 수위보다 낮거나 같으면 패스
	if (checkArea[x][y] || area[x][y] <= height)
		return;
	else
	{
		checkArea[x][y] = true;
	}
	// 상하좌우칸 검사 실시
	if (x > 0)
		CheckSafeZone(area, checkArea, x - 1, y, height, N);
	if (x < N - 1)
		CheckSafeZone(area, checkArea, x + 1, y, height, N);
	if (y > 0)
		CheckSafeZone(area, checkArea, x, y - 1, height, N);
	if (y < N - 1)
		CheckSafeZone(area, checkArea, x, y + 1, height, N);
}