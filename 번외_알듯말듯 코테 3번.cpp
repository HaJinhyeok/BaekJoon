#include <iostream>
#include <string>

using namespace std;

int combination[11][11];

// �ִ� 10�ڸ� : 0123456789 -> 10C10

int Combination(int n, int r);
string solution(int k);

int main()
{
	int k;
	//cin >> k;
	for (int i = 1; i <= 1024; i++)
	{
		cout << solution(i) << '\n';
	}
	//cout << solution(k);
	return 0;
}

int Combination(int n, int r)
{
	if (combination[n][r])
		return combination[n][r];
	if (r > n / 2)
		r = n - r;
	if (r == 0)
		return combination[n][r] = 1;
	if (r == 1)
		return combination[n][r] = n;

	return combination[n][r] = Combination(n - 1, r) + Combination(n - 1, r - 1);
}
string solution(int k)
{
	string answer = "";
	int num;
	if (k >= 1024)
		return "-1";
	// �� �ڸ������� ���ϱ�
	for (int i = 1; i <= 10; i++)
	{
		if (k <= Combination(10, i))
		{
			num = i;
			break;
		}
		else
		{
			k -= Combination(10, i);
		}
	}
	// ���ڸ�: 0 ~ 9 -> 10C1 �� = 10
	// ���ڸ�: 01 ~ 09, 12 ~ 19, ... , 89 -> 10C2 �� = 9 + 8 + ... + 1
	// ���ڸ�: 012 ~ 019, 123 ~ 129, ... , 789 -> 10C3 �� = 8 + 7 + ... + 1
	// ���ڸ�: 0123 ~ 0129, 0134 ~ 0139, ... ,     6789 -> 10C4 �� = 7 + 6
	// n�ڸ�: -> 10Cn ��
	int digit = 0;
	int tmp;
	// �ڸ����� �����ش�
	for (int i = 0; i < num; i++)
	{
		while (k > 0)
		{
			tmp = Combination(9 - digit, num - 1 - i);
			if (k <= tmp)
			{
				// i��° �ڸ����� digit��!
				answer += (char)(digit + 48);
				//cout << "current string: " << answer << '\n';
				digit++;
				break;
			}
			else
			{
				k -= tmp;
				digit++;
			}
		}		
	}
	return answer;
}