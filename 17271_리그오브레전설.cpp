#include<iostream>

#define DIVIDER 1000000007

using namespace std;

int memoization[10001][5001];

int Combination(int N, int R);

int main()
{
	int N, M, result = 0;
	cin >> N >> M;
	int quotient = N / M;
	int remainder;
	for (int i = 0; i <= quotient; i++)
	{
		remainder = N - i * M;
		result += Combination(i + remainder, remainder);
		result %= DIVIDER;
	}
	cout << result;
	return 0;
}

int Combination(int N, int R)
{
	// nCr = nC(n-r)
	if (R > N / 2)
		R = N - R;
	if (R == 0)
		return memoization[N][R] = 1;
	if (R == 1)
		return memoization[N][R] = N;
	if (memoization[N][R])
		return memoization[N][R];
	// nCr = (n-1)C(r-1) + (n-1)Cr
	return memoization[N][R] = (Combination(N - 1, R - 1) % DIVIDER + Combination(N - 1, R) % DIVIDER) % DIVIDER;
}