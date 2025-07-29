#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 달빛 여우가 달빛 늑대보다 먼저 도착할 수 있는 나무 그루터기의 개수
int countStub = 0;
// 달빛 여우가 각 그루터기로 가는데 필요한 시간
double foxDistance[4001] = { 0, };
// 달빛 늑대가 각 드루터기로 가는데 필요한 시간
vector<pair<double,double>> wolfDistance;

void FoxDijkstra(vector<vector<int>> adjacentList);
void WolfDijkstra(vector<vector<int>> adjacentList);

int main()
{
	int stub, path, i;
	int start, finish, distance;
	cin >> stub >> path;
	// <도착 그루터기, 거리>
	vector<vector<int>> adjacentList(stub + 1, vector<int>(stub + 1));
	for (i = 0; i < path; i++)
	{
		cin >> start >> finish >> distance;
		adjacentList[start][finish] = distance;
		adjacentList[finish][start] = distance;
	}
	for (i = 0; i <= stub; i++)
	{
		foxDistance[i] = 12345678900;
		wolfDistance.push_back(make_pair(12345678900, 12345678900));
	}

	// Dijkstra
	FoxDijkstra(adjacentList);
	WolfDijkstra(adjacentList);
	
	/*
	늑대에 대해 Dijkstra를 따로 구해주어야 함!!! 그냥하니까 개망하네
	Flag 정보까지 저장해주어야 할듯
	+ i번 그루터기로 뛰어들어온 시간들 중 최솟값과 걸어들어온 시간들 중 최솟값도 가지고 있어야 할듯? 그래야 다음 이동시 
	*/

	for (i = 1; i <= stub; i++)
	{
		if (foxDistance[i] < min(wolfDistance[i].first, wolfDistance[i].second))
			countStub++;
	}

	cout << countStub;
	return 0;
}

void FoxDijkstra(vector<vector<int>> adjacentList)
{
	int len = adjacentList.size() - 1; // 그루터기 개수
	queue<int> stubQueue;
	vector<bool> isVisited(len + 1);
	// 출발은 무조건 1번(==0번) 그루터기
	stubQueue.push(1);
	isVisited[1] = true;
	// 여우는 distance 그대로 시간으로,
	foxDistance[1] = 0;

	// BFS를 활용한 Dijkstra
	while (!stubQueue.empty())
	{
		int start = stubQueue.front();
		for (int i = 1; i <= len; i++)
		{
			// 거리가 0이거나, 이미 확인한 그루터기면 패스
			if (adjacentList[start][i] == 0)
				continue;
			if (isVisited[i])
				continue;

			stubQueue.push(i);
			isVisited[i] = true;
			// 여우 계산
			double newDistance = foxDistance[start] + adjacentList[start][i];
			if (foxDistance[i] > newDistance)
			{
				foxDistance[i] = newDistance;
			}
		}
		stubQueue.pop();
	}
}

void WolfDijkstra(vector<vector<int>> adjacentList)
{
	int len = adjacentList.size() - 1; // 그루터기 개수
	
	queue<int> stubQueue;
	vector<bool> isVisited(len + 1, false);
	vector<bool> isQueued(len + 1, false); // BFS 큐에 들어왔었는지 확인

	// 출발은 무조건 1번(==0번) 그루터기
	stubQueue.push(1);
	isQueued[1] = true;
	isVisited[1] = true;
	// 늑대는 한 번은 distance / 2, 한 번은 distance * 2
	// 주의: double형으로 계산할 것
	// first는 직전에 느린 속도로 왔을때 시간
	// seconde는 직전에 빠른 속도로 왔을때 시간
	wolfDistance[1].first = 0;
	wolfDistance[1].second = 0;

	// BFS를 활용한 Dijkstra
	while (!stubQueue.empty())
	{
		int start = stubQueue.front();
		isVisited[start] = true;
		for (int i = 1; i <= len; i++)
		{
			// 거리가 0이면 패스
			if (adjacentList[start][i] == 0)
				continue;

			if (!isQueued[i])
			{
				stubQueue.push(i);
				isQueued[i] = true;
			}

			// 늑대 계산
			if (start == 1)
			{
				wolfDistance[i].second = adjacentList[start][i] / (double)2;
			}
			else
			{
				double tmpRun = wolfDistance[start].first + adjacentList[start][i] / (double)2;
				double tmpWalk = wolfDistance[start].second + adjacentList[start][i] * (double)2;
				if (wolfDistance[i].first > tmpWalk)
				{
					wolfDistance[i].first = tmpWalk;
				}
				if (wolfDistance[i].second > tmpRun)
				{
					wolfDistance[i].second = tmpRun;
				}
			}
			
		}
		stubQueue.pop();
	}
}