#include<iostream>

using namespace std;

int main() {
	char myString[101] = { NULL, };
	int myLen = 0;
	int i = 0;
	cin >> myString;
	while (myString[i] != NULL)
	{
		myLen++; i++;
	}
	cout << myLen;
	return 0;
}