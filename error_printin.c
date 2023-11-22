#include "shell.h"

/**
 * print_errorrs - print error text
 * @m: index of the cmd
 * @z: program name
 * @argv: array of args from the cmd line
 * purpose: contenates the strings
 */
void print_errorrs(int *m, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL, *buf5 = NULL;
	char *number = NULL;

	number = convert(*m, 10);

	buf1 = str_concat(z, ": ");
	buf2 = str_concat(buf1, number);
	free(buf1);
	buf3 = str_concat(buf2, ": ");
	free(buf2);
	buf4 = str_concat(buf3, argv[0]);
	free(buf3);
	buf5 = str_concat(buf4, ": absent\n");
	free(buf4);
	write(2, buf5, _strlen(buf5));
	free(buf5);
}

/**
 * print_error_envi - print error text for env builtin
 * @argv: array of args from cmd line
 * purspose: to concate the strings
 */

void print_error_envi(char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL;

	buf1 = str_concat(argv[0], ": ");
	buf2 = str_concat(buf1, argv[1]);
	free(buf1);
	buf3 = str_concat(buf2, ": No such file or directory\n");
	free(buf2);
	write(2, buf3, _strlen(buf3));
	free(buf3);
}

/**
 * print_error_exitt - print error message to  exit builtin
 * @m: index of the cmd
 * @z: program name
 * @argv: array of args from cmd line
 * purpose: concatenate strings
 */

void print_error_exitt(int *m, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL;
	char *buf4 = NULL, *buf5 = NULL, *buf6 = NULL, *buf7 = NULL;
	char *number = NULL;

	number = convert(*m, 10);

	buf1 = str_concat(z, ": ");

	buf2 = str_concat(buf1, number);
	free(buf1);
	buf3 = str_concat(buf2, ": ");
	free(buf2);
	buf4 = str_concat(buf3, argv[0]);
	free(buf3);
	buf5 = str_concat(buf4, ": Number illegal: ");
	free(buf4);
	buf6 = str_concat(buf5, argv[1]);
	free(buf5);
	buf7 = str_concat(buf6, "\n");
	free(buf6);
	write(2, buf7, _strlen(buf7));
	free(buf7);
}

/**
 * print_error_execute - print error text for execute
 * @av: args passed to main
 * purpose: to concatenate strings
 */

void print_error_execute(char **av)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL;

	buf1 = str_concat(av[0], ": 0: Cannot open ");
	buf2 = str_concat(buf1, av[1]);
	free(buf1);
	buf3 = str_concat(buf2, "\n");
	free(buf2);
	write(2, buf3, _strlen(buf3));
	free(buf3);
}

/**
 * print_error_cdss - prints error text for cd
 * @m: index of the cmd
 * @z: program name
 * @argv: array of args from the cmd line
 */

void print_error_cdss(int *m, char *s, char **argv)
{
	char *buf1 = NULL, *buf2 = NULL, *buf3 = NULL, *buf4 = NULL;
	char *buf5 = NULL, *buf6 = NULL;
	char *number = NULL;

	number = convert(*m, 10);

	buf1 = str_concat(z, ": ");
	buf2 = str_concat(buf1, number);
	free(buf1);
	buf3 = str_concat(buf2, ": ");
	free(buf2);
	buf4 = str_concat(buf3, argv[0]);
	free(buf3);
	buf5 = str_concat(buf4, ": willn't cd to ");
	free(buf4);
	buf6 = str_concat(buf5, argv[1]);
	free(buf5);
	write(2, buf6, _strlen(buf6));
	free(buf6);
}
