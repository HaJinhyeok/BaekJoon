#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

// n�� k���� �� goal�� ���� ����� k�� ã�� ��ȯ
// 1������ ���� Ƚ�� ���� x
int FindClosestExp(int n, ll goal)
{
	int exp = 1;
	ll prev = n;
	ll next = n * n;
	while (goal - prev > next - goal)
	{
		exp++;
		prev = next;
		next *= n;
	}
	return exp;
}

int Count(ll num)
{
	ll current = 1;
	int count = 0;
	while (current != num)
	{

	}
	return count;
}

/*
1 + 1 = 2 -> 2 + 1 = 3 -> 3 ^ 4 = 81 -> 81 - 1 = 80

& ���� ����� n ^ k ���� �� ã�� (n = prime number)&
= > (n - 1) + ( k > 1 ? 1 : 0 ) + | n ^ k - target |
*/
int main()
{
	int count = 0;
	ll enter;
	cin >> enter;


	return 0;
}