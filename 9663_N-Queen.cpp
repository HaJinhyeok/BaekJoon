#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> queenList(15);
int result = 0;
bool isPossible = true;

// currentRow == numOfCurrentQueen
void Queen(int N, int num);

int main()
{
	int N, numOfCurrentQueen = 0;
	cin >> N;
	Queen(N, numOfCurrentQueen);
	cout << result;

	return 0;
}

void Queen(int N, int num)
{
	if (num == N)
	{
		result++;
		return;
	}
	// (num,i) 위치에 놓아도 되는지 확인
	for (int i = 0; i < N; i++)
	{
		// 현재까지 놓인 퀸들의 위치와 비교
		for (int j = 0; j < num; j++)
		{
			// 같은 행 혹은 열에 있을 경우
			if (queenList[j].first == num || queenList[j].second == i)
			{
				isPossible = false;
				break;
			}
			// 대각선에 있을 경우
			else if (abs(num - queenList[j].first) == abs(i - queenList[j].second))
			{
				isPossible = false;
				break;
			}
		}
		if (isPossible)
		{
			queenList[num] = make_pair(num, i);
			num++;
			Queen(N, num--);
		}
		else
		{
			isPossible = true;
		}
	}
}
