#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// �޺� ���찡 �޺� ���뺸�� ���� ������ �� �ִ� ���� �׷��ͱ��� ����
int countStub = 0;
// �޺� ���찡 �� �׷��ͱ�� ���µ� �ʿ��� �ð�
double foxDistance[4001] = { 0, };
// �޺� ���밡 �� ����ͱ�� ���µ� �ʿ��� �ð�
vector<pair<double,double>> wolfDistance;

void FoxDijkstra(vector<vector<int>> adjacentList);
void WolfDijkstra(vector<vector<int>> adjacentList);

int main()
{
	int stub, path, i;
	int start, finish, distance;
	cin >> stub >> path;
	// <���� �׷��ͱ�, �Ÿ�>
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
	���뿡 ���� Dijkstra�� ���� �����־�� ��!!! �׳��ϴϱ� �����ϳ�
	Flag �������� �������־�� �ҵ�
	+ i�� �׷��ͱ�� �پ���� �ð��� �� �ּڰ��� �ɾ���� �ð��� �� �ּڰ��� ������ �־�� �ҵ�? �׷��� ���� �̵��� 
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
	int len = adjacentList.size() - 1; // �׷��ͱ� ����
	queue<int> stubQueue;
	vector<bool> isVisited(len + 1);
	// ����� ������ 1��(==0��) �׷��ͱ�
	stubQueue.push(1);
	isVisited[1] = true;
	// ����� distance �״�� �ð�����,
	foxDistance[1] = 0;

	// BFS�� Ȱ���� Dijkstra
	while (!stubQueue.empty())
	{
		int start = stubQueue.front();
		for (int i = 1; i <= len; i++)
		{
			// �Ÿ��� 0�̰ų�, �̹� Ȯ���� �׷��ͱ�� �н�
			if (adjacentList[start][i] == 0)
				continue;
			if (isVisited[i])
				continue;

			stubQueue.push(i);
			isVisited[i] = true;
			// ���� ���
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
	int len = adjacentList.size() - 1; // �׷��ͱ� ����
	
	queue<int> stubQueue;
	vector<bool> isVisited(len + 1, false);
	vector<bool> isQueued(len + 1, false); // BFS ť�� ���Ծ����� Ȯ��

	// ����� ������ 1��(==0��) �׷��ͱ�
	stubQueue.push(1);
	isQueued[1] = true;
	isVisited[1] = true;
	// ����� �� ���� distance / 2, �� ���� distance * 2
	// ����: double������ ����� ��
	// first�� ������ ���� �ӵ��� ������ �ð�
	// seconde�� ������ ���� �ӵ��� ������ �ð�
	wolfDistance[1].first = 0;
	wolfDistance[1].second = 0;

	// BFS�� Ȱ���� Dijkstra
	while (!stubQueue.empty())
	{
		int start = stubQueue.front();
		isVisited[start] = true;
		for (int i = 1; i <= len; i++)
		{
			// �Ÿ��� 0�̸� �н�
			if (adjacentList[start][i] == 0)
				continue;

			if (!isQueued[i])
			{
				stubQueue.push(i);
				isQueued[i] = true;
			}

			// ���� ���
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