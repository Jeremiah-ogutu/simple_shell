include "shell.h"

/**
 * _atoik convert the string to integer
 * @s: string to be converted
 * description: when first character is '+'
 *
 * Return: int converted from the string
 */
long int _atoi(char *s)
{
	int k, len, m, digit;
	long int z;

	k = 0;
	m = 0;
	len = _strlen(s);
	z = 0;
	digit = 0;

	if (s[k] == '+')
		k++;

	while (k< len && m == 0)
	{
		if (s[k] == '-')
			return (-1);

		if (s[k] >= '0' && s[k] <= '9')
		{
			digit = s[k] - '0';
			z = z * 10 + digit;
			m = 1;
			if (s[k + 1] < '0' || s[k + 1] > '9')
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
 * convert - converts the number 
 * @num: input number
 * @base: input base
 * description: helps create static buffer
 * Return: resulting string
 */
char *convert(int num, int base)
{

	static char *rep = "0123456789";
	static char buffer[50];
	char *ptr = NULL;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
