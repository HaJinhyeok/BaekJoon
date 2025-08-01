#include<iostream>

using namespace std;

int nCount = 0;

bool recursion(const string& myStr, int first, int last)
{
	nCount++;
	if (first >= last) return true;
	else if (myStr[first] != myStr[last])	return false;
	else	return recursion(myStr, first + 1, last - 1);

}

bool isPalindrome(const string& myStr)
{
	return recursion(myStr, 0, myStr.length() - 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, result;
	string myEnter;
	cin >> T;
	while (T--)
	{
		cin >> myEnter;
		result = isPalindrome(myEnter);
		cout << result << ' ' << nCount << '\n';
		nCount = 0;
	}
	return 0;
}