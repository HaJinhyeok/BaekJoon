#include<iostream>
#define ll long long
using namespace std;

ll lcm(ll A, ll B)
{
	ll i;
	for (i = A; i <= A * B; i += A)
	{
		if (i % B == 0) return i;
	}
	return i;
}

int main()
{
	ll A, B;
	cin >> A >> B;
	cout << lcm(A, B);
	return 0;
}