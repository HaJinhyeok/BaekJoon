#include <iostream>

using namespace std;

/*
K: N
K-1: N-1 or 2N/3

i=2k => i + floor(i/2) = 3k
i=2k+1 => i + floor(i/2) = 3k+1

N == 2 (mod 3) => K번째에 한칸 오르기
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
	// K == N 이면 한 칸 오르기 K번
	// K > N 이면 0번째 칸에서 지팡이 K-N번 두들기고 한 칸 오르기 N번
	if (K >= N)
		return true;
	// K < N 이므로 IsPossible(N-1,K-1)은 의미가 없음
	if (N % 3 == 2)
		return IsPossible(N - 1, K - 1);
	else if (N % 3 == 1)
		return IsPossible(N / 3 * 2 + 1, K - 1);
	else
		return IsPossible(N / 3 * 2, K - 1);
}