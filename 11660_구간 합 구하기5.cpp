#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, i, j, myEnter, result = 0;
	int x1, x2, y1, y2;
	cin >> N >> M;
	vector< vector<int> >TwoDimSum(N + 1, vector<int>(N + 1));
	for (i = 0; i <= N; i++) TwoDimSum[i][0] = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> myEnter;
			TwoDimSum[i][j] = TwoDimSum[i][j - 1] + myEnter;
		}
	}
	while (M--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		result = 0;
		for (i = x1; i <= x2; i++)
		{
			// ( S_x1y2 - S_x1(y1-1) ) + ... + ( S_x2y2 - S_x2(y2-1) )
			result += TwoDimSum[i][y2] - TwoDimSum[i][y1 - 1];
		}
		cout << result << '\n';
	}
	return 0;
}