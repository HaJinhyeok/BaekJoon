#include<iostream>

using namespace std;
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int first, second, third;
	cin >> first >> second >> third;
	int max = (first > second) && (first > third) ? first : (second > third) ? second : third;
	if (max == first) Swap(first, third);
	else if (max == second) Swap(second, third);
	while(first+second<=)

	return 0;
}