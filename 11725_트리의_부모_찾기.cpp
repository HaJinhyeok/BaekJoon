#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, i, first, second, j;
	cin >> N;
	vector<vector<int> > adjList(N);
	vector<int> parent(N);
	// 1은 루트 노드이므로 그냥 부모를 0으로 생각
	parent[0] = 0;
	// 입력 받기
	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &first, &second);
		if (first == 1)
		{
			adjList[first - 1].emplace_back(second - 1);
		}
		else if (second == 1)
		{
			adjList[second - 1].emplace_back(first - 1);
		}
		else
		{
			adjList[first - 1].emplace_back(second - 1);
			adjList[second - 1].emplace_back(first - 1);
		}
	}
	// bfs
	queue<int> myQueue;
	vector<bool> isChecked(N, false);
	int front;
	myQueue.push(0);
	while (!myQueue.empty())
	{
		front = myQueue.front();
		for (j = 0; j < adjList[front].size(); j++)
		{
			if (isChecked[adjList[front][j]])
				continue;
			else
			{
				myQueue.push(adjList[front][j]);
				parent[adjList[front][j]] = front;
			}
		}
		isChecked[front] = true;
		myQueue.pop();
	}
	for (i = 1; i < N; i++)
		cout << parent[i] + 1 << '\n';

	return 0;
}