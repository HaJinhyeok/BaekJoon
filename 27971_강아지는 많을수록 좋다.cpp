#include <iostream>
#include <vector>

using namespace std;

// 닫힌 구간에 포함되는 수는 전부 true
// count[i]=min(count[i-A]+1,count[i-B]+1);
// count[A]=count[B]=1;

bool isClosed[100001];
// i마리가 되기위해 필요한 최소 행동 횟수
int countToGoal[100001];

int Count(int goal, int magic1, int magic2);

int main()
{
	int puppy, closed, magicA, magicB;
	int start, finish;
	int count = 0;
	cin >> puppy >> closed >> magicA >> magicB;
	for (int i = 0; i < closed; i++)
	{
		cin >> start >> finish;
		for (int j = start; j <= finish; j++)
		{
			isClosed[j] = true;
		}
	}

	cout << Count(puppy, magicA, magicB);
	return 0;
}

int Count(int goal, int magic1, int magic2)
{
	if (goal <= 0)
		return -1;
	if (isClosed[goal])
		return -1;
	if (goal == magic1 || goal == magic2)
		return countToGoal[goal] = 1;
	if (countToGoal[goal])
		return countToGoal[goal];
	int first = Count(goal - magic1, magic1, magic2);
	int second = Count(goal - magic2, magic1, magic2);
	if (first <= 0 && second <= 0)
		return countToGoal[goal] = -1;
	else if (first <= 0)
		return countToGoal[goal] = second + 1;
	else if (second <= 0)
		return countToGoal[goal] = first + 1;
	else
		return countToGoal[goal] = min(first + 1, second + 1);

}