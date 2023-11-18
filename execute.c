#include "shell.h"
/**
 *execute - Execute a command
 * @input: Array of strings representing the command and its arguments.
 * @s: name of the program
 * @i: error in the index
 * @head: Pointer to the env_t linked list representing environment variables.
 * Return: 1 success, else 0 on fail
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
		printin_error(i, s, input);
		free_everything(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		env = listng_to_arr(*head);
		if (get_environ_val("PATH=", env)[0] != '/')
			execve(input[0], input, env);
		exe = path_finding(input, env);
		if (!exe && !stat(input[0], &filestat))
		{
			if (execve(input[0], input, env) == -1)
			{
				printin_error(i, s, input);
				free_everything(input), free_everything(env);
				return (0);
			}
			free_everything(input);
			free_everything(env);
		}
		if (execve(exe, input, env) == -1)
		{
			printin_error(i, s, input);
			free(exe), free_everything(input), free_everything(env);
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(&status);
	free_everything(input), free_everything(env);
	return (1);
}

/**
 * execute - interprets args, printing prom and wait as user input cmd
 * @ac: arguments number listed
 * @av: arguments array
 * Return: 0 always successful
 */

int main(int ac, char *av[])
{
        size_t len = 0;
        int cmd_count = 0;
        int get;
        char **input = NULL;
        int *line = NULL;
        int *program_name = av[0];
        env_t *head = NULL;

        if (ac != 1)
        {
                printin_error_main(av);
                exit(127);
        }
        signal(SIGINT,sigi_handlerin);
        arr_to_listng(&head, environ);
        while (1)
        {
                if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
                        unveil_prompt();
                get = getline(&line, &len, stdin);
if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				jerlis('\n');
			break;
		}
		cmd_count++;
		if (_strcmp(line, "\n") == 0)
			continue;
		input = parsing_line(line, get);
		if (!input)
			continue;
		if (inbuild_comd(line, input, program_name, &cmd_count, &head))
		{
			free_everything(input);
			continue;
		}
		if (!exec(input, program_name, &cmd_count, &head))
			break;
	}
	free_listin(&head), free(line);
	return (0);
}
