#include "deck.h"
#include <stdio.h>
/**
 *_strcmp - 2 str comparism
 *@str1: first str to input
 *@str2: second str to input
 *Return: 0 (success)
 */
int _strcmp(const char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

		if (str1 != str2)
			return (*str1 - *str2);
		return (0);
}

/**
 * get_value - value of a card.
 * @card: ptr to card
 *
 * Return: 0 (when the value is return)
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort spades to diamonds.
 * @deck: card to input
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *idx, *index, *pmt;

	for (idx = (*deck)->next; idx != NULL; idx = pmt)
	{
		pmt = idx->next;
		index = idx->prev;
		while (index != NULL && index->card->kind > idx->card->kind)
		{
			index->next = idx->next;
			if (idx->next != NULL)
				idx->next->prev = index;
			idx->prev = index->prev;
			idx->next = index;
			if (index->prev != NULL)
				index->prev->next = idx;
			else
				*deck = idx;
			index->prev = idx;
			index = idx->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort spades to diamonds from ace to king.
 * @deck: doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *idx, *index, *pmt;

	for (idx = (*deck)->next; idx != NULL; idx = pmt)
	{
		pmt = idx->next;
		index = idx->prev;
		while (index != NULL &&
				index->card->kind == idx->card->kind &&
				get_value(index) > get_value(idx))
		{
			index->next = idx->next;
			if (idx->next != NULL)
				idx->next->prev = index;
			idx->prev = index->prev;
			idx->next = index;
			if (index->prev != NULL)
				index->prev->next = idx;
			else
				*deck = idx;
			index->prev = idx;
			index = idx->prev;
		}
	}
}

/**
 * sort_deck - sort a deck of card you in put
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
