#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


long int _atoi(char *strg);
char *convert(int number, int base);
int execute(char **input, char *strg, int *i, env_t **head);
int arr_to_list(env_t **head, char **env);
char **list_to_arr(env_t *head);
size_t print_list(env_t *h);
void free_list(env_t **head);
size_t list_len(const env_t *h);
int main(int ac, char *av[]);
int env_handler(char **cm, env_t **head);
int cd_handler(char **argv, env_t **head);
void change_pwd(char *path, char **env, env_t **head);
env_t *add_node_end(env_t **head, char *str);
int delete_node_at_index(env_t **head, unsigned int index);
int add_node_at_index(env_t **head, char *str, int idx);
int find_index_list(env_t *head, char *name);
int inbuild_comd(char *text, char *name, char **argv, int *add, env_t **head);
void sigint_handler(int sig);
void free_everything(char **args);
char **parse_line(char *line, int get);
void unveil_prompt(void);
<<<<<<< HEAD
void executing_text(char *cp, **command);n
void input_text(char *text, size_t size);
int _strlen(char *string);
char *_strcopy(char *dest, char *source);
char *_str_duplicate(char *string);
char str_concates(char *string1, char *string2);
int _strcompare(char *string1, char *string2);
int _strcompare(char *string1, char *string2, unsigned int n);
int countingword(char *str, char delimeter);
char **_strtoken(char *str, char delimeter);
char *path_finding(char **s, char **env);
char **gett_environ(char *name, char **env);
char *get_environ_variable(char *name, char **env);
void printin_error_setenviron(int *i, char *s, char **argv);
void setenviron_handlerr(char **argv, envi_t **head, int *i, char *program_name);
int _unsetenviron(environ_t **head, char **argvs);
int _setenviron(environ_t,**head, char **argv, int args);
void printin_error(int *i, char *s, char **argv)
void printin_error_environ(char **argv);
void printin_error_exitt(int *i, char *s, char **argv);
void printin_error_main(char **av);
void printin_error_cd(int *i, char *s, char **argv);
void jerlis_print(const char *special_printf);
void unveil_prompt(void);
void _puts(char *str);

#endif
