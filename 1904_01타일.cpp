#include <iostream>

using namespace std;

int tmp[3] = { 0,1,2 };

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		tmp[2] = (tmp[0] + tmp[1]) % 15746;
		tmp[0] = tmp[1];
		tmp[1] = tmp[2];
	}
	cout << tmp[2];
	return 0;
}