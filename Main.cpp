#include <iostream>
using namespace std;

int firstPrimNumberMoreThanHundred(); // Mi a 100 - nál nagyobb elsõ prímszám ?
int primeNumberSumUnder100000(); // Mi a 100 000-nél kisebb prímszámok összege?
void firstTwinPrimeNumberAfter20000(); // Mennyi a 20000-nél nagyobb elsõ ikerprím két tagja?

int main()
{
	setlocale(LC_ALL, "hun");
	
	cout<< "Az elsõ prim szám 100 felett: " << firstPrimNumberMoreThanHundred()<<endl;
	firstTwinPrimeNumberAfter20000();
	cout << "Prímszámok összege 10000 alatt: " << primeNumberSumUnder100000() << endl;

}

int firstPrimNumberMoreThanHundred()
{

	int i = 99;
	int j = 1;

	int dividedNumCounter = 0;
	int firstPrimeNumber = 0;
	bool foundPrimeNumber = false;

	while (i < 999)
	{
		j = 1;
		dividedNumCounter = 0;
		while (j <= i)
		{
			if (i%j == 0) dividedNumCounter++;

			if (j == i && dividedNumCounter == 2)
			{
				if (!foundPrimeNumber) 
				{
					firstPrimeNumber = i;
					foundPrimeNumber = true;
					dividedNumCounter = 0;
				}
			}
			j++;
		}
		i++;
	}
	return firstPrimeNumber;
}

int primeNumberSumUnder100000()
{
	int sum = 0;
	int i = 1;
	int j = 1;
	int primNumCounter = 0;

	while (i < 100000 )
	{
		j = 1;
		primNumCounter = 0;
		while (j<=i)
		{
			if (i % j == 0) primNumCounter++;
			
			if (i == j && primNumCounter == 2) 
			{
				sum += i;
				primNumCounter = 0;
			}
			j++;
		}
		i++;
	}
	return sum+1;
}

void firstTwinPrimeNumberAfter20000()
{
	int i = 20000;
	int j = 1;
	int primNumCounter = 0;
	int twinPrime[2] = { 0 };
	int twinPrimeIndex = 0;
	bool foundTheTwinPrime = false;

	while (i < 20500)
	{
		if (!foundTheTwinPrime)
		{
			j = 1;
			primNumCounter = 0;
			while (j <= i)
			{

				if (i % j == 0) primNumCounter++;

				if (i == j && primNumCounter == 2)
				{
					twinPrime[twinPrimeIndex] = i;
					twinPrimeIndex++;

					if (twinPrimeIndex >= 2) twinPrimeIndex = 0;

					if (twinPrimeIndex == 1)
					{
						if (twinPrime[1] - twinPrime[0] == 2 || twinPrime[0] - twinPrime[1] == 2)
						{
							cout << "Az elsõ ikerprím 20000 felett: " << twinPrime[0] << " és " << twinPrime[1] << endl;
							foundTheTwinPrime = true;
							j = i + 1;
						}
					}

					primNumCounter = 0;
				}

				j++;
			}
		}
		i++;
	}
}
