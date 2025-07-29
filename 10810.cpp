#include<iostream>

using namespace std;

int main() {
	int basket, number, i, j;
	int myList[101] = { 0, };
	int First, Last, ball;
	cin >> basket >> number;
	for (i = 0; i < number; i++)
	{
		cin >> First >> Last >> ball;
		for (j = First - 1; j < Last; j++) myList[j] = ball;
	}
	for (i = 0; i < basket; i++) cout << myList[i] << ' '; // 틀리면 마지막 공백 빼보기
	return 0;
}