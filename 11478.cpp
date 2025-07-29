#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
	int i, j, len;
	string myStr;
	unordered_set<string> mySet;
	cin >> myStr;
	len = myStr.size();
	for (i = 0; i < len; i++)
	{
		for (j = len - i; j > 0; j--)
		{
			mySet.insert(myStr.substr(i, j));
		}
	}
	cout << mySet.size();
	return 0;
}