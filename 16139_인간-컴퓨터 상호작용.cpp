#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// ASCII: a(97) ~ z(122)
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string givenStr;
	int left, right, question, i, j, tmpIdx;
	char alphabet;
	cin >> givenStr;

	int givenLen = givenStr.size();
	vector<vector<int> > countAlphabet(26, vector<int>(givenLen, 0));
	/*for (i = 0; i < givenLen; i++)
	{
		tmpIdx = givenStr[i] - 97;
		for (j = i; j < givenLen; j++)
		{
			countAlphabet[tmpIdx][j]++;
		}
	}*/

	countAlphabet[givenStr[0] - 97][0]++;
	for (i = 1; i < givenLen; i++)
	{
		tmpIdx = givenStr[i] - 97;
		for (j = 0; j < 26; j++)
		{
			if (j == tmpIdx) countAlphabet[j][i] = countAlphabet[j][i - 1] + 1;
			else countAlphabet[j][i] = countAlphabet[j][i - 1];
		}
	}

	cin >> question;
	while (question--)
	{
		cin >> alphabet >> left >> right;
		tmpIdx = alphabet - 97;
		if (left == 0)	cout << countAlphabet[tmpIdx][right] << '\n';
		else	cout << countAlphabet[tmpIdx][right] - countAlphabet[tmpIdx][left - 1] << '\n';
	}


	return 0;
}