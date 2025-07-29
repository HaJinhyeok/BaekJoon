#include <iostream>
#include <vector>

using namespace std;

int trackingList[8];

void BackTracking(int N, int M, int depth, vector<bool>& isChecked);
bool IsPossible(int list[]);

int main()
{
	int N = 8, M = 8;
	int depth = 0;
	vector<bool> isChecked(N);
	BackTracking(N, M, depth, isChecked);
	return 0;
}

void BackTracking(int N, int M, int depth, vector<bool>& isChecked)
{
	if (depth == M)
	{
		/*cout << "Current number: ";
		for (int i = 0; i < M; i++)
		{
			cout << trackingList[i] << ' ';
		}
		cout << '\n';*/
		if (IsPossible(trackingList))
		{
			cout << "answer : " << trackingList[0] << trackingList[1] << trackingList[2] << " * " << trackingList[3] << " = "
				<< trackingList[4] << trackingList[5] << trackingList[6] << trackingList[7];
			cout << '\n';
		}
	}
	else
	{
		int size = isChecked.size();
		for (int i = 0; i < size; i++)
		{
			if (!isChecked[i])
			{
				trackingList[depth] = i + 1;
				isChecked[i] = true;
				depth++;
				BackTracking(N, M, depth, isChecked);
				depth--;
				isChecked[i] = false;
			}
		}
	}
}
bool IsPossible(int list[])
{
	int mul1 = list[0] * 100 + list[1] * 10 + list[2];
	int mul2 = list[3];
	int result = list[4] * 1000 + list[5] * 100 + list[6] * 10 + list[7];
	return (mul1 * mul2 == result);
}