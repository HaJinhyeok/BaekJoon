#include<iostream>

using namespace std;

int main() {
	char myString[1001];
	int myIdx;
	cin >> myString;
	cin >> myIdx;
	cout << myString[myIdx - 1 ];
	return 0;
}