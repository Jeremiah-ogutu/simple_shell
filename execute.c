#include "shell.h"

/**
  * Executor_or - executed commands as entered by the authors
  * @cp: commands
  * @cmd: arrays of pointers
  * Return: 0 (success)
  */
void executor_or(char *cp **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
