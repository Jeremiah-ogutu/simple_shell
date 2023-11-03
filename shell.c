#include "shell.h"

int main(void)
{
	char text[150];

	while (true)
	{
		shell_prompt();
		user_inPut(text, sizeof(text));
		execute_prompt(text);


	}
	return (0);
}
