#include<iostream>

using namespace std;

int main()
{
	// For all n>=n0, there exist C & n0 such that Fa1 * n + Fa0 <= C * n
	int Fa1, Fa0, C, n0;
	bool isBigO = false;
	cin >> Fa1 >> Fa0;
	cin >> C;
	cin >> n0;
	if (C < Fa1) isBigO = false;
	else
	{
		C -= Fa1;
		if (C * n0 >= Fa0) isBigO = true;
	}
	
	cout << isBigO;
	return 0;
}