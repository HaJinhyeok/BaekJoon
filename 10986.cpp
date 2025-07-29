#include<iostream>
#include<vector>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	// '나머지' 합
	// S_n (mod M)
	// 예제: 1, 3, 6, 7, 9
	// modula 3
	// >>   1, 0, 0, 1, 0
	// >>   
	// case 1) S_n = 0 (mod M) >> 3
	// case 2) A_j = A_i ( mod M) >> 1 + 3			1 ~ (n-1)
	int N, M, i;
	int An;
	int currentModula = 0;
	ll result = 0;
	cin >> N >> M;
	vector<ll> numOfModula(M, 0);
	
	for (i = 0; i < N; i++)
	{
		cin >> An;
		currentModula = (currentModula + An) % M;
		numOfModula[currentModula]++;
	}
	result += numOfModula[0];
	for (i = 0; i < M; i++)
	{
		if (numOfModula[i] > 1)	result += (numOfModula[i] - 1) * numOfModula[i] / 2;
	}
	cout << result;
	return 0;
}