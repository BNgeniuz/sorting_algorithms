#include "sort.h"

/**
 * swap_node_ahead - Swap list of integers with the node ahead of it.
 * @list: list to pointer
 * @tail: doubly-linked list ptr
 * @cock: cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **cock)
{
	listint_t *pmt = (*cock)->next;

	if ((*cock)->prev != NULL)
		(*cock)->prev->next = pmt;
	else
		*list = pmt;
	pmt->prev = (*cock)->prev;
	(*cock)->next = pmt->next;
	if (pmt->next != NULL)
		pmt->next->prev = *cock;
	else
		*tail = *cock;
	(*cock)->prev = pmt;
	pmt->next = *cock;
	*cock = pmt;
}

/**
 * swap_node_behind - Swap list of integers with the node behind it.
 * @list: list to input
 * @tail: doubly-linked list.
 * @cock: node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **cock)
{
	listint_t *pmt = (*cock)->prev;

	if ((*cock)->next != NULL)
		(*cock)->next->prev = pmt;
	else
		*tail = pmt;
	pmt->next = (*cock)->next;
	(*cock)->prev = pmt->prev;
	if (pmt->prev != NULL)
		pmt->prev->next = *cock;
	else
		*list = *cock;
	(*cock)->next = pmt;
	pmt->prev = *cock;
	*cock = pmt;
}

/**
 * cocktail_sort_list - Sort integers ascending order
 * @list: list to input
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *cock;
	int cocktail = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (cocktail == 0)
	{
		cocktail = 1;
		for (cock = *list; cock != tail; cock = cock->next)
		{
			if (cock->n > cock->next->n)
			{
				swap_node_ahead(list, &tail, &cock);
				print_list((const listint_t *)*list);
				cocktail = 0;
			}
		}
		for (cock = cock->prev; cock != *list; cock = cock->prev)
		{
			if (cock->n < cock->prev->n)
			{
				swap_node_behind(list, &tail, &cock);
				print_list((const listint_t *)*list);
				cocktail = 0;
			}
		}
	}
}
