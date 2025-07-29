#include<iostream>

using namespace std;

int main()
{
	// false는 아직 색종이가 붙지 않은 흰 영역, true는 색종이가 붙은 검은 영역
	bool WhitePaper[101][101] = { false, }; 
	int Left, Down, numOfPaper, i, j;
	int BlackArea = 0;
	cin >> numOfPaper;
	for (int idx = 0; idx < numOfPaper; idx++)
	{
		cin >> Left >> Down;
		for (i = Left; i < Left + 10; i++)
		{
			for (j = Down; j < Down + 10; j++)
			{
				WhitePaper[i][j] = true;
			}
		}
	}
	for (i = 1; i < 101; i++)
	{
		for (j = 1; j < 101; j++)
		{
			if (WhitePaper[i][j]) BlackArea++;
		}
	}
	cout << BlackArea;
	return 0;
}