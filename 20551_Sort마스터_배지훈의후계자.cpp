#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, enter;
	priority_queue<int,vector<int>, greater<int>> pq;
	unordered_map<int, int> umap;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> enter;
		pq.push(enter);
	}
	int i = 0;
	int top;
	while (!pq.empty())
	{
		top = pq.top();
		pq.pop();
		// 없으면 unordered_map에 추가
		if (umap.find(top) == umap.end())
		{
			umap.insert(make_pair(top, i));

		}
		i++;
	}
	for (int j = 0; j < M; j++)
	{
		cin >> enter;
		cout << ((umap.find(enter) != umap.end()) ? umap[enter] : -1) << '\n';
	}
	return 0;
}