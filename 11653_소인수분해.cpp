#include<iostream>
using namespace std;

int main() {
	int myInt, i, nCheck;
	cin >> myInt;
	nCheck = myInt;
	for (i = 2; i <= myInt;)
	{
		if (nCheck % i == 0)
		{
			cout << i << '\n';
			nCheck /= i;
		}
		else
		{
			i++;
		}
	}
	return 0;
}