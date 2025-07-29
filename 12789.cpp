#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	// ��⿭, 1���� �� �� �ִ� ����, ��� ����
	// ��⿭���� �������� �̵��� ������, �� �ݴ�� �� �ȴ�.
	// ��⿭�� ť, ������ �������� �����
	// 1. ���� ���� �� ���� ���� ��ȣ�� �ִ��� Ȯ��
	// 2. ������ ��⿭ ť �� �տ� ���� ��ȣ�� �ִ��� Ȯ��
	// 3. ������ ��⿭ ť �� �տ� ���� ��ȣ�� ���� ������ POP���ְ� ���ÿ� PUSH
	// 4. ��⿭ ť�� �ƹ��� �������� �Ұ�����
	int N, myNum;
	bool isComplete = true;
	queue<int> waitingSpace;
	stack<int> tmpSpace;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> myNum;
		waitingSpace.push(myNum);
	}
	for (int i = 1; i <= N; i++)
	{
		if (tmpSpace.size() != 0)
		{
			if (tmpSpace.top() == i)
			{
				tmpSpace.pop();
				continue;
			}
		}
		while (waitingSpace.size() != 0 && waitingSpace.front() != i)
		{
			tmpSpace.push(waitingSpace.front());
			waitingSpace.pop();
		}
		if (waitingSpace.empty())
		{
			isComplete = false;
			break;
		}
		if (waitingSpace.front() == i) waitingSpace.pop();
	}
	if(isComplete)	cout << "Nice";
	else	cout << "Sad";
	return 0;
}