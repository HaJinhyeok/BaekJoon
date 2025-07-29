#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 1. 빈도수
// 2. 단어 길이
// 3. 알파벳 사전 순

bool compare(pair<string, int> a, pair<string, int> b)
{
	if (a.second != b.second) return a.second > b.second;
	else if (a.first.length() != b.first.length()) return a.first.length() > b.first.length();
	else return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	string myString;
	map<string, int> vocaMap;
	vector< pair<string, int> >::iterator iter;
	cin >> N >> M;
	while (N--)
	{
		cin >> myString;
		if (myString.length() < M) continue;
		else
		{
			if (vocaMap.find(myString) == vocaMap.end())
			{
				vocaMap[myString] = 1;
			}
			else vocaMap[myString]++;
		}
	}
	vector< pair<string, int> > vocaVec(vocaMap.begin(), vocaMap.end());
	sort(vocaVec.begin(), vocaVec.end(), compare);
	for (auto& iter : vocaVec)
	{
		cout << iter.first << '\n';
	}
	return 0;
}