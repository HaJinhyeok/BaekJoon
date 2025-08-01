#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(vector<int> vec1, vector<int> vec2)
{
	if (vec1[0] == vec2[0])
		return vec1[1] < vec2[1];
	else return vec1[0] < vec2[0];
}

int countMeeting(vector<vector<int> > table, int idx, int finish, int nCount)
{
	int i;
	if (idx == table.size() - 1) return nCount;
	for (i = idx + 1; i < table.size(); i++)
	{
		if (table[i][0] >= finish)
		{
			finish = table[i][1];
			nCount++;
			return countMeeting(table, i, finish, nCount);
		}
	}
	return nCount;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, start, end;
	int i, j;
	cin >> N;
	vector<vector<int> > timeTable(N, vector<int>(2));
	for (i = 0; i < N; i++)
	{
		cin >> start >> end;
		timeTable[i][0] = start;
		timeTable[i][1] = end;
	}
	sort(timeTable.begin(), timeTable.end(), compare);
	for (auto iter : timeTable)
		cout << "start: " << iter[0] << ", end: " << iter[1] << '\n';
	cout << "Size of double vector: " << timeTable.size();

	return 0;
}