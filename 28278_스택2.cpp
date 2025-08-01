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

//1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100, 000)
//2 : 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다.없다면 - 1을 대신 출력한다.
//3 : 스택에 들어있는 정수의 개수를 출력한다. 
//4 : 스택이 비어있으면 1, 아니면 0을 출력한다.
//5 : 스택에 정수가 있다면 맨 위의 정수를 출력한다.없다면 - 1을 대신 출력한다.