#include<iostream>
#include<vector>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}
int main()
{
	int N, position, myGCD;
	int myNum;
	vector<int> myTree;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> position;
		// 가로수 간격의 최대공약수 찾기
		myTree.push_back(position);
		if (myTree.size() == 1) continue;
		else if (myTree.size() == 2)
		{
			myGCD = myTree[1] - myTree[0];
		}
		else myGCD = GCD(myTree[i] - myTree[i - 1] , myGCD);
	}
	// (가장 먼 나무 - 가장 가까운 나무) / GCD 에서 현재 가로수 개수(myTree의 크기)를 뺀 후 +1
	myNum = (myTree.back() - myTree.front()) / myGCD - myTree.size() + 1;
	cout << myNum;

	return 0;
}