#include<iostream>
#include<vector>
#include<climits>

using namespace std;
/*
3���� ���� ���͵� ���� ����
����:
1 -> N
1 -> v1 -> v2 -> N
1 -> v2 -> v1 -> N

�ִ� ��� : BFS
+ ����ġ --> ���ͽ�Ʈ��!

���ͽ�Ʈ�� �Լ��� �ϳ� ����� �ְ�,
1 -> v1 -> v2 -> N
1 -> v2 -> v1 -> N
>> �� ª�� �� ������ָ� �ɵ�?
*/
int main()
{
	int N, E;
	int a, b, c;
	vector<vector<int>> adjacent(N+1,vector<int>(N+1));
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		adjacent[a][b] = c;
		adjacent[b][a] = c;
	}
	return 0;
}

vector<int>& Dijkstra(vector<vector<int>>& adjacent, int start)
{

}