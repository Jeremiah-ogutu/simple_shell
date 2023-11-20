#include "shell.h"

/*
 * _strdups - str Memory allocation
 * @string: string to be duplicated
 * Return: new duplicate string if success or NULL if fail
 */

char *_strdups(char *str)
{
	char *dups = NULL;
	int z, k = 0;

	if (!string)
		return (NULL);
	while (string[k])
		k++;
	dups = malloc(sizeof(char) * k + 1);
	if (!duplicate)
		return (NULL);
	for (z = 0; z < k; z++)
		dups[z] = str[z];
	dups[z] = '\0';
	return (dups);
}

/*
 * str_concat - concatenate string
 * @s1: first string to be concatenated
 * @s2: second string to be concatenated
 * Return: pointer to the new string if success or NULL if fail
 */

char str_concat(char *s1, char *s2)
{
	char *s3 = NULL;
	unsigned int k = 0, m = 0, len1 = 0, len2 = 0;

len1 = _strlen(s1)
len2 = _strlen(g2)

s3 = malloc(sizeof(char) * (len1 + len2 + 1));
if (s == NULL)
	return (NULL);

k = 0;
m = 0;

if (s1)
{
	while (k < len1)
	{
		s3[k] = s1[k];
		k++;
	}
}

if (s2)
{
	while (k < (len1 + len2))
	{
		s3[k] = s2[m]
		       k++;
			m++;
	}
}
s3[k] = '\0';

return (s3);
}

/*
 * _strcmp - will compare the two string
 * @string1: string1 to be compared
 * @string2; string2 to be compared
 * Return; 0 if  equal, (< 0) if string1 is less than string2 and (> 0) if string 1 is greater than string2 
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
 * _strncmp - to compare the two strings up n bytes
 * @s2: intial string to be compared against
 * @s2: the second string to be be compared with the intial
 * @n: bytes to be compared
 * Return: 0 if different, nonzero if same
 */

int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int k = 0;

	while (*s1 == *s2 && k < n)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		k++;
	}
return (i != n);
}
