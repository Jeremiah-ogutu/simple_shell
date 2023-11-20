#include "shell.h"

/*
 * _setenv - setting environment variable
 * handle builtinns of the setenv
 * @head: the doubled pointer of the environment linked list
 * @argv: value and name of the variable
 * @args: arguements 
 * description: returns NULL on an empty list 
 *
 * Return: 0 (success), -1 (fail)
 */

int _setenv(env_t,**head, char **argv, int args)
{
	char *buf1 = NULL, *buf2 = NULL;
	int index = 0;

	if (!head || !*head)
		return (0);
	if (args != 3)
		return (-1);
	buf1 = str_concat(argv[1], "=");
	buf2 = str_concat(buf1, argv[2]);
	free(buf1);

	index = find_index_listn(*head, argv[1]);
	if (index == 0)
	{
		add_node_endd(head, buf2);
		free(buf2);
		return (0);
	}

	if (index > 0)
	{
		delete_node_at_indexs(head, index);
		add_node_at_indexs(head, buf2, index);
		free(buf2);
		return (0);
	}
	
	free(buf2);
	return (0);
}

/**
 * _unsetenv - unsets the  environ variable,
 * handle the unsetenviron builtin
 * @head: the doubled pointer to the env linked list
 * @argvs: array of strings
 * description: in absence of args
 * Return: 0 (success), -1 (fail)
 */
int _unsetenv(env_t **head, char **argvs)
{
	int index;

	if (!argv[1])
		return (-1);

	index = find_index_listn(*head, argv[1]);
	if (index == 0 || !head || !*head)
		return (0);
else
		delete_node_at_indexs(head, index);

	return (0);
}
/**
 * setenv_handlern - handle setenvironment,
 * unsetenv builtinns
 * @argv: array of args from cmd line
 * @head: pointer of  environ_t linked list
 * @m: index of the cmd
 * @program_name: program name
 *
 * purpose
 * If its setenvironment, call _setenv, print error on fail
 * If its unsetenviron, call _unsetenv, print error on fail
 */
void setenv_handlern(char **argv, envi_t **head, int *m, char *program_name)
{
	int k = 0, z = 0, args = 0;
	char *unset_err = "unsetenv: few arguments.\n";

	while (argv[args])
		args++;

	if (!_strcmp(argv[0], "setenv"))
	{
		k = _setenv(head, argv, args);
		if (k == -1)
			print_error_setenvi(m, program_name, argv);
	} else if (!_strcmp(argv[0], "unsetenv"))
	{
		z = _unsetenv(head, argv);
		if (z == -1)
			write(2, unset_err, _strlen(unset_err));
	}
}

/*
 * print_error_setenvi - writes error text for setenviron
 * @m: index of the cmd
 * @s: program name
 * @argv: array of args from the cmd line
 * purpose; contenates strings
 */

void print_error_setenvi(int *m, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL, *buf5 = NULL;
	char *number = NULL;

	number = convert(*m, 10);

	buf1 = str_concat(s, ": ");
	buf2 = str_concat(buf1, number);
	free(buf1);
	buf3 = str_concat(buf2, ": ");
	free(buf2);
	buf4 = str_concat(buf3, argv[0]);
	free(buf3);
	buf5 = str_concat(buf4, ": substd var name\n");
	free(buf4);
	write(2, buf5, _strlen(buf5));
	free(buf5);
}
