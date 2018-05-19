#include "lists.h"
#include <stdio.h>
/**
 * check_cycle - A function that checks whether
 * a linked list has a cycle or not
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is
 */

int check_cycle(listint_t *list)
{
	listint_t *slow;
	listint_t *fast;
	short first_flag;

	if (list == NULL)
		return (0);

	slow = list;
	fast = list;

	first_flag = 0;

	while (slow != NULL || fast != NULL)
	{
		if ((slow == fast && first_flag == 1) || fast->next == slow)
			return (1);

		first_flag = 1;

		slow = slow->next;
		if (fast->next->next != NULL)
			fast = fast->next->next;
		else
			return (0);
	}
	return (0);
}
