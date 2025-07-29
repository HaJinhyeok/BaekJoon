#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// (0,0)에서 시작
// 아래쪽(x좌표+1) or 오른쪽(y좌표+1)

int N;
char myMap[5][5];
int maximum = INT_MIN, minimum = INT_MAX;

void Calculate(int posX, int posY, char oper, int result);

int main()
{
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> myMap[i][j];
		}
	}

	Calculate(0, 0, '+', 0);

	cout << maximum << ' ' << minimum;
	return 0;
}

void Calculate(int posX, int posY, char oper, int result)
{
	// 숫자칸이면
	if (myMap[posX][posY] >= 48 && myMap[posX][posY] <= 57)
	{
		switch (oper)
		{
		case '+':
			result += myMap[posX][posY] - '0';
			break;
		case '-':
			result -= myMap[posX][posY] - '0';
			break;
		case '*':
			result *= myMap[posX][posY] - '0';
			break;
		default:
			break;
		}
		// 마지막칸이면 계산하고 크기 비교하고 끝내기
		if (posX == N - 1 && posY == N - 1)
		{
			maximum = max(result, maximum);
			minimum = min(result, minimum);
			return;
		}
	}
	else if (myMap[posX][posY] == '+')
	{
		oper = '+';
	}
	else if (myMap[posX][posY] == '-')
	{
		oper = '-';
	}
	else if (myMap[posX][posY] == '*')
	{
		oper = '*';
	}
	if (posX + 1 < N)
		Calculate(posX + 1, posY, oper, result);
	if (posY + 1 < N)
		Calculate(posX, posY + 1, oper, result);
}