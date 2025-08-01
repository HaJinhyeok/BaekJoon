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
	if (a * b * d * e == 0) // 계수에 0이 존재할 경우, 더 쉽게 해를 구할 수 있다.
	{
		// y의 계수 두 개 중 하나가 0일 때. 둘 다 0이 되면 y를 못 구함. 
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
		// x의 계수 두 개 중 하나가 0일 때. 둘 다 0이 되면 x를 못 구함.
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
		// b, e를 먼저 맞춰서 y항 제거
		int firstMultiple = e / beGCD, secondMultiple = b / beGCD;
		a *= firstMultiple; b *= firstMultiple; c *= firstMultiple;
		d *= secondMultiple; e *= secondMultiple; f *= secondMultiple;
		a -= d; b -= e; c -= f; // b = 0 으로 만들기
		xAnswer = c / a;

		f -= d * xAnswer;
		yAnswer = f / e;
	}

	cout << xAnswer << ' ' << yAnswer;
	return 0;
}
