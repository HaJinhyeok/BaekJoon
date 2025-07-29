#include <iostream>
#include <set>

using namespace std;

int main()
{
	int N, x, y;
	cin >> N;
	set<int> setX, setY, setLineX, setLineY;
	while (N--)
	{
		cin >> x >> y;
		if (setX.find(x) != setX.end())
		{
				setLineX.insert(x);
		}
		else
		{
			setX.insert(x);
		}
		if (setY.find(y) != setY.end())
		{
			setLineY.insert(y);
		}
		else
		{
			setY.insert(y);
		}
	}
	cout << setLineX.size() + setLineY.size();


	return 0;
}