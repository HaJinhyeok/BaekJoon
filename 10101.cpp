#include<iostream>

using namespace std;

int checkAngle(int a, int b, int c)
{
	if (a == b && b == c) return 3;
	else if (a == b || a == c || b == c) return 2;
	else return 1;
}
int main() {
	int first, second, third;
	cin >> first >> second >> third;
	if (first + second + third != 180) cout << "Error";
	else
	{
		switch (checkAngle(first, second, third))
		{
		case 3:
			cout << "Equilateral";
			break;
		case 2:
			cout << "Isosceles";
			break;
		case 1:
			cout << "Scalene";
			break;
		default:
			break;
		}
	}
	
	return 0;
}