#include<iostream>
#include<vector>
using namespace std;

int main() {
	int row, col, i, j;
	cin >> row >> col;
	vector<vector<int> > matrixA(row, vector<int>(col));
	vector<vector<int> > matrixB(row, vector<int>(col));
	// ù��° ��� �ޱ�
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cin >> matrixA[i][j];
		}
	}
	// �ι�° ��� ������ ���ÿ� ù°�� ���ؼ� ����
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cin >> matrixB[i][j];
			matrixB[i][j] += matrixA[i][j];
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			cout << matrixB[i][j];
			if (j != col - 1) cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}