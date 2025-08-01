#include<iostream>
#include<string>
using namespace std;

int main() {
	string myString;
	bool isPalindrome = true;
	cin >> myString;
	int length = myString.size();
	float myPivot = (float)length / 2;
	for (int i = 0; i < myPivot; i++)
	{
		if (myString[i] != myString[length - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}
	cout << isPalindrome;
	return 0;
}