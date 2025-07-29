#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;
// 처음 입력받을 때 0인 위치 저장할 벡터 하나,
// priority_queue 하나?


int main()
{
	int sudokuBoard[9][9];
	vector<pair<int, int>> zeroList;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudokuBoard[i][j];
			// 값이 0인 칸의 위치, 본인 포함 가로 및 세로에 0이 몇 칸, 3 by 3 matrix에 0 몇 칸인지 저장
			if (sudokuBoard[i][j] == 0)
			{
				zeroList.emplace_back(make_pair(i, j));
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudokuBoard[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}