#include<iostream>

using namespace std;
//n��° ������ �ܿ� ����, 3���� ���� ����
//�� �Ա� = > n - 1��° �� ���� ���� �� max
//����1�� �Ա� = > �� �Ա�[n-1] + ������[n]
//����2�� �Ա� = > ����1�� �Ա�[n-1] + ������[n]

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