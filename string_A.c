#include "shell.h"

/*
 * _strlen - finds length of the string
 * *string: the string to be evaluated
 * Return: string length
 */

int _strlen(char *string)
{
	int len = 0;

	if (!string)
		return (0);
	while (string[len])
		len++;
	return (len);
}

/*
 * _strcopy - to copy string pointed by src
 * include null byte
 * @dest: points the buffer where the string will be copied
 * @source: the string to be copied
 * Return: points to the dest
 */

char *_strcopy(char *dest, char *source)
{
	int len, k;

	len = 0;

	while (source[len] != '\0')
		len++;
	for (k = 0; k < len; k++)
		dest[k] = source[k];

	dest[k] = '\0';

	return (dest);
}
