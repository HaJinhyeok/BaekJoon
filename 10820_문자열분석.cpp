#include<iostream>

using namespace std;

int main()
{
	char str[102];
	int count[4] = { 0, };
	while (fgets(str, sizeof(str), stdin))
	{
		//gets_s(str, sizeof(str));
		for (auto i : str)
		{
			if (i >= 48 && i <= 57)
			{
				count[2]++;
			}
			else if (i >= 65 && i <= 90)
			{
				count[1]++;
			}
			else if (i >= 97 && i <= 122)
			{
				count[0]++;
			}
			else if (i == ' ')
			{
				count[3]++;
			}
			else if (i == '\n')
			{
				break;
			}
		}
		if (count[0] + count[1] + count[2] + count[3] != 0)
			cout << count[0] << ' ' << count[1] << ' ' << count[2] << ' ' << count[3] << '\n';
		for (int k = 0; k < 4; k++)
		{
			count[k] = 0;
		}
	}
	return 0;
}