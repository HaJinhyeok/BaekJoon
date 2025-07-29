#include<iostream>

using namespace std;

typedef unsigned int uint;

// 결과적으로 이동은 무조건 오른쪽으로만
// 최대한 많은 칸을 방문해야 하므로 2칸 위(or 아래) + 1칸 오른쪽 이동(1 or 4번)을 최대한 써야함
// 세로 길이 N이 2이고 가로 길이 M이 7이하? 이면 딱 세번 이동 가능(네 번부터는 모든 이동 방법써야하므로)
// 세로 길이 N이 3 이상이고 가로 길이 M이 4 이하? 이면 딱 세 번 이하 이동 가능
// N, M이 충분히 크면 가로 길이 M - 2가 정답
// 가짓수 나누는 문제 같은데
// 

uint CountMaxVisits(uint N, uint M);

int main()
{
	uint N, M, count = 0;
	cin >> N >> M;
	cout << CountMaxVisits(N, M);
	return 0;
}

uint CountMaxVisits(uint N, uint M)
{
	if (N == 1 || M == 1)
		return 1;
	if (N == 2)
	{
		if (M >= 7)
			return 4;
		else
			return (M + 1) / 2;
	}
	// N >= 3
	else
	{
		if (M >= 7)
			return M - 2;
		else if (M >= 4 && M <= 6)
			return 4;
		else
			return M;
	}
}