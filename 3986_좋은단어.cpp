#include<iostream>
#include<stack>

using namespace std;

bool IsGood(string str);

int main()
{
	int N, count = 0;
	string input;
	cin >> N;
	while (N--)
	{
		cin >> input;
		if (IsGood(input))
			count++;
	}
	cout << count;
	return 0;
}

bool IsGood(string str)
{
	int len = str.length();
	if (len % 2)
		return false;

	stack<char> myStack;
	for (int i = 0;i < len;i++)
	{
		if (myStack.empty())
		{
			myStack.push(str[i]);
		}
		else if (myStack.top() == 'A')
		{
			if (str[i] == 'A')
				myStack.pop();
			else
				myStack.push(str[i]);
		}
		else if (myStack.top() == 'B')
		{
			if (str[i] == 'B')
				myStack.pop();
			else
				myStack.push(str[i]);
		}
	}
	return myStack.empty();
}