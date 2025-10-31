#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			listint_t *prev_node = temp->prev;
			listint_t *next_node = temp->next;

			if (prev_node->prev)
				prev_node->prev->next = temp;
			temp->prev = prev_node->prev;

			temp->next = prev_node;
			prev_node->prev = temp;
			prev_node->next = next_node;

			if (next_node)
				next_node->prev = prev_node;

			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
