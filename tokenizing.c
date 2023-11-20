#include "shell.h"

/*
 * wordcountt - counting string tokens
 * @str: the string to count
 * @delim: a delimeter found between the tokens
 * description: loop and count tokens
 *
 * Return: number of counted tokens
*/

int wordcountt(char *str, char delim)
{
	int num = 0, k;
	int flag = 0;

	for (k = 0; str[k]; k++)
	{
		if (str[k] == delim)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			num++;
		}
	}
	return (num);
}

/*
 * _strtok - to converts the string to tokens
 * @str: string to be tokenized
 * @delimeter: the delimeter inbetween the tokens
 * description: convert into tokens
 *
 * Return: pointer to strings array if success and NULL on fail
 */

char **_strtok(char *str, char delim)
{
	char *cpy = NULL, **words = NULL;
	int k = 0, n = 0, len = 0, total = 0;

	if (str == 0 || *str == 0)
		return (NULL);
	total = wordcountt(str, delim);
	if (total == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL)
		return (NULL);
	while (*str && k < total)
	{
		if (*str == delim)
			str++;
		else
		{
			cpy = str;
			while (*str != delim && *str)
			{
				len++;
				str++;
			}
			words[k] = malloc(sizeof(char) * (len + 1));
			if (!words[j])
				return (NULL);
			while (*cpy != delim && *cpy && *cpy != '\n')
			{
				words[k][n] = *cpy;
				cpy++;
				n++;
			}
			words[k][n] = '\0';
			k++;
			n = 0;
			len = 0;
		}
	}
	words[j] = NULL;
	return (words);
}
