#include "shell.h"

/**
  * executing_text - Execute a command.
  * @cp: The name of the command.
  * @command: arrays of pointers
  * Return: 0 (success)
  */
void executing_text(char *cp, char **command)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, command, env);
		perror(cp);
		free(cp);
		free_buffers(command);
		exit(98);
	}
	else
		wait(&status);
}
