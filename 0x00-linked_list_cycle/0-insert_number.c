#include "lists.h"
#include <stdio.h>

/**
 * insert_node - inserts a number into
 * a sorted singly linked list
 * @head: double pointer to start of list
 * @number: number to insert to node
 * Return: address of the new node, or NULL
 * if failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *tmp;

	tmp = *head;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (tmp)
	{
		if (number < tmp->n)
		{
			new_node->next = tmp;
			*head = new_node;
			return (new_node);
		}
		if (number > tmp->n && tmp->next == NULL)
		{
			new_node->next = tmp->next;
			tmp->next = new_node;
			return (new_node);
		}
		if (tmp->next)
		{
			if (number >= tmp->n && number < tmp->next->n)
			{
				new_node->next = tmp->next;
				tmp->next = new_node;
				return (new_node);
			}
		}
		tmp = tmp->next;
	}
	return (new_node);
}
