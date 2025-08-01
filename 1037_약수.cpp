#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int numOfDiv, result;
	cin >> numOfDiv;
	vector<int> myDiv(numOfDiv);
	for (int i = 0; i < numOfDiv; i++)	cin >> myDiv[i];
	if (numOfDiv == 1) result = myDiv[0] * myDiv[0];
	else
	{
		sort(myDiv.begin(), myDiv.end());
		result = myDiv[0] * myDiv[numOfDiv - 1];
	}
	cout << result;

	return 0;
}