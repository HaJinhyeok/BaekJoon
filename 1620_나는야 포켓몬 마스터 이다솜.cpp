#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, i;
	string myStr;
	vector<string> myVec;
	unordered_map<string, int> myMap;
	cin >> N >> M;
	for (i = 1; i <= N; i++)
	{
		cin >> myStr;
		myVec.push_back(myStr);
		myMap.insert({ myStr,i });
	}
	while (M--)
	{
		cin >> myStr;
		// 숫자가 입력됐을 경우 - vector
		if (myStr[0] >= 48 && myStr[0] <= 57)
		{
			cout << myVec[stoi(myStr)-1] << '\n';
		}
		// 문자열이 입력됐을 경우 - map
		else
		{
			cout << myMap[myStr] << '\n';
		}
	}
	return 0;
}