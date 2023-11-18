#include "shell.h"

/**
 * jerlis_print - print character c to std output
 * @c: character to be printed
 * Return: 1 success always, -1 error and set errno
 */

void jerlis_print(const char *special_printf)
{
        write(STDOUT_FILENO, special_printf, strlen(special_printf));
}

/**
 * unveil_prompt - promt to be displayed
*/

void unveil_prompt(void)
{
        jerlis_print("jerlis_shell$ ");
}


/**
 * _puts - prints a string to standard output
 * @str: pointer to the string to print
 */
void _puts(char *str)
{
	int k;

	for (k = 0; str[k] != '\0'; k++)
		jerlis_print(str[k]);
	jerlis_print('\n');
}
