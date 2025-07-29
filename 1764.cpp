#include<iostream>
#include<unordered_set>
#include<set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	string myEnter;
	unordered_set<string> myUSet;
	set<string> mySet;
	cin >> N >> M;
	while (N--)
	{
		cin >> myEnter;
		myUSet.insert(myEnter);
	}
	while (M--)
	{
		cin >> myEnter;
		if (myUSet.find(myEnter) != myUSet.end()) mySet.insert(myEnter);
	}
	cout << mySet.size() << '\n';
	for (auto iter : mySet) cout << iter << '\n';
	return 0;
}