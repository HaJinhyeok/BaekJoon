#include<iostream>
#include<vector>

using namespace std;

int memoization[10001];

int main()
{
	int N;
	int a = 0, b = 0, c = 0;
	int a_, b_, c_;
	int enter;
	cin >> N;
	while (N--)
	{
		cin >> enter;
		a_ = a; b_ = b; c_ = c;
		a = max(a_, max(b_, c_));
		b = a_ + enter;
		c = b_ + enter;
	}
	cout << max(a, max(b, c));

	return 0;
}