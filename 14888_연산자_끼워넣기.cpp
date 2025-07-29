#include <iostream>
#include <vector>

using namespace std;

int minResult = 1234567890, maxResult = -1234567890;
int myNum[11];
int operNum[4];
int N;
char operations[10];

void BackTracking(int operNum[], int depth);
int CalculateExpression(vector<char> expression, int N);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> myNum[i];

	}
	for (int i = 0; i < 4; i++)
	{
		cin >> operNum[i];
	}

	BackTracking(operNum, 0);
	cout << maxResult << '\n' << minResult;

	return 0;
}

int CalculateExpression()
{
	int result = myNum[0];
	for (int i = 0; i < N - 1; i++)
	{
		switch (operations[i])
		{
		case '+':
			result += myNum[i + 1];
			break;
		case '-':
			result -= myNum[i + 1];
			break;
		case '*':
			result *= myNum[i + 1];
			break;
		case '/':
			result /= myNum[i + 1];
			break;
		default:
			break;
		}
	}
	return result;
}

void BackTracking(int operNum[], int depth)
{
	if (depth == N - 1)
	{
		int result = CalculateExpression();
		minResult = result < minResult ? result : minResult;
		maxResult = result > maxResult ? result : maxResult;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if(operNum[i]>0)
			{
				operNum[i]--;
				switch (i)
				{
				case 0:
					operations[depth] = '+';
					break;
				case 1:
					operations[depth] = '-';
					break;
				case 2:
					operations[depth] = '*';
					break;
				case 3:
					operations[depth] = '/';
					break;
				}
				BackTracking(operNum, depth + 1);
				operNum[i]++;
			}
			else
			{
				for (int j = i + 1; j % 4 < i; j++)
				{
					if(operNum[j%4]>0)
					{
						operNum[j % 4]--;
						switch (j % 4)
						{
						case 0:
							operations[depth] = '+';
							break;
						case 1:
							operations[depth] = '-';
							break;
						case 2:
							operations[depth] = '*';
							break;
						case 3:
							operations[depth] = '/';
							break;
						}
						BackTracking(operNum, depth + 1);
						operNum[j % 4]++;
					}
				}
			}
		}
	}
}