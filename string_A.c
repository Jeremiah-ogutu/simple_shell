#include "shell.h"

/*
 * _strlen - finds length of the string
 * *string: the string to be evaluated
 * Return: string length
 */

int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

/*
 * _strcpy - to copy string pointed by src
 * include null byte
 * @dest: where the string will be copied
 * @src: string to be copied
 * Return: points dest
 */

char *_strcpy(char *dest, char *src)
{
	int len, k;

	len = 0;

	while (src[len] != '\0')
		len++;
	for (k = 0; k < len; k++)
		dest[k] = src[k];

	dest[k] = '\0';

	return (dest);
}
