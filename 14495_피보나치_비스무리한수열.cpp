#include<iostream>

using namespace std;

typedef long long ll;

ll PsudoFibNum[117];

ll PsudoFib(int idx)
{
	if (idx <= 3)
		return PsudoFibNum[idx] = 1;
	if (PsudoFibNum[idx])
		return PsudoFibNum[idx];
	else
		return PsudoFibNum[idx] = PsudoFib(idx - 3) + PsudoFib(idx - 1);
}

int main()
{
	int num;
	cin >> num;
	cout << PsudoFib(num);
	return 0;
}