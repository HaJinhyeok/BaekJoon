#include<iostream>
#include<cmath>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	// ax + by = c & dx + ey = f
	int a, b, c, d, e, f;
	int xAnswer = 0, yAnswer = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if (a * b * d * e == 0) // ����� 0�� ������ ���, �� ���� �ظ� ���� �� �ִ�.
	{
		// y�� ��� �� �� �� �ϳ��� 0�� ��. �� �� 0�� �Ǹ� y�� �� ����. 
		if (b == 0)
		{
			xAnswer = c / a;
			yAnswer = (f - d * xAnswer) / e;
		}
		else if (e == 0)
		{
			xAnswer = f / d;
			yAnswer = (c - a * xAnswer) / b;
		}
		// x�� ��� �� �� �� �ϳ��� 0�� ��. �� �� 0�� �Ǹ� x�� �� ����.
		if (d == 0)
		{
			yAnswer = f / e;
			xAnswer = (c - b * yAnswer) / a;
		}
		else if (a == 0)
		{
			yAnswer = c / b;
			xAnswer = (f - e * yAnswer) / d;
		}
	}
	else
	{
		int beGCD = GCD(abs(b), abs(e));
		// b, e�� ���� ���缭 y�� ����
		int firstMultiple = e / beGCD, secondMultiple = b / beGCD;
		a *= firstMultiple; b *= firstMultiple; c *= firstMultiple;
		d *= secondMultiple; e *= secondMultiple; f *= secondMultiple;
		a -= d; b -= e; c -= f; // b = 0 ���� �����
		xAnswer = c / a;

		f -= d * xAnswer;
		yAnswer = f / e;
	}

	cout << xAnswer << ' ' << yAnswer;
	return 0;
}
