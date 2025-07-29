#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, enter, answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	while (N--)
	{
		cin >> enter;
		pq.push(enter);
	}
	while (!pq.empty())
	{
		if (pq.top() > answer + 1)
		{
			answer++;
			break;
		}
		else
		{
			answer += pq.top();
			pq.pop();
		}
	}
	if (pq.empty())
		cout << answer + 1;
	else
		cout << answer;
	return 0;
}