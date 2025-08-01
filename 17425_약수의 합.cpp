#include<iostream>
#include<vector>

#define ll long long
#define MAX 1000000

using namespace std;

ll prefixSum[MAX + 1] = { 0, };

int main()
{
	// f(A) := sum of divisor of A
	// g(x) := sum of f(y), where 1 <= y <= x
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test, nEnter, i, j;

	cin >> test;
	for (i = 1; i <= MAX; i++)
	{
		for (j = 1; i * j <= MAX; j++)
		{
			prefixSum[i * j] += i;
		}
		prefixSum[i] += prefixSum[i - 1];
	}
	for (i = 1; i <= test; i++)
	{
		cin >> nEnter;
		cout << prefixSum[nEnter] << '\n';
	}
	return 0;
}