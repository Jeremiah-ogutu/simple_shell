#include "shell.h"

/**
* get_env_varis - get variable value
* @name: key to be checked
* @env: array of str in the environ cpy
* description: loop and and compare the str
*
* Return: name of the value located in env
*/

char *get_env_varis(char *name, char **env)
{
	int k;

	for (k = 0; env[k]; k++)
		if (_strcmp(env[k], name, _strlen(name)) == 0)
			return (env[k] + _strlen(name));
	return (NULL);
}

/**
* get_envs- convert string PATH to array of strings
* @name: key equals value t
* @env: contains array of strings
* description: parse each string
*
* Return: value at key, in the form of an array of strings
*/

char **get_envs(char *name, char **env)
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
* path_finderss- connect PATH directories and whether executable
* @s: input, as [strings]
* @env: contains [strings] of environ cpy
* description: call get_env
*
* Return: success if string concatenates or  NULL if fail
*/
char *path_finderss(char **s, char **env)
{
	int k;
	char *dir = NULL;
	char *progam = NULL;
	char **path_value = NULL;

	path_value = get_env("PATH", env);
	if (!path_value)
	{
		free_everything(path_value);
		return (NULL);
	}

	for (k = 0; path_value[k]; k++)
	{
		dir = str_concat(path_value[k], "/");
		program = str_concat(dir, s[0]);

		if (access(program, X_OK) == 0)
		{
			free_everything(path_value);
			free(dir);
			return (program);
		}
		free(dir);
		free(program);
	}
	free_everything(path_value);
	return (NULL);
}
