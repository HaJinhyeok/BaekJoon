#include<iostream>

using namespace std;

int main() {
	int myNum;
	int myList[101] = { 0, };
	int target, i;
	int numOfTarget = 0;
	cin >> myNum;
	for (i = 0; i < myNum; i++) cin >> myList[i];
	cin >> target;
	for (i = 0; i < myNum; i++) if (myList[i] == target) numOfTarget++;
	cout << numOfTarget;
	return 0;
}