#include<iostream>
#include<deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<int> myDeq;
	int N, order, X;
	cin >> N;
	while (N--)
	{
		cin >> order;
		switch (order)
		{
		case 1:
			cin >> X;
			myDeq.push_front(X);
			break;
		case 2:
			cin >> X;
			myDeq.push_back(X);
			break;
		case 3:
			if (myDeq.size() == 0) cout << -1 << '\n';
			else
			{
				cout << myDeq.front() << '\n';
				myDeq.pop_front();
			}
			break;
		case 4:
			if (myDeq.size() == 0) cout << -1 << '\n';
			else
			{
				cout << myDeq.back() << '\n';
				myDeq.pop_back();
			}
			break;
		case 5:
			cout << myDeq.size() << '\n';
			break;
		case 6:
			if (myDeq.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
			break;
		case 7:
			if (myDeq.size() == 0) cout << -1 << '\n';
			else cout << myDeq.front() << '\n';
			break;
		case 8:
			if (myDeq.size() == 0) cout << -1 << '\n';
			else cout << myDeq.back() << '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}