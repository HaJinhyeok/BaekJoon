#include<iostream>

using namespace std;

int main() {
	int first, second, third;
	int max;
	while (1)
	{
		cin >> first >> second >> third;
		if (!first) break;
		max = (first > second) && (first > third) ? first : (second > third) ? second : third; 
		if (max == first)
		{
			if (first >= second + third)
			{
				cout << "Invalid\n";
				continue;
			}
		}
		else if (max == second)
		{
			if (second >= first + third)
			{
				cout << "Invalid\n";
				continue;
			}
		}
		else
		{
			if (third >= second + first)
			{
				cout << "Invalid\n";
				continue;
			}
		}
		if (first == second && second == third) cout << "Equilateral\n";
		else if (first == second || second == third || third == first) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
	return 0;
}