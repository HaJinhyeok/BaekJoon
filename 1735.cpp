#include<iostream>
#define ui unsigned int

using namespace std;

ui gcd(ui a, ui b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
ui lcm(ui a, ui b)
{
	return a * b / gcd(a, b);
}

int main()
{
	ui nume1, nume2, denom1, denom2;
	ui finalNume, finalDenom;
	cin >> nume1 >> denom1;
	cin >> nume2 >> denom2;

	finalDenom = lcm(denom1, denom2);
	finalNume = nume1 * (finalDenom / denom1) + nume2 * (finalDenom / denom2);

	ui finalGCD = gcd(finalDenom, finalNume);
	if (finalGCD != 1)
	{
		finalNume /= finalGCD;
		finalDenom /= finalGCD;
	}
	cout << finalNume << ' ' << finalDenom;

	return 0;
}