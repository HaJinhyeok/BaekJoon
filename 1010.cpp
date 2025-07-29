#include<iostream>
#define ll long long
using namespace std;

ll Permutation(int m, int n)
{
	ll result = 1;
	if (n == 0) return 1;
	for (int i = m, j = 0; j < n; j++, i--)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int T, N, M;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		// mCn = mC(m-n)
		if (N > M - N) N = M - N;
		// mCn = mPn/nPn
		cout << Permutation(M, N) / Permutation(N, N) << '\n';
	}
	return 0;
}