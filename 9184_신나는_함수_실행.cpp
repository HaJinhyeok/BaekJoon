#include <iostream>

using namespace std;

// -50 => 0, +50 => +100
int memoization[102][102][102];
int Recurr(int a, int b, int c);

int main()
{
	int a, b, c;
	bool isPlaying = true;

	while (isPlaying)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			isPlaying = false;
		else
		{
			printf("w(%d, %d, %d) = %d\n", a, b, c, Recurr(a + 50, b + 50, c + 50));
		}
	}
	return 0;
}

int Recurr(int a, int b, int c)
{
	if (memoization[a][b][c])
		return memoization[a][b][c];

	if (a <= 50 || b <= 50 || c <= 50)
		return memoization[a][b][c] = 1;
	else if (a > 70 || b > 70 || c > 70)
		return memoization[70][70][70] == 0 ? Recurr(70, 70, 70) : memoization[70][70][70];
	else if (a < b && b < c)
	{
		return memoization[a][b][c] = Recurr(a, b, c - 1) + Recurr(a, b - 1, c - 1) - Recurr(a, b - 1, c);
	}
	else
	{
		return memoization[a][b][c] = Recurr(a - 1, b, c) + Recurr(a - 1, b - 1, c) + Recurr(a - 1, b, c - 1) - Recurr(a - 1, b - 1, c - 1);
	}
}