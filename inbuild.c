#include "shell.c"

/**
 * inbuild_comd - checks if the command is a inbuilt
 * @text: text from input, passed i to free
 * @name:name of the program
 * @argv:the command passed
 * @add: pointer to the increaced variable
 * @head:pointer to the env list
 * Return:0
 */

int inbuild_comd(char *text, char *name, char **argv, int *add, env_t **head)
{
	if (!_strcmp(argv[0], "exit"))
	{
		long int m = exit_hadler(argv);

		if (m == -1)
			print_error_exit(add, name, argv);
		else
		{
			free_everything(argv);
			free(text);
			free_list(head);
			exit(m);
		}
		return (1);
	}

	if (!_strcmp(argv[0], "env"))
	{
		int n = env_handler(argv, head);

		if (n == -1)
			print_error_env(argv);
		return (1);
	}

	if (!_strcmp(argv[0], "setenv") || !_strcmp(argv[0], "unsetenv"))
	{
		setenv_handler(argv, head, add, name);
		return (10);
	}

	if (!_strcmp(argv[0], "cd"))
	{
		int l = cd_handle(argv, head);

		if (l == -1)
		{
			print_error_cd(add, name, argv);
			jerlis_print(2, "\n", 1);
		}
		return (1);
	}
	return (0);
}
