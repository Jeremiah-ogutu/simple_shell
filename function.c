#include "shell.h"

/**
 * env_t *addin_node_end - add new node at linked list end
 * @head: doubled pointer of the env_t
 * @str: string to be inserted in  new node
 * Return: new element address, or NULL if fail
 */
env_t *addin_node_end(env_t **head, char *str)
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
 * deleting_node_at_index - delete nodes of linked list
 * @head: poinst first element of the linked list
 * @index: index to be deleted in the node
 * Return: 1 always Success, or -1 always Fail
 */
int deleting_node_at_index(env_t **head, unsigned int index)
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
 * addin_node_at_index - adding new node at stated index in the linked list
 * @head: doubled pointer to  env_t 
 * @str: string inseted in the new node
 * @idkx: location to insert the node
 * Return: 0 always success, -1 always fail
 */
int addin_node_at_index(env_t **head, char *str, int idkx)
{
	int k;
	env_t *new = NULL;
	env_t *temp = *head;

	new = malloc(sizeof(env_t));
	if (!new || !head)
		return (-1);

	new->str = _strdup(str);
	new->next = NULL;

	if (idkx == 0)
	{
		new->next = *head;
		*head = new;
		return (0);
	}

	for (k = 0; temp && k < idkx; k++)
	{
		if (k == idkx - 1)
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
 * findin_index_list - locates index in the list
 * @head: points env_t list
 * @namedd: string node to be located
 * Return: node index, or 0 if node isnot located
 */
int findin_index_list(env_t *head, char *namedd)
{
	int index = 0;
	int a = 0;

	while (head)
	{
		a = _strncmp(head->str, name, _strlen(namedd));
		if (c == 0)
			return (index);
		index++;
		head = head->next;
	}

	return (0);
}
