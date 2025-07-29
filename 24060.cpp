#include<iostream>
#include<vector>

using namespace std;

int nCount = 0, nNum = 0, result = 0;
void merge_sort(vector<int>& myVec, int front, int back);
void Merge(vector<int>& myVec, int first, int middle, int last);

int main()
{
	int nSize, myEnter, i;
	vector<int> myVec;
	cin >> nSize >> nNum;
	for (i = 0; i < nSize; i++)
	{
		cin >> myEnter;
		myVec.push_back(myEnter);
	}
	merge_sort(myVec, 0, nSize - 1);
	// for (i = 0; i < nSize; i++)	cout << myVec[i] << ' ';
	// cout << "\nnCount = " << nCount;
	if (result > 0) cout << result;
	else cout << -1;
	return 0;
}

void merge_sort(vector<int>& myVec, int front, int back)
{
	if (front < back)
	{
		int middle = (front + back) / 2;
		merge_sort(myVec, front, middle);
		merge_sort(myVec, middle + 1, back);
		Merge(myVec, front, middle, back);
	}
}

void Merge(vector<int>& myVec, int first, int middle, int last)
{
	vector<int> tmp(last - first + 1);
	int i, j, k;
	for (i = first, j = middle + 1, k = 0; i <= middle && j <= last;)
	{
		if (myVec[i] <= myVec[j])	tmp[k++] = myVec[i++];
		else tmp[k++] = myVec[j++];
	}
	while (i <= middle) tmp[k++] = myVec[i++];
	while (j <= last)	tmp[k++] = myVec[j++];
	for (i = first, k = 0; i <= last;)
	{
		myVec[i++] = tmp[k++];
		if (++nCount == nNum) result = tmp[k - 1];
	}
}