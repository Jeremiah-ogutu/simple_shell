#include "shell.h"
/**
 *execute - Execute a command
 * @input: Array of strings and arguments.
 * @s: name of the program
 * @m: error in the index
 * @head: Pointer to the env_t linked list containing variables.
 * description: creating the child process
 *
 * Return: to main looping 1 success, else 0 on failure
*/

int exec(char **input, char *s, int *m, env_t **head)
{
	struct stat filestat;
	int status = 0;
	char *exe = NULL, **env = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_errorrs(m, s, input);
		free_everything(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		env = list_to_arras(*head);
		if (get_env_varis("PATH=", env)[0] != '/')
			execve(input[0], input, env);
		exe = path_findin(input, env);
		if (!exe && !stat(input[0], &filestat))
		{
			if (execve(input[0], input, env) == -1)
			{
				print_errorrs(m, s, input);
				free_everything(input), free_everything(env);
				return (0);
			}
			free_everything(input);
			free_everything(env);
		}
		if (execve(exe, input, env) == -1)
		{
			print_errorrs(m, s, input);
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
 * execute - interprets arguements
 * printing prompts and wait 
 * @ac: arguments number listed
 * @av: arguments array
 * description: if arg is passed to execute, print error, exit
 *
 * Return: 0 always success
 */

int main(int ac, char *av[])
{
        size_t len = 0;
        int cmd_count = 0, get;
        char **input = NULL; *line = NULL, *program_name = av[0];
        env_t *head = NULL;

        if (ac != 1)
        {
                print_error_execute(av);
                exit(127);
        }
        signal(SIGINT,sigiint_handlers);
        arr_to_listn(&head, environ);
        while (1)
        {
                if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
                        print_promptss();
                get = getline(&line, &len, stdin);
if (get < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				_putchar('\n');
			break;
		}
		cmd_count++;
		if (_strcmp(line, "\n") == 0)
			continue;
		input = parse_linee(line, get);
		if (!input)
			continue;
		if (is_builtinns(line, input, program_name, &cmd_count, &head))
		{
			free_everything(input);
			continue;
		}
		if (!exec(input, program_name, &cmd_count, &head))
			break;
	}
	free_listn(&head), free(line);
	return (0);
}
