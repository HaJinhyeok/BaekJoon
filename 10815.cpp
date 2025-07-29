#include<iostream>
#define MAX 20000002
#define HALF 10000000
using namespace std;

char isExist[MAX] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);	cout.tie(NULL);		cin.tie(NULL);
	int N, M, i, cardNum;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> cardNum;
		isExist[cardNum + HALF] = 1;
	}
	cin >> M;
	while (M--)
	{
		cin >> cardNum;
		cout << (int)(isExist[cardNum + HALF]) << ' ';
	}
	return 0;
}