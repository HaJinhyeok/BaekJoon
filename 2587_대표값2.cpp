#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> myInt;
	int N, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> N;
		myInt.push_back(N);
		sum += N;
	}
	sort(myInt.begin(), myInt.end());
	cout << sum / 5 << '\n' << myInt[2];

	return 0;
}