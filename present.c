#include "shell.h"

/**
 * _putchar - writes the character c to standard output
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
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
	int i;

	for (i = 0; str[i] != '\0'; i++)
		jerlis_print(str[i]);
	jerlis_print('\n');
}
