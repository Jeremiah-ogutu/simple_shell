#include "shell.h"

void user_inPut(char *text, size_t size)
{
	if (fgets(text, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else 
		{
			shell_printf("command does not exit.\n");
			exit(EXIT_FAILURE);
		}
	}

	text[strcspn(text, "\n")] = '\0';
}
