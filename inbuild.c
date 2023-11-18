#include "shell.c"

/**
 * inbuild_comd - checks if the command is a inbuilt
 * @text: text from input, passed in to free
 * @progm_name: the program
 * @argv: text parsed
 * @k: pointes of the variable increased
 * @head: doubled pointer of the env list
 * Return: 0 (t0 the main)
 */

int inbuild_comd(char *text, char **argv, char program_name; int *k, environ_t **head)
{
	int d,z;
	long int q;

	if (!_strcmp(argv[0], "exit"))
	{
		long int q = exit_handlerin(argv);

		if (q == -1)
			printlin_error_exitt(k, program_name, argv);
		else
		{
			free_everything(argv);
			free(text);
			free_list(head);
			exit(q);
		}
		return (1);
	}

	if (!_strcmp(argv[0], "envi"))
	{
		int d = env_handler(argv, head);

		if (d == -1)
			printin_environ(argv);
		return (1);
	}

	if (!_strcmp(argv[0], "setenvi") || !_strcmp(argv[0], "unsetenvi"))
	{
		setenviron_handler(argv, head, k, prgram_name);
		return (10);
	}

	if (!_strcmp(argv[0], "cd"))
	{
		int z = cd_handlerin(argv, head);

		if (z == -1)
		{
			printin_error_cd(k, program_name, argv);
			jerlis_print(2, "\n", 1);
		}
		return (1);
	}
	return (0);
}
