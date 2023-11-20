#include "shell.h"

/**
 * arr_to_listng - convert the env variable to linked list
 * @head: doubled pointer to  environ_t list 
 * @env: [strings] hosting the env variables
 * description: to free all existing lists
 *
 * Return: nodes number
 */
int arr_to_listn(env_t **head, char **env)
{
	int k = 0;

	if (head)
		free_listn(head);

	while (env[k])
	{
		add_node_endd(head, env[k]);
		k++;
	}
	return (k);
}

/**
 * list_to_arras - convert a linked list to [strings]
 * @head: pointer to the env_t list
 * Return: array adress, or NULL if failure
 */

char **list_to_arras(env_t *head)
{
	env_t *temp = head;
	char **arr = NULL, *s = NULL;
	size_t size = 0;
	int k;

	size = list_lenn(head);

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
		s = _strcpy(s, temp->str);
		arr[k] = s;
	}
	arr[k] = NULL;

	return (arr);
}

/**
 * print_listts - prints nodes in the linked list
 * @m: points to the list_t to be printed
 *
 * Return: printed number of nodes
 */
size_t print_listts(env_t *m)
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
 * free_listts - frees nodes in the linked list
 * @head: list_t list to  free
 */
void free_listts(env_t **head)
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
 * list_lenn - to return number elements the linked list
 * @m: pointer to the env_t list
 * Return: number elements found in m
 */

size_t list_lenn(const env_t *m)
{
	size_t n = 0;

	while (m)
	{
		n++;
		m = m->next;
	}
	return (n);
}
