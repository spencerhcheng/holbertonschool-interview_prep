#include "lists.h"

/**
 * is_palindrome - functon that checks
 * if the singly linked list is a palindrome
 * @head: pointer to first node
 * Return: 0 if not a palindrome, else 1
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp;
	listint_t *head_2;

	tmp = *head;
	head_2 = NULL;

	while (tmp != NULL)
	{
		add_node_begin(&head_2, tmp->n);
		tmp = tmp->next;
	}
	print_listint(head_2);
	return (check_lists(head, &head_2));
}

/**
 * check_lists - function that checks
 * if the singly linked list and the reversed list values
 * are the same
 * @head: pointer to pointer to first node of original list
 * @head_2: pointer to pointer to first node of reversed list
 * Return: 0 if not a palindrome, else 1
 */

int check_lists(listint_t **head, listint_t **head_2)
{
	listint_t *tmp;
	listint_t *tmp_2;

	tmp = *head;
	tmp_2 = *head_2;

	while (tmp != NULL && tmp_2 != NULL)
	{
		if (tmp->n != tmp_2->n)
		{
			return (0);
		}
		tmp = tmp->next;
		tmp_2 = tmp_2->next;
	}
	return (1);
}


/**
 * add_node_begin - function that adds
 * to the beginning of a linked list
 * @head: pointer to pointer of first node
 * @n: integer to be included in new node
 * Return: address of the new element of NULL if fails
 */

listint_t *add_node_begin(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		return (new_node);
	}

	else
	{
		new_node->next = *head;
		*head = new_node;
	}
	return (new_node);
}
