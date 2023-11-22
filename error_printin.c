#include "shell.h"

/**
 * print_error - print error message
 * @i: indexm of the cmd
 * @s: program name
 * @argv: array of args from the cmd line
 */
void print_error(int *i, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL, *buf5 = NULL;
	char *number = NULL;

	number = convert(*i, 10);

	buf1 = str_concates(s, ": ");
	buf2 = str_concates(buf1, number);
	free(number);
	free(buf1);
	buf3 = str_concates(buf2, ": ");
	free(buf2);
	buf4 = str_concates(buf3, argv[0]);
	free(buf3);
	buf5 = str_concates(buf4, ": not found\n");
	free(buf4);
	jerlis_print(2, buf5, _strlen(buf5));
	free(buf5);
}

/**
 * print_error_environ - print error message for env builtin
 * @argv: array of args from cmd line
 */

void print_error_environ(char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL;

	buf1 = str_concates(argv[0], ": ");
	buf2 = str_concates(buf1, argv[1]);
	free(buf1);
	buf3 = str_concates(buf2, ": No such file or directory\n");
	free(buf2);
	jerlis_print(2, buf3, _strlen(buf3));
	free(buf3);
}

/**
 * print_error_exit - print error message to  exit builtin
 * @i: indexm of the cmd
 * @s: program name
 * @argv: array of args from cmd line
 */

void print_error_exit(int *i, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL;
	char *buf4 = NULL, *buf5 = NULL, *buf6 = NULL, *buf7 = NULL;
	char *number = NULL;

	number = convert(*i, 10);

	buf1 = str_concates(s, ": ");

	buf2 = str_concates(buf1, number);
	free(number);
	free(buf1);
	buf3 = str_concates(buf2, ": ");
	free(buf2);
	buf4 = str_concates(buf3, argv[0]);
	free(buf3);
	buf5 = str_concates(buf4, ": The number is illegal: ");
	free(buf4);
	buf6 = str_concates(buf5, argv[1]);
	free(buf5);
	buf7 = str_concates(buf6, "\n");
	free(buf6);
	jerlis_print(2, buf7, _strlen(buf7));
	free(buf7);
}

/**
 * print_error_main - print error text for main
 * @av: args passed to main
 */

void print_error_main(char **av)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL;

	buf1 = str_concates(av[0], ": 0: Cannot open ");
	buf2 = str_concates(buf1, av[1]);
	free(buf1);
	buf3 = str_concates(buf2, "\n");
	free(buf2);
	jerlis_print(2, buf3, _strlen(buf3));
	free(buf3);
}

/**
 * print_error_cd - prints error text for cd
 * @i: indexm of the cmd
 * @s: program name
 * @argv: array of args from the cmd line
 */

void print_error_cd(int *i, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL;
	char *buf5 = NULL, *buf6 = NULL;
	char *number = NULL;

	number = convert(*i, 10);

	buf1 = str_concates(s, ": ");
	buf2 = str_concates(buf1, number);
	free(number);
	free(buf1);
	buf3 = str_concates(buf2, ": ");
	free(buf2);
	buf4 = str_concates(buf3, argv[0]);
	free(buf3);
	buf5 = str_concates(buf4, ": can't cd to ");
	free(buf4);
	buf6 = str_concates(buf5, argv[1]);
	free(buf5);
	jerlis_print(2, buf6, _strlen(buf6));
	free(buf6);
}
