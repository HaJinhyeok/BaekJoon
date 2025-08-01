#include<iostream>

using namespace std;

bool isPrime(unsigned int n)
{
	if (n == 1 || n == 0) return false;
	for (unsigned int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
unsigned int findPrime(unsigned int n)
{
	while (!isPrime(n)) n++;
	return n;
}
int main()
{
	int test;
	unsigned int N;
	cin >> test;
	while (test--)
	{
		cin >> N;
		cout << findPrime(N) << '\n';
	}

	return 0;
}