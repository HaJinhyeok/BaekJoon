#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num;
	int enter;
	int max = INT16_MIN;
	int candidate;
	vector<int> numbers;
	// sums[i] : i��° ���ڱ��� ������ �� �ִ� ������
	// '����'�� ���� �߿��ϹǷ�, i��°���� ���Ѱ� ū�� i��°���� ���Ѱ� ū�� �Ǵ�
	vector<int> sums;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> enter;
		numbers.push_back(enter);
	}
	sums.push_back(numbers[0]);
	for (int i = 1; i < num; i++)
	{
		candidate = sums[i - 1] + numbers[i];
		sums.push_back(candidate > numbers[i] ? candidate : numbers[i]);
	}
	for (int i = 0; i < num; i++)
	{
		max = sums[i] > max ? sums[i] : max;
	}
	cout << max;

	return 0;
}