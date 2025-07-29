#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>

using namespace std;

typedef struct {
	int Age;
	string Name;
}User;

bool compareAge(User first, User second)
{
	return first.Age < second.Age;
}

int main()
{
	int N, age;
	string name;
	User tmp;
	vector<User> userList;

	cin >> N;
	while (N--)
	{
		cin >> age >> name;
		tmp.Age = age;
		tmp.Name = name;
		userList.push_back(tmp);
	}
	// c++ algorithm의 일반 sort는 퀵정렬이라서 unstable sort라고 한다!!!
	stable_sort(userList.begin(), userList.end(), compareAge);

	vector<User>::iterator iter;
	for (iter = userList.begin(); iter != userList.end(); iter++) cout << iter->Age << ' ' << iter->Name << '\n';

	return 0;
}