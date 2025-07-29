#include<iostream>

using namespace std;
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int basket, number;
	int first, last, i, j, k;
	int myList[101] = { 0, };
	for (i = 1; i < 101; i++)myList[i] = i;
	cin >> basket >> number;
	for (i = 1; i <= number; i++)
	{
		cin >> first >> last;
		k = last;
		for (j = first; j <= (first + last) / 2; j++) swap(myList[j], myList[k--]);
	}
	for (i = 1; i <= basket; i++) cout << myList[i] << ' ';
	return 0;
}