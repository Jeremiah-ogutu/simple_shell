#include "shell.h"

/**
* get_environ_variable - get environ variable value
* @name: environ key to be checked
* @env: array of str in the environ cpy
* Return: name of the value located in env
*/

char *get_environ_variable(char *name, char **env)
{
	int k;

	for (k = 0; env[k]; k++)
		if (_strcompare(env[k], name, _strlen(name)) == 0)
			return (env[k] + _strlen(name));
	return (NULL);
}

/**
* gett_environ - convert string PATH to array of strings
* @name: key equals value t
* @env: contains array of strings of the environ cpy
* Return: value at key, in the form of an array of strings
*/

char **gett_environ(char *name, char **env)
{
	char **value = NULL, **path = NULL;
	int k;

	for (k = 0; env[k]; k++)
	{
		path = _strtok(env[k], '=');
		if (_strcmp(name, path[0]) == 0)
		{
			value = _strtok(path[1], ':');
			free_everything(path);
			return (value);
		}
		else
			free_everything(path);
	}
	free_everything(path);
	free_everything(value);
	return (NULL);
}
/**
* path_finding- connect PATH directories and whether executable
* @s: input, as [strings]
* @env: contains [strings] of environ cpy
* Return: success if string concatenates or  NULL if fail
*/
char *path_finding(char **s, char **env)
{
	int k;
	char *dir = NULL;
	char *prog = NULL;
	char **path_value = NULL;

	path_value = get_env("PATH", env);
	if (!path_value)
	{
		free_everything(path_value);
		return (NULL);
	}

	for (k = 0; path_value[i]; i++)
	{
		dir = str_concates(path_value[i], "/");
		prog = str_concates(dir, s[0]);

		if (access(prog, X_OK) == 0)
		{
			free_everything(path_value);
			free(dir);
			return (prog);
		}
		free(dir);
		free(prog);
	}
	free_everything(path_value);
	return (NULL);
}
