#include<iostream>
#include<vector>
#include<climits>

using namespace std;
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