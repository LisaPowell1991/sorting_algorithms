#include  "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of intetegers,
 * in ascending order using the Cocktail shaker sort algorithm.
 * @list: Pointer to the head of list.
 *
 * Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		temp = *list;

		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->next;
		}
		if (!swapped)
			break;
		swapped = 0;

		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps 2 nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @node1: First node to swap.
 * @node2: Second node to swap.
 *
 * Return: Void
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node2->prev == NULL)
		*list = node2;
}
