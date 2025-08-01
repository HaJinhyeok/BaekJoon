#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string myChat;
	// 채팅창 인원들이 채팅을 아직 안 쳤으면 false
	// 채팅창 인원들이 채팅을 한 번이라도 쳤으면 true
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
			// 채팅 기록이 없거나 value가 false인 사람(key)이면 카운트 증가. 두 조건 따로 써야하나?
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