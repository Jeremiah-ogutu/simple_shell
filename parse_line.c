#include "shell.h"

/**
 * siginter_handlerin - fails to exit in Ctrl-C case
 * @signal: a signal function is needed to run appropriately
 */
/
void sigi_handlerin(int signal)
{
	(void)signal;
	 jerlis_print('\n');
	 unveil_prompt();
	 fflush(stdout);
}

/**
 * free_everythingg - frees arrays of strings
 * @args: strings array to be freed 
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
* parsing_line - handles character in newline if located and parse input
* @line: line to be readin the  stdinput
* @gett: line size returned 
* Return: output of parsed line
*/
char **parsing_line(char *line, int gett)
{
	char **input = NULL;

	if (line[gett - 1] == '\n')
		line[gett - 1] = '\0';
	input = _strtok(line, ' ');

	return (input);
}
