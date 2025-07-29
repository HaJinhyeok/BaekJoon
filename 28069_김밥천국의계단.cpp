#include <iostream>

using namespace std;

/*
K: N
K-1: N-1 or 2N/3

i=2k => i + floor(i/2) = 3k
i=2k+1 => i + floor(i/2) = 3k+1

N == 2 (mod 3) => K��°�� ��ĭ ������
N == 1 (mod 3) => 
N == 0 (mod 3)
*/

bool IsPossible(int N, int K);

int main()
{
	int N, K;
	cin >> N >> K;
	if (IsPossible(N, K))
		cout << "minigimbob";
	else
		cout << "water";
	return 0;
}

bool IsPossible(int N, int K)
{
	if (K == 0)
		return false;
	// K == N �̸� �� ĭ ������ K��
	// K > N �̸� 0��° ĭ���� ������ K-N�� �ε��� �� ĭ ������ N��
	if (K >= N)
		return true;
	// K < N �̹Ƿ� IsPossible(N-1,K-1)�� �ǹ̰� ����
	if (N % 3 == 2)
		return IsPossible(N - 1, K - 1);
	else if (N % 3 == 1)
		return IsPossible(N / 3 * 2 + 1, K - 1);
	else
		return IsPossible(N / 3 * 2, K - 1);
}