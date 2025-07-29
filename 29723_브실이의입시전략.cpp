#include <iostream>
#include <queue>
#include <map>

using namespace std;

// 수강과목 N개 일단 받고
// 공개과목 K개 search해서 점수 더해놓고
// 나머지 수강과목 N-K개 내림차순 정렬
// 앞에서 M-K번까지 점수 합산 == maximum
// 뒤에서 점수 합산 == minimum
int main()
{
	int N, M, K, score;
	int maximum = 0, minimum = 0;
	string name;
	map<string, int> takenLectures;
	priority_queue<int> scores;
	vector<int> scoreVector;
	cin >> N >> M >> K;
	for (int i = 0;i < N;i++)
	{
		cin >> name >> score;
		takenLectures.insert(make_pair(name, score));
	}
	for (int i = 0;i < K;i++)
	{
		cin >> name;
		maximum += takenLectures[name];
		minimum += takenLectures[name];
		takenLectures.erase(name);
	}
	for (auto i : takenLectures)
	{
		scores.push(i.second);
	}
	while (!scores.empty())
	{
		scoreVector.push_back(scores.top());
		scores.pop();
	}
	int len = scoreVector.size();
	for (int i = 0;i < M - K;i++)
	{
		maximum += scoreVector[i];
		minimum += scoreVector[len - 1 - i];
	}
	cout << minimum << ' ' << maximum;
	return 0;
}