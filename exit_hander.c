#include "shell.h"

/**
 * exit_handler - handles the inbuilt exit with arguments
 * @token: strings of the command line
 * Return: 0 ifelse -1 else the number
 *
 */
long int exit_handler(char **token)
{
	int flag = 0;
	int loop;
	long int number = 0;

	if (token[1] == NULL)
		return (number);

	for (loop = 0; token[1][loop]; loop++)
	{
		if ((token[1][loop] >= '0' && token[1][loop] <= '9') || token[1][0] == '+')
		{
			flag = 1;

			if (token[1][loop + 1] < '0' || token[1][loop + 1] > '9')
				break;
		}
		else
		{
			break;
		}
		flag = 0;
	}

	if (flag == 1)
	{
		number = _atoi(token[1]);
		return (number);
	}
	return (-1);
}

/**
 * env_handler - replicates the env inbuild
 * @cm:arguments in command
 * @head:pointer to the env_t
 * Return:0 else -1
 *
 *
 */
int env_handler(char **cm, env_t **head)
{
	if (cm[1] == NULL)
	{
		print_list(*head);
		return (0);
	}
	return (-1);
}

/**
 * cd_handler - replicate the cd buidin
 * @argv:arguments from the command line
 * @head:pointer to env
 * Return: else 0
 */

int cd_handler(char **argv, env_t **head)
{
	char *root = NULL;
	char *prev = NULL;
	char **env = NULL;

	env = list_to_arr(*head);

	if (!argv[1])
	{
		root = get_env_val("HOME=", env);
		chdir(root);
		change_pwd(root, env, head);
		free_everything(env);
		return (1);
	}
	if (_strcmp(argv[1], "-") == 0)
	{
		prev = get_env_val("OLDPWD=", env);
		_puts(prev);
		change_pwd(prev, env, head);
		chdir(prev);
		free_everything(env);
		return (1);
	}
	if (chdir(argv[1]) < 0)
	{
		free_everything(env);
		return (-1);
	}
	else
	{
		change_pwd(argv[1], env, head);
		free_everything(env);
		return (1);
	}
	return (0);
}

/**
 * change_pwd - helper for cd
 *@path:the pwd to be changed
 *@head:poinetr to env
 *@env:array for env
 */

void change_pwd(char *path, char **env, env_t **head)
{
	char **prev = NULL;
	char **current = NULL;
	int nodes = 0;
	int set = 0;

	prev = malloc(sizeof(char *) * 4);
	prev[0] = strdup("0ld");
	prev[1] = strdup("OLDPWD");
	prev[2] = strdup(get_env_val("PWD=", env));
	prev[3] = NULL;

	current = malloc(sizeof(char *) * 4);
	current[0] = _strdup("current");
	current[1] = _strdup("PWD");
	current[2] = _strdup(path);
	current[3] = NULL;
	nodes = arr_to_list(head, env);
	if (!nodes)
		return;
	set = _setenv(head, prev, 2);
	if (set < 0)
	{
		free_everything(prev);
		free_everything(current);
		return;
	}
	free_everything(prev);
	set = _setenv(head, current, 2);
	if (set < 0)
	{
		free_everything(current);
		return;
	}
	free_everything(current);
}
