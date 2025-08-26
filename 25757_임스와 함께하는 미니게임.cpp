#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	int num;
	int count;
	char play;
	string enter;
	set<string> people;
	cin >> num >> play;
	while (num--)
	{
		cin >> enter;
		people.insert(enter);
	}
	count = people.size();
	switch (play)
	{
	case 'Y':
		// 2�� -> �� �� �� �ӽ� ���� �� �� �ʿ�
		break;
	case 'F':
		// 3�� -> �� �� �� �ӽ� ���� �� �� �ʿ�
		count /= 2;
		break;
	case 'O':
		// 4�� -> �� �� �� �ӽ� ���� �� �� �ʿ�
		count /= 3;
		break;
	default:
		break;
	}
	cout << count;
	return 0;
}