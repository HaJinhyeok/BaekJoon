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
	// (num,i) ��ġ�� ���Ƶ� �Ǵ��� Ȯ��
	for (int i = 0; i < N; i++)
	{
		// ������� ���� ������ ��ġ�� ��
		for (int j = 0; j < num; j++)
		{
			// ���� �� Ȥ�� ���� ���� ���
			if (queenList[j].first == num || queenList[j].second == i)
			{
				isPossible = false;
				break;
			}
			// �밢���� ���� ���
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
