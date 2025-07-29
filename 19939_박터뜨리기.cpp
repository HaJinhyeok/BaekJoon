#include<iostream>

using namespace std;

/*
��Ʈ��ŷ?
1�� �ٱ��Ͽ� 1��, 2�� �ٱ��Ͽ� 2��, ... ������ ��� i�� �ٱ��Ͽ� i�� ���� �� ������ return -1
>> k(k+1)/2 > N �̸� return -1
N=K(K+1) : 1+2+...+(K-1)+K -> K-1
N+1 : 1+2+...+(K-1)+(K+1) -> K
N+2 : 1+2+...+(K-1+1)+(K+1)->K
N+K : (1+1)+(2+1)+...+(K-1+1)+(K+1)->K-1
��������� K �ƴϸ� K-1�̳�... ����
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