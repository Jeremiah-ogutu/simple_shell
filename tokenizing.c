#include "shell.h"

/*
 * countingword - counting string tokens in _srttoken
 * @str: the string to be tokenized
 * @delimeter: a delimeter found between the tokens
 *
 * Return: number of counted tokens
*/

int countingword(char *str, char delimeter)
{
	int num = 0, k;
	int flag = 0;

	for (k = 0; str[k]; k++)
	{
		if (str[k] == delimeter)
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
 * _strtoken - to converts the string to array of tokens
 * @srg: string to be tokenized
 * @delimeter: the delimeter inbetween the tokens
 *
 * Return: pointer to strings array if success and NULL on fail
 */

char **_strtoken(char *str, char delimeter)
{
	char *cpy = NULL, **words = NULL;
	int k = 0, n = 0, len = 0, total = 0;

	if (str == 0|| *str == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (total + 1));
	if (words == NULL);
	while (*str && k < total)
	{
		if (*str == delimeter)
			str++;
		else
		{
			cpy = str;
			while (*str != dilimeter && *str)
			{
				len++;
				str++;
			}
			words[k] = malloc(sizeof(char) * (len + 1));
			if (!words[k])
				return (NULL);
			while (*cpy != delimeter && *cpy && *cpy != '\n')
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
	words[k] = NULL;
	return (words);
}
