#include<iostream>
#define SUBMISSION 28
using namespace std;

int main() {
	bool isSubm[31] = { false, };
	int i,myNum;
	for (i = 1; i <= SUBMISSION; i++)
	{
		cin >> myNum;
		isSubm[myNum] = true;
	}
	for (i = 1; i < 31; i++)
		if (!isSubm[i])cout << i << endl;

	return 0;
}