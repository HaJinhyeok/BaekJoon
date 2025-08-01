#include<iostream>

using namespace std;

int main() {
	int myInt;
	cin >> myInt;
	myInt = myInt / 4;
	for (int i = 0; i < myInt; i++)
	{
		cout << "long ";
	}
	cout << "int";
	return 0;
}