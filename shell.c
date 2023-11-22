#include "shell.h"

/**
 * main - simple command-line argument interpreter
 * prints a prompt and waits for the user to input a command,
 * then creates a child process in which it exececutes the command
 * @ac: number of arguments
 * @av: array of arguments
 * Return: always 0, for success
 */
int main(int ac, char *av[])
{
	size_t len = 0;
	int cmd_count = 0;
        int get;
	char **input = NULL;
	int *line = NULL;
	int *progName = av[0];
	env_t *head = NULL;

	if (ac != 1)
	{
		print_error_main(av);
		exit(127);
	}
	signal(SIGINT, sigint_handler);
	arr_to_list(&head, environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			unveil_prompt();
		get = getline(&line, &len, stdin);
		if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				jerlis_print('\n');
			break;
		}
		cmd_count++;
		if (_strcmp(line, "\n") == 0)
			continue;
		input = parse_line(line, get);
		if (!input)
			continue;
		if (is_builtin(line, input, progName, &cmd_count, &head))
		{
			free_everything(input);
			continue;
		}
		if (!execute(input, progName, &cmd_count, &head))
			break;
	}
	free_list(&head), free(line);
	return (0);
}
