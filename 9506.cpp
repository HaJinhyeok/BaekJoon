#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int givenNumber, checkPerfect = 1; // ����� �ϳ��� ���ؼ� üũ�Ѵ�. 1�� ��� ���� ����̹Ƿ� default�� 1
	vector<int> nFactors;
	while (1)
	{
		cin >> givenNumber;
		if (givenNumber == -1) break;
		else if (givenNumber == 1)
		{
			cout << "1 is NOT perfect.\n";
			continue;
		}
		for (int i = 2; i * i <= givenNumber; i++)
		{
			if (givenNumber % i == 0)
			{
				checkPerfect += i + givenNumber / i;
				nFactors.push_back(i);
				nFactors.push_back(givenNumber / i);
			}
		}
		if (checkPerfect != givenNumber) cout << givenNumber << " is NOT perfect.\n";
		else
		{
			cout << givenNumber << " = 1";
			sort(nFactors.begin(), nFactors.end());
			for (int i = 0; i < nFactors.size(); i++)	cout << " + " << nFactors[i];
			cout << '\n';
		}
		// ��� ���� ������ üũ�ϴ� �� ����
		nFactors.clear();
		checkPerfect = 1;
	}
	return 0;
}