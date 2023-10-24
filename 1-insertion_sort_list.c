#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: Double pointer to the head of the list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *next_node;

	if (list == NULL || *list == NULL)
	{
		return;
	}

	curr_node = (*list)->next;
	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		while (curr_node->prev != NULL && curr_node->prev->n > curr_node->n)
		{
			curr_node->prev->next = curr_node->next;
			if (curr_node->next != NULL)
				curr_node->next->prev = curr_node->prev;
			curr_node->next = curr_node->prev;
			curr_node->prev = curr_node->next->prev;
			curr_node->next->prev = curr_node;
			if (curr_node->prev == NULL)
				*list = curr_node;
			else
				curr_node->prev->next = curr_node;
			print_list(*list);
		}
		curr_node = next_node;
	}
}
