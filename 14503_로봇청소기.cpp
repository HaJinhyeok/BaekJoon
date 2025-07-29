#include <iostream>
#include <vector>

using namespace std;

int CleaningUp(vector<vector<int>>& space, int x, int y, int dir);

// 0 - 청소되지 않은 빈 칸, 1 - 벽, 2 - 청소 완료된 빈 칸
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
	// dir: 0-북, 1-동, 2-남, 3-서
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
			// 북
			if (x > 0 && space[x - 1][y] == 0)
				checkEmpty[0] = true;
			// 동
			if (y < col - 1 && space[x][y + 1] == 0)
				checkEmpty[1] = true;
			// 남
			if (x < row - 1 && space[x + 1][y] == 0)
				checkEmpty[2] = true;
			// 서
			if (y > 0 && space[x][y - 1] == 0)
				checkEmpty[3] = true;
			// 청소되지 않은 빈 칸이 있는 경우
			if (checkEmpty[0] || checkEmpty[1] || checkEmpty[2] || checkEmpty[3])
			{
				while (true)
				{
					if (dir == 0) dir += 4;
					// 반시계 회전
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
						// 앞에 청소되지 않은 빈 칸 나올 때까지 돌려
						continue;
					}
				}
				
			}
			// 청소되지 않은 빈 칸이 없는 경우
			else
			{
				if (dir == 0)
				{
					// 남쪽 확인
					if (x < row - 1 && space[x + 1][y] != 1)
						x++;
					else
						isPossible = false;
				}
				else if (dir == 1)
				{
					// 서쪽 확인
					if (y > 0 && space[x][y - 1] != 1)
						y--;
					else
						isPossible = false;
				}
				else if (dir == 2)
				{
					// 북쪽 확인
					if (x > 0 && space[x - 1][y] != 1)
						x--;
					else
						isPossible = false;
				}
				else if (dir == 3)
				{
					// 동쪽 확인
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
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
3-1. 반시계 방향으로 90도 회전한다.
3-2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
3-3. 1번으로 돌아간다.
*/ 