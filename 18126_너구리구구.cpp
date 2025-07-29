#include <iostream>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

ll distances[5001];
priority_queue<ll> pq;
ll Dijkstra(vector<vector<pair<int, int>>>& adjacent, int num);

int main()
{
	int N;
	int a, b, c;
	cin >> N;
	vector<vector<pair<int, int>>> adjacent(N + 1);
	for (int i = 0;i < N - 1;i++)
	{
		cin >> a >> b >> c;
		adjacent[a].push_back(make_pair(b, c));
		adjacent[b].push_back(make_pair(a, c));
	}
	cout << Dijkstra(adjacent, N);
	return 0;
}
ll Dijkstra(vector<vector<pair<int, int>>>& adjacent, int num)
{
	int current;
	queue<int> myQue;
	vector<bool> check(num + 1);
	myQue.push(1);
	while (!myQue.empty())
	{
		current = myQue.front();
		check[current] = true;
		for (auto i : adjacent[current])
		{
			if (!check[i.first])
			{
				myQue.push(i.first);
			}
			else
			{
				continue;
			}
			if (distances[i.first] < distances[current] + i.second)
			{
				distances[i.first] = distances[current] + i.second;
			}
		}
		myQue.pop();
	}
	for (int i = 1;i <= num;i++)
	{
		pq.push(distances[i]);
	}
	return pq.top();
}