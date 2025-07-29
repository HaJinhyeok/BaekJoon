#include <iostream>
#include <memory.h>

using namespace std;

int N;
int sticker[2][100001];
int memoization[2][100001];

void StickerScore();

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		cin >> N;
		memset(sticker, 0, sizeof(sticker));
		memset(memoization, 0, sizeof(memoization));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> sticker[i][j];
			}
		}
		StickerScore();
		cout << max(memoization[0][N], memoization[1][N]) << '\n';
	}
	return 0;
}

void StickerScore()
{
	memoization[0][0] = memoization[1][0] = 0;
	memoization[0][1] = sticker[0][1];
	memoization[1][1] = sticker[1][1];

	for (int i = 2; i <= N; i++)
	{
		memoization[0][i] = max(memoization[1][i - 1], memoization[1][i - 2]) + sticker[0][i];
		memoization[1][i] = max(memoization[0][i - 1], memoization[0][i - 2]) + sticker[1][i];
	}
}