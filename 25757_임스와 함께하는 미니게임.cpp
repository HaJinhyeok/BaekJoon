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
		// 2인 -> 한 판 당 임스 제외 한 명 필요
		break;
	case 'F':
		// 3인 -> 한 판 당 임스 제외 두 명 필요
		count /= 2;
		break;
	case 'O':
		// 4인 -> 한 판 당 임스 제외 세 명 필요
		count /= 3;
		break;
	default:
		break;
	}
	cout << count;
	return 0;
}