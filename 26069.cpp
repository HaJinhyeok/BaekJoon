#include<iostream>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, count = 1;
	string name1, name2;
	map<string, bool> rainbowDance;
	cin >> N;
	while (N--)
	{
		cin >> name1 >> name2;
		if (rainbowDance[name1] == true && rainbowDance[name2] == true) continue;
		else if (name1 == "ChongChong" || name2 == "ChongChong")
		{
			rainbowDance[name1] = true;
			rainbowDance[name2] = true;
			count++;
		}
		else if (rainbowDance[name1] == true || rainbowDance[name2] == true)
		{
			rainbowDance[name1] = true;
			rainbowDance[name2] = true;
			count++;
		}
	}
	cout << count;
	return 0;
}