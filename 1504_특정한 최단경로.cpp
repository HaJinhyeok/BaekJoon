#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;
using ll = long long;
/*
3주차 정기 스터디 수업 문제
로직:
1 -> N
1 -> v1 -> v2 -> N
1 -> v2 -> v1 -> N

최단 경로 : BFS
+ 가중치 --> 다익스트라!

다익스트라를 함수로 하나 만들어 주고,
1 -> v1 -> v2 -> N
1 -> v2 -> v1 -> N
>> 더 짧은 쪽 출력해주면 될듯?
*/
ll Dijkstra(vector<vector<int>>& adjacent, int start, int end, int num);

int main()
{
	int N, E;
	int a, b, c;
	int v1, v2;
	ll len1, len2, len3, len4, len5;
	const ll fail = -1;
	cin >> N >> E;
	vector<vector<int>> adjacent(N + 1, vector<int>(N + 1, INT32_MAX));
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		adjacent[a][b] = c;
		adjacent[b][a] = c;
	}
	cin >> v1 >> v2;
	len1 = Dijkstra(adjacent, 1, v1, N);
	len2 = Dijkstra(adjacent, 1, v2, N);
	len3 = Dijkstra(adjacent, v1, v2, N);
	len4 = Dijkstra(adjacent, v1, N, N);
	len5 = Dijkstra(adjacent, v2, N, N);
	if (len3 == fail)
	{
		cout << fail;
	}
	else
	{
		ll d1 = (len1 == fail) ? fail : ((len5 == fail) ? fail : len1 + len3 + len5);
		ll d2 = (len2 == fail) ? fail : ((len4 == fail) ? fail : len2 + len3 + len4);
		ll d = (d1 == fail) ? ((d2 == fail) ? fail : d2) : ((d2 == fail) ? d1 : min(d1, d2));
		cout << d;
	}


	return 0;
}

ll Dijkstra(vector<vector<int>>& adjacent, int start, int end, int num)
{
	vector<ll> distance(num + 1, INT32_MAX);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		auto [dis, ver] = pq.top();
		pq.pop();
		if (dis != distance[ver])	continue;

		for (int i = 1; i <= num; i++)
		{
			if (adjacent[ver][i] == INT32_MAX)	continue;
			if (distance[i] > distance[ver] + adjacent[ver][i])
			{
				distance[i] = distance[ver] + adjacent[ver][i];
				pq.push({ distance[i], i });
			}
		}
	}
	return distance[end];
}