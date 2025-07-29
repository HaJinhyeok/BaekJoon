#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string myChat;
	// ä��â �ο����� ä���� ���� �� ������ false
	// ä��â �ο����� ä���� �� ���̶� ������ true
	map<string, bool> nameList;
	map<string, bool>::iterator iter;
	//vector<string> nameList;
	int N, count = 0;
	cin >> N;
	while (N--)
	{
		cin >> myChat;
		if (myChat == "ENTER")
		{
			for (auto& iter : nameList)
				iter.second = false;
		}
		else
		{
			// ä�� ����� ���ų� value�� false�� ���(key)�̸� ī��Ʈ ����. �� ���� ���� ����ϳ�?
			if (nameList.find(myChat) == nameList.end() || nameList[myChat] == false)
			{
				count++;
				nameList[myChat] = true;
			}
		}
	}
	cout << count;
	return 0;
}