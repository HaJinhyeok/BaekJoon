#include<iostream>
#include<vector>
using namespace std;

int main() {
	unsigned int givenNumber, goal, i;
	vector<int> nFactors;
	cin >> givenNumber >> goal;
	for (i = 1; i <= givenNumber; i++)
	{
		if (givenNumber % i == 0)nFactors.push_back(i);
	}
	if (nFactors.size() < goal) cout << 0;
	else cout << nFactors[goal - 1];
	return 0;
}