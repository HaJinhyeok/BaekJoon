#include <iostream>

using namespace std;

/*
���� ���ڰ� ')'�� '('�� ������ ������ '(' ���� ���� ���� ī��Ʈ
'(' �ڿ� �ٷ� ')'�� ���� ���������� ���� ��ġ�̹Ƿ� ������� ī��Ʈ�� ��ŭ ���� ���� �����ֱ�
')' �ڿ� ������ ')'�� ������� ���� ���ϹǷ� ���� ���� ���� ī��Ʈ -1 ���ְ� ���� ���� +1
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