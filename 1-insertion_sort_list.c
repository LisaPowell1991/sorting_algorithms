#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the list that is going to be sorted.
 *
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		previous_node = current->prev;

		while (previous_node != NULL && previous_node->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = previous_node;
			previous_node->next = temp->next;
			temp->prev = previous_node->prev;
			temp->next = previous_node;

			if (previous_node->prev != NULL)
				previous_node->prev->next = temp;
			previous_node->prev = temp;

			if (previous_node == *list)
				*list = temp;

			print_list(*list);

			previous_node = temp->prev;
		}
		current = current->next;
	}
}
