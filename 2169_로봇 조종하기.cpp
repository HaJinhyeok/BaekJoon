#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> area(N, vector<int>(M));
	// (i, j) ĭ�� ����, ���ʿ��� ���� ��� / ������ ������ ��� / �����ʿ��� �� ���
	// ���Ҿ�
	// �½�ĵ �콺ĵ -> �¿��� ��� �� �� ������,
	// �쿡�� �·� �� �� �ٽ� ������ �� ��ġ�� ������ ���� �ִ��� DP ���̺� ������Ʈ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> area[i][j];
		}
	}
	// DP ���̺� ����
	vector<vector<int>> table(N, vector<int>(M));
	table[0][0] = area[0][0];
	for (int j = 1; j < M; j++)
	{
		table[0][j] = table[0][j - 1] + area[0][j];
	}
	for (int i = 1; i < N; i++)
	{
		// �������� Ž��
		vector<int> leftToRight(M);
		leftToRight[0] = table[i - 1][0] + area[i][0];
		for (int j = 1; j < M; j++)
		{
			leftToRight[j] = max(leftToRight[j - 1], table[i - 1][j]) + area[i][j];
		}
		// �������� Ž��
		vector<int> rightToLeft(M);
		rightToLeft[M - 1] = table[i - 1][M - 1] + area[i][M - 1];
		for (int j = M - 2; j >= 0; j--)
		{
			rightToLeft[j] = max(rightToLeft[j + 1], table[i - 1][j]) + area[i][j];
		}
		// �������� Ž��
		for (int j = 0; j < M; j++)
		{
			table[i][j] = max(leftToRight[j], rightToLeft[j]);
		}
	}
	cout << table[N - 1][M - 1];

	return 0;
}