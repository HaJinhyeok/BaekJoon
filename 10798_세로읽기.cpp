#pragma warning(disable: 4996)
#include<iostream>
#define WORD 5
using namespace std;

int main()
{
	char givenWords[WORD][15] = { '\0', };
	int i, j;
	for (i = 0; i < WORD; i++)
	{
		cin >> givenWords[i];
	}
	for (j = 0; j < 15; j++)
	{
		for (i = 0; i < WORD; i++)
		{
			if (givenWords[i][j] != '\0') cout << givenWords[i][j];
		}
	}
	return 0;
}