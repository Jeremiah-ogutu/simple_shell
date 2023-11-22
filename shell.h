#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} env_t;

long int _atoi(char *s);
char *convert(int num, int base);
int _setenv(env_t,**head, char **argv, int args);
int _unsetenv(env_t **head, char **argvs);
void setenv_handlern(char **argv, envi_t **head, int *m, char *program_name);
void print_error_setenvi(int *m, char *s, char **argv);
void print_errorrs(int *m, char *s, char **argv);
void print_error_envi(char **argv);
void print_error_exitt(int *m, char *s, char **argv);
void print_error_execute(char **av);
void print_error_cdss(int *m, char *s, char **argv)
int exec(char **input, char *s, int *m, env_t **head);
int main(int ac, char *av[]);
int arr_to_listn(env_t **head, char **env);
char **list_to_arras(env_t *head);
size_t print_listts(env_t *m);
void free_listts(env_t **head);
size_t list_lenn(const env_t *m);
env_t *add_node_endd(env_t **head, char *str);
int delete_node_at_indexs(env_t **head, unsigned int index);
int add_node_at_indexs(env_t **head, char *str, int idx);
int find_index_listn(env_t *head, char *name);
int is_builtinns(char *line, char **argv, char program_name; int *k, env_t **head);
long int exit_handlern(char **tokens);
int env_handlern(char **av, env_t **head);
void sigint_handlern(int sig);
void free_everything(char **args);
char **parse_linee(char *line, int get);
char *path_finderss(char **s, char **env);
char **get_envs(char *name, char **env);
char *get_env_varis(char *name, char **env);
int _putchar(char c);
void print_promptss(void);
void _puts(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdups(char *str);
char str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, unsigned int n);
char **_strtok(char *str, char delim);
int wordcountt(char *str, char delim);

#endif
