#include "shell.h"

/**
* executing_text - fuction that execute command
* @text:the command to be executed
* Return: 0 success
*/

int executing_text(char (*text)[124])
{
	pid_t pid;
	int status;
	char **argv =malloc(2 * sizeof(char *));

	if (argv == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	argv[0] = strdup(*text);
	if (argv[0] == NULL)
	{
		perror("strdup");
		free(argv);
		exit(EXIT_FAILURE);
	}
	argv[1] = NULL;


	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		{

		if (execve(*text, argv, NULL) == -1)
		{
			perror(*text);
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
		{
			return (-1);
		}
	}
	return (-1);
}

