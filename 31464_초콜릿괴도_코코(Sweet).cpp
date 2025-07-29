#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	string input;
	cin >> N;
	vector<vector<char>> chocolate(N, vector<char>(N));
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		for (int j = 0; j < N; j++)
		{
			chocolate[i][j] = input[j];
		}
	}

	return 0;
}