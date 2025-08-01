#include<iostream>

using namespace std;

int main() {
	int xCo[3], yCo[3];
	int x4, y4;
	for (int i = 0; i < 3; i++)
	{
		cin >> xCo[i] >> yCo[i];
	}
	if (xCo[0] == xCo[1]) x4 = xCo[2];
	else if (xCo[0] == xCo[2]) x4 = xCo[1];
	else x4 = xCo[0];
	if (yCo[0] == yCo[1]) y4 = yCo[2];
	else if (yCo[0] == yCo[2]) y4 = yCo[1];
	else y4 = yCo[0];
	cout << x4 << ' ' << y4;
	return 0;
}