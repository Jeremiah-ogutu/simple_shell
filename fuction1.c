#include "shell.h"

/**
 * arr_to_listng - convert the env variable to linked list
 * @head: doubled pointer to  environ_t list 
 * @env: [strings] hosting the env variables
 * Return: nodes number
 */
int arr_to_listng(env_t **head, char **env)
{
	int k = 0;

	if (head)
		free_list(head);

	while (env[k])
	{
		add_node_end(head, env[k]);
		k++;
	}
	return (k);
}

/**
 * listng_to_arr - convert a linked list to [strings]
 * @head: pointer to the env_t list
 * Return: array adress, or NULL if fail
 */

char **listng_to_arr(env_t *head)
{
	env_t *temp = head;
	char **arr = NULL, *s = NULL;
	size_t size = 0;
	int k;

	size = list_len(head);

	if (!head || !size)
		return (NULL);

	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);

	for (k = 0; temp; temp = temp->next, k++)
	{
		s = malloc(sizeof(char) * (_strlen(temp->str) + 1));
		if (!s)
		{
			free_everything(arr);
			return (NULL);
		}
		s = _strcopy(s, temp->str);
		arr[k] = s;
	}
	arr[k] = NULL;

	return (arr);
}

/**
 * printlin_list - prints nodes in the linked list
 * @m: points to the list_t to be printed
 *
 * Return: printed number of nodes
 */
size_t printlin_list(env_t *m)
{
	size_t s = 0;

	while (m)
	{
		if (!m->str)
			_puts("(nil)");
		else
			_puts(m->str);
		m = m->next;
		s++;
	}

	return (s);
}

/**
 * freeing_listin - frees nodes in the linked list
 * @head: list_t list to  free
 */
void freeing_listin(env_t **head)
{
	env_t *temp = NULL;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free((*head)->str);
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

/**
 * size_t list_len - to return number elements the linked list
 * @m: pointer to the env_t list
 * Return: number elements found in m
 */

size_t list_len(const env_t *m)
{
	size_t n = 0;

	while (m)
	{
		n++;
		m = m->next;
	}
	return (n);
}
