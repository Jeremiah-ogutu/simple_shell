#include "shell.h"

void execute_prompt(const char *outPut)
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
			execlp(outPut, ooutPut, (char *)NULL);
			perror("exclp");
			exit(EXIT_FAILURE);
		}
	else
	{
		wait(NULL);
	}
}
