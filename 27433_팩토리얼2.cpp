#include<iostream>
#define ll long long
using namespace std;
ll Factorial(ll n)
{
	if (n == 0 || n == 1) return 1;
	else return n * Factorial(n - 1);
}
int main()
{
	int N;
	cin >> N;
	cout << Factorial(N);
	return 0;
}