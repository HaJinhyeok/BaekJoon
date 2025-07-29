#include <iostream>
#include <stack>

using namespace std;

bool IsPattern(string left, string right, string input);

int main()
{
	int N, i = 1;
	cin >> N;
	string pattern, input;
	cin >> pattern;
	while (pattern[i] != '*')
	{
		i++;
	}
	string left = pattern.substr(0, i);
	string right = pattern.substr(i + 1);
	while (N--)
	{
		cin >> input;
		if (IsPattern(left, right, input))
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;
}

bool IsPattern(string left,string right, string input)
{
	int inputLen = input.length();
	int leftLen = left.length();
	int rightLen = right.length();
	if (inputLen < leftLen + rightLen)
		return false;
	for (int i = 0;i < left.length();i++)
	{
		if (input[i] != left[i])
			return false;
	}
	for (int i = 0;i < right.length();i++)
	{
		if (input[inputLen - 1 - i] != right[rightLen - 1 - i])
			return false;
	}
	return true;
}