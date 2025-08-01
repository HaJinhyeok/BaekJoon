#include<iostream>

using namespace std;
// 닫히면 false(0), 열리면 true(1)

int main()
{
	unsigned int N, countSquareNum = 0;
	cin >> N;
	
	for (unsigned int i = 1; i * i <= N; i++)	countSquareNum++;

	cout << countSquareNum;

	return 0;
}