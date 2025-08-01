#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	// 대기열, 1열로 설 수 있는 공간, 통과 지점
	// 대기열에서 공간으로 이동은 되지만, 그 반대는 안 된다.
	// 대기열은 큐, 공간은 스택으로 만든다
	// 1. 공간 스택 맨 위에 다음 번호가 있는지 확인
	// 2. 없으면 대기열 큐 맨 앞에 다음 번호가 있는지 확인
	// 3. 없으면 대기열 큐 맨 앞에 다음 번호가 나올 때까지 POP해주고 스택에 PUSH
	// 4. 대기열 큐에 아무도 없어지면 불가능임
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