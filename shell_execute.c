#include "shell.h"

void execute_prompt(const char *text)
{
	pid_t childPid = fork();

	if (childPid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if 
		(childPid == 0)
		{
			execlp(text, text, (char *)NULL);
			perror("exclp");
			exit(EXIT_FAILURE);
		}
	else
	{
		wait(NULL);
	}
}
