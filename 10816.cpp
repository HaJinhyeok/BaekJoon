#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, nEnter;
	unordered_map<int, int> myMap;
	cin >> N;
	while (N--)
	{
		cin >> nEnter;
		myMap[nEnter]++;
	}
	cin >> M;
	while (M--)
	{
		cin >> nEnter;
		cout << myMap[nEnter] << ' ';
	}
	return 0;
}