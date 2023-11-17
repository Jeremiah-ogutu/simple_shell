#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @strg: string to be converted
 * Return: the int converted from the string
 */
long int _atoi(char *strg)
{
	int i;
	int len;
	int f;
	int digit;
	long int n;

	i = 0;
	n = 0;
	len = _strlen(strg);
	f = 0;
	digit = 0;

	if (strg[i] == '+')
		i++;

	while (i < len && f == 0)
	{
		if (strg[i] == '-')
			return (-1);

		if (strg[i] >= '0' && strg[i] <= '9')
		{
			digit = strg[i] - '0';
			n = n * 10 + digit;
			f = 1;
			if (strg[i + 1] < '0' || strg[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	if (n > INT_MAX || n < 0)
		return (-1);

	return (n);
}

/**
 * convert - converts number and base into string
 * @number: input number
 * @base: input base
 * Return: result string
 */
char *convert(int number, int base)
{

	static char *rep = "0123456789";
	static char buffer[50];
	char *ptr = NULL;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[number % base];
		number /= base;
	} while (number != 0);

	return (ptr);
}
