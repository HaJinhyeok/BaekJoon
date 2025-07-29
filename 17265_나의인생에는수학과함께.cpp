#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// (0,0)���� ����
// �Ʒ���(x��ǥ+1) or ������(y��ǥ+1)

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
	// ����ĭ�̸�
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
		// ������ĭ�̸� ����ϰ� ũ�� ���ϰ� ������
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