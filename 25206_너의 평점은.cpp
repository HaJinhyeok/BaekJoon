#pragma warning(disable:4996)
#include<iostream>
#include<string>
#define TOTAL 20
using namespace std;

int main() {
	string lectureName, myGrade;
	float lectureCredit = 0.0f, GPA, totalGrade = 0.0f, totalCredit = 0.0f; // GPA = tatalGrade / totalCredit
	for (int i = 0; i < TOTAL; i++)
	{
		cin >> lectureName >> lectureCredit >> myGrade;
		
		switch (myGrade[0])
		{
		case 'P': // P일 경우, 그 과목은 계산에서 제외한다.
			totalCredit -= lectureCredit;
			break;
		case 'F': // F = 0.0
			break;
		case 'A':
			if (myGrade[1] == '+')	totalGrade += 4.5 * lectureCredit;
			else totalGrade += 4.0 * lectureCredit;
			break;
		case 'B':
			if (myGrade[1] == '+')	totalGrade += 3.5 * lectureCredit;
			else totalGrade += 3.0 * lectureCredit;
			break;
		case 'C':
			if (myGrade[1] == '+')	totalGrade += 2.5 * lectureCredit;
			else totalGrade += 2.0 * lectureCredit;
			break;
		case 'D':
			if (myGrade[1] == '+')	totalGrade += 1.5 * lectureCredit;
			else totalGrade += 1.0 * lectureCredit;
			break;
		default:
			break;
		}
		totalCredit += lectureCredit;
		//cout << "current totalGrade: " << totalGrade << ", current totalCredit: " << totalCredit << '\n';
	}
	GPA = totalGrade / totalCredit;
	cout << GPA;
	return 0;
}