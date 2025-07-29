#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool compare(string str1, string str2)
{
	return str1 > str2;
}

int main()
{
	int numOfLog;
	string sName, sEnter;
	unordered_set<string> nameSet;
	cin >> numOfLog;
	while (numOfLog--)
	{
		cin >> sName >> sEnter;
		if (sEnter == "enter")	nameSet.insert(sName);
		else if (sEnter == "leave") nameSet.erase(sName);
	}
	vector<string> nameVec(nameSet.begin(), nameSet.end());
	sort(nameVec.begin(), nameVec.end(), compare);
	for (auto iter : nameVec) cout << iter << '\n';
	return 0;
}