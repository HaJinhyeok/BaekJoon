#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, nEnter;
	unordered_set<int> mySet;
	cin >> N >> M;
	while (N--)
	{
		cin >> nEnter;
		mySet.insert(nEnter);
	}
	while (M--)
	{
		cin >> nEnter;
		if (mySet.find(nEnter) != mySet.end()) mySet.erase(nEnter);
		else mySet.insert(nEnter);
	}
	cout << mySet.size();
	return 0;
}