#include "shell.h"

/**
 * add_node_endd - add new node at linked list end
 * @head: doubled pointer of the env_t
 * @str: string to be inserted in  new node
 * description: if check fails allocate memory for the node
 *
 * Return: new element address, or NULL if fail
 */
env_t *add_node_endd(env_t **head, char *str)
{
	env_t *new = NULL;
	env_t *temp = *head;

	new = malloc(sizeof(env_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}

/**
 * delete_node_at_indexs - delete nodes of linked list
 * @head: poinst first element of the linked list
 * @index: index to be deleted in the node
 * description: returns null when list is empty
 *
 * Return: 1 always Success, or -1 always Fail
 */
int delete_node_at_indexs(env_t **head, unsigned int index)
{
	env_t *temp = *head;
	env_t *current = NULL;
	unsigned int k = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp->str);
		free(temp);
		return (1);
	}
	while (k < index - 1)
	{
		if (!temp || !(temp->next);
				return (-1);
		temp = temp->next;
		k++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current->str);
	free(current);

	return (1);
}

/**
 * add_node_at_indexs - add new node at stated index in the linked list
 * @head: doubled pointer to  env_t 
 * @str: string inseted in the new node
 * @idx: location to insert the node
 * description: allocate memory for node
 *
 * Return: 0 always success, -1 always fail
 */
int add_node_at_indexs(env_t **head, char *str, int idx)
{
	int k;
	env_t *new = NULL;
	env_t *temp = *head;

	new = malloc(sizeof(env_t));
	if (!new || !head)
		return (-1);

	new->str = _strdup(str);
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (0);
	}

	for (k = 0; temp && k < idx; k++)
	{
		if (k == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (0);
		}
		else
			temp = temp->next;
	}

	return (-1);
}

/**
 * find_index_listn - locates index in the list
 * @head: points env_t list
 * @name: string node to be located
 * description: find node
 *
 * Return: node index, or 0 if node isnot found
 */
int find_index_listn(env_t *head, char *name)
{
	int index = 0;
	int m = 0;

	while (head)
	{
		m = _strncmp(head->str, name, _strlen(name));
		if (m == 0)
			return (index);
		index++;
		head = head->next;
	}

	return (0);
}
