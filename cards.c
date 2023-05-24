#include "cards.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "utils.h"

void add_deck(unsigned int num_cards, linked_list_t *decks)
{
	unsigned int i = 0;
	int r, value;
	char line[BUF_SIZE], *symbol, *number;
	linked_list_t *deck = list_create(sizeof(card_t));
	card_t *my_card;

	while (i < num_cards) {
		// citeste linia de la stdin
		fgets(line, BUF_SIZE, stdin);
		number = strtok(line, DELIM);
		// pentru ca fgets returneaza un string il transform in int
		value = string_to_int(number);
		symbol = strtok(NULL, DELIM);

		r = check_card(value, symbol);
		// daca cartea nu e buna -> eroare
		if (r == 0) {
			printf(INVALID_CARD);
		} else {
			my_card = (card_t *)calloc(1, sizeof(card_t));
			my_card->value = value;
			strcpy(my_card->symbol, symbol);

			list_add_nth_node(deck, list_get_size(deck), my_card);
			free(my_card);
			i++;
		}
	}

	list_add_nth_node(decks, list_get_size(decks), deck);
	free(deck);
	printf(ADDED_DECK, num_cards);
}

void show_deck(unsigned int index_d, linked_list_t *decks)
{
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;
	printf("Deck %d:\n", index_d);

	node_t *node_c;
	for (node_c = deck->head; node_c != NULL; node_c = node_c->next) {
		card_t *my_card = (card_t *)node_c->data;
		printf("\t%d %s\n", my_card->value, my_card->symbol);
	}
}

void show_all(linked_list_t *decks)
{
	unsigned int i;
	for (i = 0; i < list_get_size(decks); i++) {
		show_deck(i, decks);
	}
}

void del_deck(unsigned int index_d, linked_list_t *decks)
{
	// verific indexul
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}
	// sterg nodul la care se afla deck
	node_t *node_d = list_remove_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;
	// eliberez memoria
	list_free(&deck);
	free(node_d);
	printf(REMOVED_DECK, index_d);
}