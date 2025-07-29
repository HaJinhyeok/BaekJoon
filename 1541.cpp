#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> numSet;
	vector<char> operSet;
	string givenStr;
	string tmpStr = "";
	int i = 0, j = 0, result = 0;
	bool isMinus = false;
	cin >> givenStr;
	// ASCII: 0(48) ~ 9(57), +(43), -(45)
	for (i = 0; i < givenStr.length(); i++)
	{
		if (givenStr[i] == 43 || givenStr[i] == 45)
		{
			operSet.push_back(givenStr[i]);
			if (tmpStr.length() > 0)
			{
				numSet.push_back(stoi(tmpStr));
				tmpStr.clear();
			}
		}
		else if (givenStr[i] >= 48 && givenStr[i] <= 57)
		{
			tmpStr += givenStr[i];
		}
		if (i == givenStr.length() - 1)
		{
			numSet.push_back(stoi(tmpStr));
		}
	}
	for (i = 0, j = 0; i < numSet.size(); i++)
	{
		if (i == 0) result += numSet[i];
		else
		{
			// 아직 '-' 부호가 들어오기 전이면
			if (!isMinus)
			{
				if (operSet[j] == '-')
				{
					isMinus = true;
					result -= numSet[i];
				}
				else if (operSet[j] == '+')
				{
					result += numSet[i];
				}
			}
			else
			{
				result -= numSet[i];
			}
			j++;
		}
	}
	cout << result;
	return 0;
}