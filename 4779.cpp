#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// 3등분 후 중간 지점은 비워주기
void CantorCenter(vector<bool>& myVec, int n, int idx)
{
	int i;
	for (i = idx; i < idx + pow(3, n); i++) myVec[i] = false;
}

// 칸토어 집합, 3^n(n=1이면 끝내주기), 3등분 지점 각각의 시작 index
void Cantor(vector<bool>& myVec, int n, int idx)
{
	if (n == 0)	myVec[0] = true;
	else if (n == 1)
	{
		myVec[idx] = true;
		myVec[idx + 1] = false;
		myVec[idx + 2] = true;
	}
	else
	{
		int divideBy3 = pow(3, n - 1);
		Cantor(myVec, n - 1, idx);
		CantorCenter(myVec, n - 1, idx + divideBy3);
		Cantor(myVec, n - 1, idx + 2 * divideBy3);
	}
}

void PrintCantor(const vector<bool> myVec)
{
	for (auto iter : myVec)
	{
		if (iter == true) cout << '-';
		else cout << ' ';
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	while (cin >> N)
	{
		vector<bool> CantorSet(pow(3, N));
		Cantor(CantorSet, N, 0);
		PrintCantor(CantorSet);
		cout << '\n';
	}

	return 0;
}