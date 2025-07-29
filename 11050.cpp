#include<iostream>

using namespace std;
int Permutation(int n, int k)
{
	int result = 1;
	if (k == 0) return 1;
	for (int i = n, j = 0; j < k; j++, i--) result *= i;
	return result;
}
int main()
{
	int N, K, result = 1;
	cin >> N >> K;
	//nCk = nPk / k! = n! / (k! * (n-k)!)
	if (K > N / 2) K = N - K; // nCk = nC(n-k)
	cout << Permutation(N, K) / Permutation(K, K);
	return 0;
}