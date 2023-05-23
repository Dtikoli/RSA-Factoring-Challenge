#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
  * isPrime - Function to check if a number is prime
  * @num: number to check
  * Return: True, otherwise false
  */
bool isPrime(long int num)
{
	long int i;

	if (num <= 1)
		return (false);
	if (num <= 3)
		return (true);
	if (num % 2 == 0 || num % 3 == 0)
		return (false);
	for (i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (false);
	}
	return (true);
}

/**
  * findPrimeFactors - finds two distinct prime factors p and q of n
  * @n: number to factorize
  * @p: a pointer to the first prime factor
  * @q: a pointer to the second prime factor
  * Return: Nothing
  */
void findPrimeFactors(long int n, long int *p, long int *q)
{
	long int i;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0 && isPrime(i))
		{
			*p = i;
			*q = n / i;
			return;
		}
	}
}

/**
  * main - entry point
  * @argc: number of CL args
  * @argv: string pointer to CL args
  * Return: Always 0
  */
int main(int argc, char *argv[])
{
	long int n, p, q;
	FILE *fp;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		printf("Failed to open the file.\n");
		return (1);
	}

	if (fscanf(fp, "%ld", &n) != 1)
	{
		printf("Failed to read the number from the file.\n");
		fclose(fp);
		return (1);
	}
	fclose(fp);

	findPrimeFactors(n, &p, &q);

	if (p && q)
		printf("%ld=%ld*%ld\n", n, q, p);

	else
		printf("No distinct prime factors found.");

	return (0);
}

