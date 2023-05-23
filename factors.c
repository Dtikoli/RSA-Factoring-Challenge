#include <stdio.h>

/**
  * factorize - factorizes a number
  * @num: number to factorize
  * Return: Nothing
  */
void factorize(long int num)
{
	long int i;

	for (i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%ld=%ld*%ld\n", num, num / i, i);
			break;
		}
	}
}

/**
  * main - entry point
  * @argc: number of CL arguments
  * @argv: string pointer to CL arguments
  * Return: Always 0
  */
int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	long int n;

	if (argc != 2)
	{
		printf("Usage: factors <file>\n");
		return (1);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		printf("Error opening file\n");
		return (1);
	}

	while (fscanf(fp, "%ld", &n) == 1)
		factorize(n);

	fclose(fp);

	return (0);
}

