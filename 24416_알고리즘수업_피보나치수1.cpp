#include <iostream>

using namespace std;

int count1 = 0, count2 = 0;
int fibonacci[41];
int fib1(int n)
{
	if (n <= 2)
	{
		count1++;
		return 1;
	}
	else return fib1(n - 1) + fib1(n - 2);
}
int fib2(int n)
{
	fibonacci[1] = 1;
	fibonacci[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		count2++;
	}
	return fibonacci[n];
}
int main()
{
	int N;
	cin >> N;
	fib1(N); fib2(N);
	cout << count1 << ' ' << count2;
	return 0;
}