#include<iostream>

using namespace std;

/*
백트래킹?
1번 바구니에 1개, 2번 바구니에 2개, ... 식으로 담고 i번 바구니에 i개 담을 수 없으면 return -1
>> k(k+1)/2 > N 이면 return -1
N=K(K+1) : 1+2+...+(K-1)+K -> K-1
N+1 : 1+2+...+(K-1)+(K+1) -> K
N+2 : 1+2+...+(K-1+1)+(K+1)->K
N+K : (1+1)+(2+1)+...+(K-1+1)+(K+1)->K-1
결론적으로 K 아니면 K-1이네... ㅅㅂ
*/
int Calculate(int N, int K);

int main()
{
	int N, K;
	cin >> N >> K;
	cout << Calculate(N, K);
	return 0;
}

int Calculate(int N, int K)
{
	int sum = K * (K + 1) / 2;
	if (N < sum)
		return -1;
	if ((N-sum) % K == 0)
		return K - 1;
	else 
		return K;
}