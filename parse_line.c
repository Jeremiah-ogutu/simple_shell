#include "shell.h"

/**
 * sigint_handlern - no exit with  Ctrl-C
 * @sig: signal funcs
 * Description: print line & prompt while ignoring sig
 */
void sigint_handlern(int sig)
{
	(void)sig;
	 _putchar('\n');
	 print_prompt();
	 fflush(stdout);
}

/**
 * free_everything - frees arrays strings
 * @args:strings to be freed
 */
void free_everything(char **args)
{
	int k;

	if (!args)
		return;

	for (k = 0; args[k]; k++)
		free(args[k]);

	free(args);
}

/**
* parse_lines - handles newline & parses input 
* @line: stdin line
* @get: return acquired line
*
* Return: the line parsed
*/
char **parse_linee(char *line, int get)
{
	char **input = NULL;

	if (line[get - 1] == '\n')
		line[get - 1] = '\0';
	input = _strtok(line, ' ');

	return (input);
}
