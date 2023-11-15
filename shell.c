#include "shell.h"
/**
 * main-the starting point
 *
 * Return:0 success
 */

int main(void)
{

	char text[124];
	const char *command;
	char *arguments[10];

	while (1)
	{
		unveil_prompt();
		input_text(text, sizeof(text));

	if (strcmp(text, "ls") == 0)
	{
		command = "ls";
		arguments[0] = "ls";
		arguments[1] = "-1";
		arguments[2] = NULL;
		executing_text(command, arguments);
	}
	else
	{
		command = text;
		arguments[0] = text;
		arguments[1] = NULL;
		executing_text(command, arguments);
	}
	}
	return (0);
}
