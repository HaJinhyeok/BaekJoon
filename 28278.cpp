#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, X;
	string firstLine;
	vector<int> myStack;
	cin >> N;
	cin.ignore();
	while (N--)
	{
		getline(cin, firstLine);
		switch (firstLine[0])
		{
		case '1': 
			firstLine.erase(0, 2);
			X = stoi(firstLine);
			myStack.push_back(X);
			break;
		case '2':
			if (myStack.empty()) cout << -1 << '\n';
			else
			{
				cout << myStack.back() << '\n';
				myStack.pop_back();
			}
			break;
		case '3':
			cout << myStack.size() << '\n';
			break;
		case '4':
			if (myStack.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		case '5':
			if (myStack.empty()) cout << -1 << '\n';
			else cout << myStack.back() << '\n';
			break;
		default:
			break;
		}
		
	}
	return 0;
}

//1 X: ���� X�� ���ÿ� �ִ´�. (1 �� X �� 100, 000)
//2 : ���ÿ� ������ �ִٸ� �� ���� ������ ���� ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�.
//3 : ���ÿ� ����ִ� ������ ������ ����Ѵ�. 
//4 : ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
//5 : ���ÿ� ������ �ִٸ� �� ���� ������ ����Ѵ�.���ٸ� - 1�� ��� ����Ѵ�.