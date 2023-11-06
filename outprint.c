#include "shell.h"

void input_text(char *text, size_t size)
{
	if (fgets(text, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			jerlis_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			jerlis_print("Error no search file or folder.\n");
			exit(EXIT_FAILURE);
		}
	}
	text[strcspn(text, "\n")] = '\0';
}