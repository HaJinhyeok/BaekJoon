#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, x, y;
	vector<int> xCoordinates;
	vector<int> yCoordinates;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		xCoordinates.push_back(x);
		yCoordinates.push_back(y);
	}
	if (N == 1) cout << 0;
	else {
		sort(xCoordinates.begin(), xCoordinates.end());
		sort(yCoordinates.begin(), yCoordinates.end());
		cout << (xCoordinates.back() - xCoordinates.front()) * (yCoordinates.back() - yCoordinates.front());
	}
	
	return 0;
}