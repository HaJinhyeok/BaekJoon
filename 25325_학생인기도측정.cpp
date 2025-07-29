#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

struct comp
{
	bool operator()(pair<string, int> a, pair<string, int> b)
	{
		if (a.second == b.second)
			return strcmp(a.first.c_str(), b.first.c_str()) > 0;
		else
			return a.second < b.second;
	}
};

int main()
{
	int N;
	string enter, tmp="";
	map<string, int> count;
	priority_queue<pair<string, int>, vector<pair< string, int >>, comp> pq;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> enter;
		count[enter] = 0;
	}
	getchar();
	for (int i = 0;i < N;i++)
	{
		getline(cin, enter);
		for (int i = 0;i < enter.size();i++)
		{
			if (enter[i] == ' ')
			{
				count[tmp]++;
				tmp.clear();
			}
			else
			{
			tmp += enter[i];
			}
		}
		count[tmp]++;
		tmp.clear();
	}
	for (auto i : count)
	{
		pq.push(i);
	}
	while (!pq.empty())
	{
		cout << pq.top().first << ' ' << pq.top().second << '\n';
		pq.pop();
	}
	return 0;
}
