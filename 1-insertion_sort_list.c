#include "sort.h"
/**
 * insertion_sort_list - sort integers in ascending orders
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *swap_node - swap a node
 *@node: node to swap
 *@list: list to node
 *Return: return a pointer to a swap node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *tmp = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = back;
	tmp->next = back;
	tmp->prev = back->prev;
	back->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = tmp;
	else
		*list = tmp;
	return (tmp);
}
