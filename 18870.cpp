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
	// X_i를 정렬할 벡터
	vector<ToCompare> ComparingVec;
	ToCompare tmp;
	cin >> N;
	// 최종적으로 X'_i를 저장할 벡터
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
			// value가 그 전의 것과 같다면 중복이므로, 중복 없는 순서(IdxWithoutDuple)을 키우지 않고 그대로 대입
			if (ComparingVec[i].value == ComparingVec[i - 1].value) ComparingVec[i].UnDuplicatedIdx = IdxWithoutDuple;
			// value가 그 전의 것과 다르다면 중복이 아니므로, 순서를 하나 키워서 대입
			else ComparingVec[i].UnDuplicatedIdx = ++IdxWithoutDuple;
		}
		// cout << "Value: " << ComparingVec[i].value << ", idx: " << ComparingVec[i].idx << ", UnDuplicatedIdx: " << ComparingVec[i].UnDuplicatedIdx << '\n';
		compressedCoor[ ComparingVec[i].idx ] = ComparingVec[i].UnDuplicatedIdx;
	}

	for (i = 0; i < N; i++) cout << compressedCoor[i] << ' ';

	return 0;
}