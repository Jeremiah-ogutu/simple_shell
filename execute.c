#include "shell.h"
/**
 *execute - Execute a command.
 *
 * @input: Array of strings representing the command and its arguments.
 * @strg: String representing the command line input.
 * @i: Pointer to the increment variable of the main program.
 * @head: Pointer to the env_t linked list representing environment variables.
 *
 * Return:1 sucess else 0
*/

int execute(char **input, char *strg, int *i, env_t **head)
{
	struct stat filestat;
	int status = 0;
	char *exe = NULL, **env = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_error(i, strg, input);
		free_everything(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		env = list_to_arr(*head);
		if (get_env_val("PATH=", env)[0] != '/')
			execve(input[0], input, env);
		exe = path_finder(input, env);
		if (!exe && !stat(input[0], &filestat))
		{
			if (execve(input[0], input, env) == -1)
			{
				print_error(i, strg, input);
				free_everything(input), free_everything(env);
				return (0);
			}
			free_everything(input);
			free_everything(env);
		}
		if (execve(exe, input, env) == -1)
		{
			print_error(i, strg, input);
			free(exe), free_everything(input), free_everything(env);
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(&status);
	free_everything(input), free_everything(env);
	return (1);
}

