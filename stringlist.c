#include "shell.h"

/**
* add_node - fn name
* @head: we malo
* @str: we malo ya gam
* @num: this is the num
*
* Return: we malo ya gameel
*/

l_t *add_node(l_t **head, const char *str, int num)
{
	l_t *n_h;

	if (!head)
		return (NULL);
	n_h = malloc(sizeof(l_t));
	if (!n_h)
		return (NULL);
	_memset((void *)n_h, 0, sizeof(l_t));
	n_h->num = num;
	if (str)
	{
		n_h->str = _strdup(str);
		if (!n_h->str)
		{
			free(n_h);
			return (NULL);
		}
	}
	n_h->next = *head;
	*head = n_h;
	return (n_h);
}

/**
* add_node_end - fn name
* @head: we malo
* @str: we malo ya gam
* @num: this is the num
*
* Return: we malo ya gameel
*/

l_t *add_node_end(l_t **head, const char *str, int num)
{
	l_t *n_n, *node;

	if (!head)
		return (NULL);

	node = *head;
	n_n = malloc(sizeof(l_t));
	if (!n_n)
		return (NULL);
	_memset((void *)n_n, 0, sizeof(l_t));
	n_n->num = num;
	if (str)
	{
		n_n->str = _strdup(str);
		if (!n_n->str)
		{
			free(n_n);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_n;
	}
	else
		*head = n_n;
	return (n_n);
}


/**
* p_list_str - fn name
* @head: we malo
*
* Return: we malo ya gameel
*/

size_t p_list_str(const l_t *head)
{
	size_t index = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		index++;
	}
	return (index);
}

/**
* delete_node_i - fn name
* @head: we malo
* @i: index ya baba
*
* Return: we malo ya gameel
*/

int delete_node_i(l_t **head, unsigned int i)
{
	l_t *node, *previous_node;
	unsigned int j = 0;

	if (!head || !*head)
		return (0);

	if (!i)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}

	node = *head;
	while (node)
	{
		if (j == i)
		{
			previous_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		j++;
		previous_node = node;
		node = node->next;
	}
	return (0);
}

/**
* free_list - fn name
* @head: we malo
*/

void free_list(l_t **head)
{
	l_t *node, *n_node, *h;

	if (!head || !*head)
		return;

	h = *head;
	node = h;
	while (node)
	{
		n_node = node->next;
		free(node->str);
		free(node);
		node = n_node;
	}
	*head = NULL;
}
