#include "shell.h"

/**
 * _atoik convert the string to integer
 * @strg: string to be converted
 *
 * Return: the int converted from the string
 */
long int _atoik(char *str)
{
	int k, len, m, digit;
	long int z;

	k = 0;
	z = 0;
	len = _strlen(strg);
	m = 0;
	digit = 0;

	if (str[k] == '+')
		k++;

	while (k< len && m == 0)
	{
		if (str[k] == '-')
			return (-1);

		if (str[k] >= '0' && str[k] <= '9')
		{
			digit = str[k] - '0';
			z = z * 10 + digit;
			m = 1;
			if (str[k + 1] < '0' || str[k + 1] > '9')
				break;
			m = 0;
		}
		k++;
	}
	if (m == 0)
		return (0);
	if (z > INT_MAX || z < 0)
		return (-1);

	return (z);
}

/**
 * convert - converts the number and base to a string
 * @number: input number
 * @base: input base
 * Return: resulting string
 */
char *converting(int number, int base)
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
