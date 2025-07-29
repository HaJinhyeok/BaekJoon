#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
void DFS(vector<vector<int>>& adjacent, int start);
void BFS(vector<vector<int>>& adjacent, int start);

int main()
{
	int N, M, V;
	int v1, v2;
	cin >> N >> M >> V;
	vector<vector<int>> adjacent(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		adjacent[v1].push_back(v2);
		adjacent[v2].push_back(v1);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(adjacent[i].begin(), adjacent[i].end());
	}
	DFS(adjacent, V);
	cout << '\n';
	BFS(adjacent, V);
	return 0;
}

void DFS(vector<vector<int>>& adjacent, int start)
{
	int len = adjacent.size();
	vector<bool> check(len + 1);
	stack<int> myStack;
	check[start] = true;
	cout << start << ' ';
	myStack.push(start);
	while (!myStack.empty())
	{
		int last = myStack.top();
		int i;
		for (i = 0; i < adjacent[last].size(); i++)
		{
			if (!check[adjacent[last][i]])
			{
				myStack.push(adjacent[last][i]);
				cout << adjacent[last][i] << ' ';
				check[adjacent[last][i]] = true;
				break;
			}
		}
		if (i == adjacent[last].size())
		{
			myStack.pop();
		}
	}
}

void BFS(vector<vector<int>>& adjacent, int start)
{
	int len = adjacent.size();
	vector<bool> check(len + 1);
	queue<int> myQueue;
	check[start] = true;
	myQueue.push(start);
	while (!myQueue.empty())
	{
		int first = myQueue.front();
		cout << first << ' ';
		myQueue.pop();
		for (int i = 0; i < adjacent[first].size(); i++)
		{
			if (!check[adjacent[first][i]])
			{
				myQueue.push(adjacent[first][i]);
				check[adjacent[first][i]] = true;
			}
		}
	}
}