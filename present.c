#include "shell.h"

/**
 * _putchar - print chars c
 * @c: This is the chars  printed
 *
 * Return: if successful
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_promptss - helps print the prompt
 */
void print_prompt(void)
{
	char *s = "$ ";

	write(1, s, 2);
}

/**
 * _puts - prints string
 * @str: points to string
 */
void _puts(char *str)
{
	int k;

	for (k = 0; str[k] != '\0'; k++)
		_putchar(str[k]);
	_putchar('\n');
}
