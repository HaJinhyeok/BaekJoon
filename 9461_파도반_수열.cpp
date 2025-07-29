#include <iostream>

using namespace std;
typedef long long ll;

ll tmp[101] = { 0, };
// f(n) = f(n-2) + f(n-3)
ll Padovan(int n)
{
	if (tmp[n])
		return tmp[n];

	if (n <= 3)
		return tmp[n] = 1;
	else
		return tmp[n] = Padovan(n - 2) + Padovan(n - 3);
}
int main()
{
	int test, num;
	cin >> test;
	while (test--)
	{
		cin >> num;
		cout << Padovan(num) << '\n';
	}
	return 0;
}