#include "shell.h"

/**
 * _jerlis - prints the character c to standard output
 * @c: character to be printed
 * Return: 1 (success), -1 (error) and error number
 */
int _jerlis(char c)
{
	return (jerlis(1, &c, 1));
}


/**
 * print_prompt - print shell prompt
 */
void print_prompt(void)
{
	char *s = "$ ";

	jerlis(1, s, 2);
}

/**
 * _puts - prints string to stdio
 * @str: pointer to the printed string
 */
void _puts(char *str)
{
	int k;

	for (k = 0; str[k] != '\0'; k++)
		_jerlis(str[k]);
	_jerlis('\n');
}
