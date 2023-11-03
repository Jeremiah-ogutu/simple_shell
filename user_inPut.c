#include "shell.h"

void user_inPut(char *inPut, size_t size)
{
	if (fgets(inPut, size, stdin) == NULL)
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

	inPut[strcspn(inPut, "\n")] = '\0';
}
