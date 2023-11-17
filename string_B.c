#include "shell.h"

/*
 * _str_duplicate - memory allocation for the duplicate string
 * @string: string to be duplicated
 * Return: new duplicate string if success or NULL if fail
 */

char *_str_duplicate(char *string)
{
	char *duplicate = NULL;
	int z, k = 0;

	if (!string)
		return (NULL);
	while (string[k])
		k++;
	duplicate = malloc(sizeof(char) * k + 1);
	if (!duplicate)
		return (NULL);
	for (z = 0; z < k; z++)
		duplicate[z] = string[z];
	duplicate[z] = '\0';
	return (duplicate);
}

/*
 * str_concates - to concatenate the strings and allocate memory for new string
 * @string1: first string to be concatenated
 * @string2: second string to be concatenated
 * Return: pointer to the new string if success or NULL if fail
 */

char str_concates(char *string1, char *string2)
{
	char *string3 = NULL;
	unsigned int k = 0, m = 0, len1 = 0, len2 = 0;

len1 = _strlen(string1)
len2 = _strlen(string2)

string3 = malloc(sizeof(char) * (len1 + len2 + 1));
if (string == NULL)
	return (NULL);

k = 0;
m = 0;

if (string1)
{
	while (k < len1)
	{
		string3[k] = string1[k];
		k++;
	}
}

if (string2)
{
	while (k < (len1 + len2))
	{
		string3[k] = string2[m]
		       k++;
			m++;
	}
}
string3[k] = '\0';

return (string3);
}

/*
 * _strcompare - will compare the two string
 * @string1: string1 to be compared
 * @string2; string2 to be compared
 * Return; 0 if the strings are equal, (< 0) if string1 is less than string2 and (> 0) if string 1 is greater than string2 
*/

int _strcompare(char *string1, char *string2)
{
	while (*string1 == *string2)
	{
		if (*string1 == '\0')
		{
			return (0);
		}
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}

/*
 * _strcompare - to compare the two strings up n bytes
 * @string2: intial string to be compared against
 * @string2: the second string to be be compared with the intial
 * @n: bytes to be compared
 * Return: 0 if different, nonzero if same
 */

int _strcompare(char *string1, char *string2, unsigned int n)
{
	unsigned int k = 0;
	while (*string1 == *string2 && k < n)
	{
		if (*string1 == '\0')
		{
			return (0);
		}
		string1++;
		string2++;
		k++;
	}
	return (i != n);
}



