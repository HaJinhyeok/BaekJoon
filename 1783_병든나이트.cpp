#include<iostream>

using namespace std;

typedef unsigned int uint;

// ��������� �̵��� ������ ���������θ�
// �ִ��� ���� ĭ�� �湮�ؾ� �ϹǷ� 2ĭ ��(or �Ʒ�) + 1ĭ ������ �̵�(1 or 4��)�� �ִ��� �����
// ���� ���� N�� 2�̰� ���� ���� M�� 7����? �̸� �� ���� �̵� ����(�� �����ʹ� ��� �̵� �������ϹǷ�)
// ���� ���� N�� 3 �̻��̰� ���� ���� M�� 4 ����? �̸� �� �� �� ���� �̵� ����
// N, M�� ����� ũ�� ���� ���� M - 2�� ����
// ������ ������ ���� ������
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