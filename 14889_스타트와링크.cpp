#include <iostream>
#include <vector>

using namespace std;

int difference = 1234567890;
int N;
bool IsSelected[20] = { false, };

void BackTracking(vector<int> start, vector<int>link, vector<vector<int>>& stats);
int CalculateTotalStats(vector<int>team, vector<vector<int>>& stats);

int main()
{
	cin >> N;
	vector<vector<int>> stats(N, vector<int>(N));
	vector<int> start;
	vector<int> link;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> stats[i][j];
		}
	}
	// 두 팀으로 나누기이므로 start 팀에 0번이 포함된 경우만 생각하면 된다
	start.push_back(0);
	IsSelected[0] = true;
	BackTracking(start, link, stats);
	cout << difference;
	return 0;
}

void BackTracking(vector<int> start, vector<int>link, vector<vector<int>>& stats)
{
	if (start.size() == N / 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (IsSelected[i] == false)
			{
				link.push_back(i);
			}
		}
		/*cout << "Current Start Team: ";
		for (int i = 0; i < start.size(); i++)
		{
			cout << start[i] << ' ';
		}
		cout << '\n';
		cout << "Current Link Team: ";
		for (int i = 0; i < link.size(); i++)
		{
			cout << link[i] << ' ';
		}
		cout << '\n';*/
		int currentResult = CalculateTotalStats(start, stats) - CalculateTotalStats(link, stats);
		currentResult = currentResult >= 0 ? currentResult : -currentResult;
		difference = currentResult < difference ? currentResult : difference;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (IsSelected[i] == false && start.back() < i)
			{
				start.push_back(i);
				IsSelected[i] = true;
				BackTracking(start, link, stats);
				IsSelected[i] = false;
				start.pop_back();
			}
		}
	}
}

int CalculateTotalStats(vector<int>team, vector<vector<int>>& stats)
{
	int size = team.size();
	int sum = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			//cout << "Added stats of" << team[i] << ", " << team[j] << '\n';
			sum += stats[team[i]][team[j]] + stats[team[j]][team[i]];
		}
	}
	//cout << "Sum: " << sum << '\n';
	return sum;
}