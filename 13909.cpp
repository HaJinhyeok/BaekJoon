#include<iostream>

using namespace std;
// ������ false(0), ������ true(1)

int main()
{
	unsigned int N, countSquareNum = 0;
	cin >> N;
	
	for (unsigned int i = 1; i * i <= N; i++)	countSquareNum++;

	cout << countSquareNum;

	return 0;
}