#include <iostream>

using namespace std;

int main()
{
	int test, countNot = 0;
	bool isFactorial = false, currentInteger = false;
	string input;
	cin >> test;
	while (test--)
	{
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '0')
			{
				currentInteger = false;
				isFactorial = true;
			}
			else if (input[i] == '1')
			{
				currentInteger = true;
				isFactorial = true;
			}
			else if (!isFactorial && input[i] == '!')
			{
				countNot++;
			}
			else
			{
				currentInteger = true;
			}
		}
		if (countNot % 2 == 1) currentInteger = !currentInteger;
		printf("%d\n", currentInteger);

		input.clear();
		countNot = 0;
		isFactorial = false;
	}
	return 0;
}