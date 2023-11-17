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



#endif
