#include "lists.h"
/**
 * list_len - returns the number of elements of the linked list
 * @h: the node
 * Return: the number of elements
 */

size_t list_len(const list_t *h)
{
	size_t l = 0;

	while (h)
	{
		h = h->next;
		l++;
	}
	return (l);
}

