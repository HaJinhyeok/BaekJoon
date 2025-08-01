#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int basket, number, i;
	int first, second;
	int myList[101] = { 0, };
	for (i = 1; i <= 100; i++) myList[i] = i;
	cin >> basket >> number;
	for (i = 0; i < number; i++)
	{
		cin >> first >> second;
		swap(myList[first], myList[second]);
	}
	for (i = 1; i <= basket; i++) cout << myList[i] << ' ';
	return 0;
}