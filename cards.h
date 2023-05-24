#ifndef CARDS_H_
#define CARDS_H_

#include "linked_list.h"

#define SYM_SIZE 10

// strcutura cu informatiile unei carti
typedef struct card {
	int value;
	char symbol[SYM_SIZE];
} card_t;

void add_deck(unsigned int num_cards, linked_list_t *decks);

void show_deck(unsigned int index_d, linked_list_t *decks);

void show_all(linked_list_t *decks);

void del_deck(unsigned int index_d, linked_list_t *decks);

#endif	// CARDS_H_