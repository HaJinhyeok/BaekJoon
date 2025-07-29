#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, len;
	cin >> N;
	vector<string> myStr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> myStr[i];
	}
	len = myStr[0].length();
	vector<char> result(len);
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == 0)
				result[i] = myStr[j][i];
			else
			{
				if (result[i] != myStr[j][i])
				{
					result[i] = '?';
				}

			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		cout << result[i];
	}
	return 0;
}