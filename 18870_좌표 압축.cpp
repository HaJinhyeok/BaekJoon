#pragma warning(disable:5208)

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

typedef struct{
	int value = 0;
	int idx = 0 ;
	int UnDuplicatedIdx = 0;
}ToCompare;

bool cmp(ToCompare first, ToCompare second)
{
	return first.value < second.value;
}

int main()
{
	int N, myNum, i;
	int IdxWithoutDuple = 0;
	// X_i�� ������ ����
	vector<ToCompare> ComparingVec;
	ToCompare tmp;
	cin >> N;
	// ���������� X'_i�� ������ ����
	vector<int> compressedCoor(N);

	for (i = 0; i < N; i++)
	{
		cin >> myNum;
		tmp.value = myNum;
		tmp.idx = i;
		ComparingVec.push_back(tmp);
	}
	sort(ComparingVec.begin(), ComparingVec.end(), cmp);

	vector<ToCompare>::iterator iter;
	
	for (i = 0; i < N; i++)
	{
		if (i == 0)
		{
			ComparingVec[i].UnDuplicatedIdx = IdxWithoutDuple;
		}
		else
		{
			// value�� �� ���� �Ͱ� ���ٸ� �ߺ��̹Ƿ�, �ߺ� ���� ����(IdxWithoutDuple)�� Ű���� �ʰ� �״�� ����
			if (ComparingVec[i].value == ComparingVec[i - 1].value) ComparingVec[i].UnDuplicatedIdx = IdxWithoutDuple;
			// value�� �� ���� �Ͱ� �ٸ��ٸ� �ߺ��� �ƴϹǷ�, ������ �ϳ� Ű���� ����
			else ComparingVec[i].UnDuplicatedIdx = ++IdxWithoutDuple;
		}
		// cout << "Value: " << ComparingVec[i].value << ", idx: " << ComparingVec[i].idx << ", UnDuplicatedIdx: " << ComparingVec[i].UnDuplicatedIdx << '\n';
		compressedCoor[ ComparingVec[i].idx ] = ComparingVec[i].UnDuplicatedIdx;
	}

	for (i = 0; i < N; i++) cout << compressedCoor[i] << ' ';

	return 0;
}