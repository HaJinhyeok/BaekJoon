#include <iostream>

using namespace std;

/*
다음 문자가 ')'인 '('가 들어오기 전까지 '(' 쌓인 막대 개수 카운트
'(' 뒤에 바로 ')'가 오면 레이저이의 절단 위치이므로 현재까지 카운트된 만큼 막대 개수 더해주기
')' 뒤에 나오는 ')'는 막대기의 끝을 말하므로 쌓인 막대 개수 카운트 -1 해주고 막대 개수 +1
*/

int main()
{
	int currentBar = 0;
	int numOfSlice = 0;
	string input;
	cin >> input;
	for (int i = 0;i < input.length();i++)
	{
		if (input[i] == '(')
		{
			if (input[i + 1] == ')')
			{
				numOfSlice += currentBar;
			}
			else
			{
			currentBar++;
			}
		}
		else if (input[i] == ')' && input[i - 1] == ')')
		{
			currentBar--;
			numOfSlice++;
		}
	}
	cout << numOfSlice;
	return 0;
}