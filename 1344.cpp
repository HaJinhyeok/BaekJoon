#include<iostream>
#include<math.h>
#define MAX 18
#define ll long long

using namespace std;

bool isPrime[MAX + 1] = { 0,0,1,1,0,1,0,1,0,0,0,1, 0, 1, 0 , 0, 0 , 1 , 0 };

ll Combination(int k)
{
	// nCk = nPk / k!
	ll deno = 1, nom = 1; // ºÐ¸ð, ºÐÀÚ
	int i;
	// nCk = nC(n-k)
	if (k > MAX / 2) k = MAX - k;
	for (i = 1; i <= k; i++)
	{
		deno *= i;
		nom *= MAX + 1 - i;
	}
	return nom / deno;
}
double Probability(int k, double prob)
{
	double result;
	result = Combination(k) * pow(prob, k) * pow(1 - prob, MAX - k);

	return result;
}

int main()
{
	double first, second, result1 = 0.0, result2 = 0.0;
	double result3 = 0.0;
	double plzSum1 = 0.0;
	int i;
	cin >> first >> second;
	first /= 100;
	second /= 100;
	for (i = 0; i <= MAX; i++)
	{
		if (!isPrime[i])
		{
			result1 += Probability(i, first);
			result2 += Probability(i, second);
		}
	}
	/*for (i = 0; i <= MAX; i++)
	{
		if (isPrime[i])
		{
			result3 += Probability(i, first);
		}
		plzSum1 += Probability(i, first);
	}
	cout << "±×³É È®·ü ½Ï ´õÇÏ¸é: " << plzSum1 << "\n";
	cout << "1ÆÀÀÌ ¼Ò¼ö·Î µæÁ¡ÇÒ È®·ü: " << result3;
	cout << "\n1ÆÀÀÌ ¼Ò¼ö·Î µæÁ¡ÇÏÁö ¾ÊÀ» È®·ü: " << result1;
	cout << "\n1 - ¼Ò¼ö·Î µæÁ¡ÇÒ È®·ü: " << 1 - result1 << '\n';
	printf("%f\n", 1 - result1 * result2);*/
	cout << 1 - result1 * result2 << '\n';

	return 0;
}
// number of prime = 7
// ÇÑ ÆÀÀÌ ¼Ò¼ö·Î µæÁ¡ÇÏÁö '¾ÊÀ»' È®·ü
// >> Sum_(k=0)^18 18Ck * p^k * (1-p)^(18-k)
// where isPrime[k]==false