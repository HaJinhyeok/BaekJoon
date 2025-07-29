#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int numVer, numEdge, startIdx;
	int start, finish, weight;
	const int inf = INT_MAX;

	cin >> numVer >> numEdge;
	vector<pair<int, int>> adjacent[20001];

	vector<int> cost(numVer + 1, inf);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

	cin >> startIdx;
	for (int i = 0; i < numEdge; i++)
	{
		cin >> start >> finish >> weight;
		adjacent[start].push_back(make_pair(finish, weight));
	}

	//// dijkstra
	cost[startIdx] = 0;
	pq.push(make_pair(0, startIdx));
	while (!pq.empty())
	{
		// ( 현재 노드까지의 비용 cost, 현재 노드의 번호 currentIdx )
		int currentCost = pq.top().first;
		int currentIdx = pq.top().second;
		pq.pop();

		for (int i = 0; i < adjacent[currentIdx].size(); i++)
		{
			int dstIdx = adjacent[currentIdx][i].first;
			int dstCost = adjacent[currentIdx][i].second;

			if (currentCost + dstCost < cost[dstIdx])
			{
				cost[dstIdx] = currentCost + dstCost;
				pq.push(make_pair(cost[dstIdx], dstIdx));
			}

		}
	}

	for (int i = 1; i <= numVer; i++)
	{
		if (cost[i] >= inf)
			printf("INF\n");
		else
			printf("%d\n", cost[i]);
	}

	return 0;
}