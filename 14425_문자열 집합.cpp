#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
	unordered_set<string> myStrSet;
	int N, M;
	unsigned int nCount = 0;
	string myEnter;
	cin >> N >> M;
	while (N--)
	{
		cin >> myEnter;
		myStrSet.insert(myEnter);
	}
	while (M--)
	{
		cin >> myEnter;
		// 찾고, 있으면 count
		if (myStrSet.find(myEnter) != myStrSet.end()) nCount++;
	}
	cout << nCount;
	return 0;
}