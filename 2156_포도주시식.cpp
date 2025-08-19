#include<iostream>

using namespace std;
//n번째 포도주 잔에 대해, 3가지 상태 존재
//안 먹기 = > n - 1번째 세 가지 상태 중 max
//연속1로 먹기 = > 안 먹기[n-1] + 포도주[n]
//연속2로 먹기 = > 연속1로 먹기[n-1] + 포도주[n]

int main()
{
	int num;
	int drink;
	int currentState[3] = { 0, };
	int preState[3] = { 0, };
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> drink;
		currentState[0] = max(preState[0], max(preState[1], preState[2]));
		currentState[1] = preState[0] + drink;
		currentState[2] = preState[1] + drink;
		for (int j = 0; j < 3; j++)
		{
			preState[j] = currentState[j];
		}
	}
	cout << max(currentState[0], max(currentState[1], currentState[2]));
	return 0;
}