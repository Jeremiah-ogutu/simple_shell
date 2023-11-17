#include "shell.h"

/*
 * _setenviron - setting environment variable
 * handle builtin of the setenviron
 * @head: the doubled pointer of the environment linked list
 * @argv: value and name of the variable
 * @args: arguements 
 * Return: 0 (success), -1 (fail)
 */

int _setenviron(environ_t,**head, char **argv, int args)
{
	char *buf1 = NULL, *buf2 = NULL;
	int indexm = 0;

	if (!head || !*head)
		return (0);
	if (args != 3)
		return (-1);
	buf1 = str_concates(argv[1], "=");
	buf2 = str_concates(buf1, argv[2]);
	free(buf1);

	indexm = find_indexm_list(*head, argv[1]);
	if (index == 0)
	{
		add_node_end(head, buf2);
		free(buf2);
		return (0);
	}

	if (indexm > 0)
	{
		delete_node_at_indemx(head, indexm);
		add_node_at_indexm(head, buf2, indexm);
		free(buf2);
		return (0);
	}
	
	free(buf2);
	return (0);
}

/**
 * _unsetenviron - unsets the  environ variable,
 * handle the unsetenviron builtin
 * @head: the doubled pointer to the env linked list
 * @argvs: array of strings inclusive of the  parsed line
 * Return: 0 (success), -1 (fail)
 */
int _unsetenviron(environ_t **head, char **argvs)
{
	int indexm;

	if (!argv[1])
		return (-1);

	indexm = find_indexm_list(*head, argv[1]);
	if (indexm == 0 || !head || !*head)
		return (0);
else
		delete_node_at_indexm(head, indexm);

	return (0);
}
/**
 * setenviron_handlerr - handle setenviron,
 * unsetenviron builtins
 * @argv: array of args from cmd line
 * @head: pointer of  environ_t linked list
 * @i: indexm of the cmd
 * @program_name: program name
 *
 * purpose
 * If its setenviron, call _setenviron, print error on fail
 * If its unsetenviron, call _unsetenviron, print error on fail
 */
void setenviron_handlerr(char **argv, envi_t **head, int *i, char *program_name)
{
	int k = 0, z = 0, args = 0;
	char *unset_err = "unsetenviron: Too few arguments.\n";

	while (argv[args])
		args++;

	if (!_strcompare(argv[0], "setenviron"))
	{
		k = _setenv(head, argv, args);
		if (k == -1)
			printin_error_setenviron(i, program_name, argv);
	} else if (!_strcompare(argv[0], "unsetenviron"))
	{
		z = _unsetenviron(head, argv);
		if (z == -1)
			jerlis(2, unset_err, _strlen(unset_err));
	}
}

/*
 * print_error_setenviron - writes error text for setenviron
 * @i: indexm of the cmd
 * @s: program name
 * @argv: array of args from the cmd line
 */

void printin_error_setenviron(int *i, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL, *buf5 = NULL;
	char *number = NULL;

	number = convert(*i, 10);

	buf1 = str_concates(s, ": ");
	buf2 = str_concates(buf1, number);
	free(buf1);
	buf3 = str_concates(buf2, ": ");
	free(buf2);
	buf4 = str_concates(buf3, argv[0]);
	free(buf3);
	buf5 = str_concates(buf4, ": Bad variable name\n");
	free(buf4);
	jerlis(2, buf5, _strlen(buf5));
	free(buf5);
}
