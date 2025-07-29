#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Coordinates {
public:
	int xAxis;
	int yAxis;
	int Value;
	Coordinates(int x, int y, int v);
};
Coordinates::Coordinates(int x, int y, int v)
{
	xAxis = x;
	yAxis = y;
	Value = v;
}
bool Compare(Coordinates first, Coordinates second)
{
	return first.Value < second.Value;
}
int main()
{
	int givenValue;
	vector<Coordinates> givenNumber;
	vector<Coordinates> myVector;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> givenValue;
			givenNumber.push_back(Coordinates(i, j, givenValue));
		}
		sort(givenNumber.begin(), givenNumber.end(), Compare);
		myVector.push_back(givenNumber.back());
		givenNumber.clear();
	}
	sort(myVector.begin(), myVector.end(), Compare);
	cout << myVector.back().Value << '\n' << myVector.back().xAxis + 1 << ' ' << myVector.back().yAxis + 1;
	
	return 0;
}