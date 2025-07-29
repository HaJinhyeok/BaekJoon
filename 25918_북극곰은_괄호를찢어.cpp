#include <iostream>
#include <stack>

using namespace std;

int CountDay(int num, const string& str);

int main()
{
	int N;
	int count = 0;
	string want;
	cin >> N;
	cin >> want;
	cout << CountDay(N, want);
	return 0;
}

int CountDay(int num, const string& str)
{
	// N�� Ȧ����? ������ -1
	if (num % 2 == 1)
		return -1;
	int count = 0;
	stack<char> check;
	// �� ���� ���鼭 ¦�� �´��� Ȯ�� + ���ÿ� ���� �ִ� ������ Ƚ��
	for (int i = 0;i < num;i++)
	{
		if (check.empty() || check.top() == str[i])
		{
			check.push(str[i]);
			if (check.size() > count)
			{
				count = check.size();
			}
		}
		else
		{
			check.pop();
		}
	}
	if (!check.empty())
		return -1;

	return count;
}