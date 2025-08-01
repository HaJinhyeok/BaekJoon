#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int CheckRecolored(vector<vector<int> > bBoard, vector<vector<int> > wBoard, int coX, int coY, int nSize)
{
	int bResult = bBoard[coX + nSize - 1][coY + nSize - 1] - bBoard[coX + nSize - 1][coY - 1] - bBoard[coX - 1][coY + nSize - 1] + bBoard[coX - 1][coY - 1];
	int wResult = wBoard[coX + nSize - 1][coY + nSize - 1] - wBoard[coX + nSize - 1][coY - 1] - wBoard[coX - 1][coY + nSize - 1] + wBoard[coX - 1][coY - 1];
	return (bResult < wResult) ? bResult : wResult;
}

int main()
{
	// IMOS algorithm 사용하기...
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M, K, i, j, recolorResult;
	int minRecolored = 10000000;
	string myStr;
	cin >> N >> M >> K;
	vector<vector<int> > blackStartBoard(N + 1, vector<int>(M + 1, 0));
	vector<vector<int> > whiteStartBoard(N + 1, vector<int>(M + 1, 0));
	vector<vector<char> > chessBoard(N, vector<char>(M));
	for (i = 0; i < N; i++)
	{
		cin >> myStr;
		for (j = 0; j < M; j++)
		{
			chessBoard[i][j] = myStr[j];
		}
	}



	//for (i = 1; i <= N; i++)
	//{
	//	cin >> myStr;
	//	for (j = 1; j <= M; j++)
	//	{
	//		switch (myStr[j-1])
	//		{
	//		case 'B':
	//			if ((i + j) % 2 == 0)
	//			{
	//				// blackStart인 경우, 합이 짝수 일때 B여야 하고 아니면 W여야함
	//				blackStartBoard[i][j] = blackStartBoard[i - 1][j] + blackStartBoard[i][j - 1] - blackStartBoard[i - 1][j - 1];
	//				// whiteStart인 경우, 합이 짝수 일때 W여야 하고 아니면 B여야함
	//				whiteStartBoard[i][j] = whiteStartBoard[i - 1][j] + whiteStartBoard[i][j - 1] - whiteStartBoard[i - 1][j - 1] + 1;
	//			}
	//			else
	//			{
	//				blackStartBoard[i][j] = blackStartBoard[i - 1][j] + blackStartBoard[i][j - 1] - blackStartBoard[i - 1][j - 1] + 1;
	//				whiteStartBoard[i][j] = whiteStartBoard[i - 1][j] + whiteStartBoard[i][j - 1] - whiteStartBoard[i - 1][j - 1];
	//			}
	//			break;
	//		case 'W':
	//			if ((i + j) % 2 == 0)
	//			{
	//				blackStartBoard[i][j] = blackStartBoard[i - 1][j] + blackStartBoard[i][j - 1] - blackStartBoard[i - 1][j - 1] + 1;
	//				whiteStartBoard[i][j] = whiteStartBoard[i - 1][j] + whiteStartBoard[i][j - 1] - whiteStartBoard[i - 1][j - 1];
	//			}
	//			else
	//			{
	//				blackStartBoard[i][j] = blackStartBoard[i - 1][j] + blackStartBoard[i][j - 1] - blackStartBoard[i - 1][j - 1];
	//				whiteStartBoard[i][j] = whiteStartBoard[i - 1][j] + whiteStartBoard[i][j - 1] - whiteStartBoard[i - 1][j - 1] + 1;
	//			}
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	//}
	//for (i = 1; i <= N - K + 1; i++)
	//{
	//	for (j = 1; j <= M - K + 1; j++)
	//	{
	//		recolorResult = CheckRecolored(blackStartBoard, whiteStartBoard, i, j, K);
	//		minRecolored = (minRecolored < recolorResult) ? minRecolored : recolorResult;
	//	}
	//}
	cout << minRecolored;

	return 0;
}