#include "shell.c"

/**
 * is_builtinns - checks if the command is a inbuilt
 * @text: text from input, passed in to free
 * @program_name: the program
 * @argv: text parsed
 * @k: pointes of the variable increased
 * @head: doubled pointer of the env list
 * description: compare inbuilt input
 *
 * Return: 0 to the main
 */

int is_builtinns(char *line, char **argv, char program_name; int *k, env_t **head)
{
	int d,z;
	long int q;

	if (!_strcmp(argv[0], "exit"))
	{
		long int q = exit_handlern(argv);

		if (q == -1)
			print_error_exitt(k, program_name, argv);
		else
		{
			free_everything(argv);
			free(text);
			free_listtsn(head);
			exit(q);
		}
		return (1);
	}

	if (!_strcmp(argv[0], "env"))
	{
		int d = env_handlern(argv, head);

		if (d == -1)
			print_error_envi(argv);
		return (1);
	}

	if (!_strcmp(argv[0], "setenv") || !_strcmp(argv[0], "unsetenv"))
	{
		setenv_handlern(argv, head, k, program_name);
		return (10);
	}

	if (!_strcmp(argv[0], "cd"))
	{
		int z = cd_handlern(argv, head);

		if (z == -1)
		{
			print_error_cdd(k, program_name, argv);
			write(2, "\n", 1);
		}
		return (1);
	}
	return (0);
}

/**
 * exit_handlern - handles the builtinn exit
 * @tokens: array of strings from cmd line
 * description: In absence of second token,
 * Return num (0)
 *
 * Return: 0 no args, -1 failure
 */

long int exit_handlern(char **tokens)
{
	int flag = 0, k;
	long int num = 0;

	if (tokens[1] == NULL)
		return (num);
	for (k = 0; tokens[1][k]; k++)
	{
		if ((tokens[1][k] >= '0' && tokens[1][k] <= '9') || tokens[1][0] == '+')
		{
			flag = 1;
			if (tokens[1][i + 1] < '0' || tokens[1][i + 1] > '9')
				break;
		}
		else
			break;
		flag = 0;
	}
	if (flag == 1)
	{
		num = _atoi(tokens[1]);
		return (num);
	}
	return (-1);
}

/**
 * env_handlern - replicates bash
 * @av: args from cmd
 * @head: doubled pointer
 *
 * Return: 0 on success, -1 on error
 */
int env_handlern(char **av, env_t **head)
{
	if (av[1] == NULL)
	{
		print_listts(*head);
		return (0);
	}
	return (-1);
}
