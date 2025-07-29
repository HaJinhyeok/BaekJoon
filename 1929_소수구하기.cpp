#include<iostream>
#include<vector>

using namespace std;

bool IsPrime(int num);

int main()
{
	int M, N;
	cin >> M >> N;
	vector<bool> myVec(N - M + 1, true);

	for (int i = M;i <=N; i++)
	{
		if (IsPrime(i))
			cout << i << '\n';
	}
	return 0;
}
bool IsPrime(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2;i * i <= num;i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}