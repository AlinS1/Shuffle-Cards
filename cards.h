#ifndef CARDS_H_
#define CARDS_H_

#include "linked_list.h"

#define SYM_SIZE 10

// strcutura cu informatiile unei carti
typedef struct card {
	int value;
	char symbol[SYM_SIZE];
} card_t;

void add_full_deck(unsigned int num_cards, linked_list_t *decks);

void add_deck(unsigned int num_cards, linked_list_t *decks);

void del_deck(unsigned int index_d, linked_list_t *decks);

void del_card(unsigned int index_d, unsigned int index_c, linked_list_t *decks);

void add_cards(unsigned int index_d, unsigned int num_cards,
			   linked_list_t *decks);

void deck_len(unsigned int index_d, linked_list_t *decks);

void merge_decks(unsigned int index_d1, unsigned int index_d2,
				 linked_list_t *decks);

void split_deck(unsigned int index_d, unsigned int index_split,
				linked_list_t *decks);

void reverse_deck(unsigned int index_d, linked_list_t *decks);

void show_deck(unsigned int index_d, linked_list_t *decks);

void show_all(linked_list_t *decks);

void free_decks(linked_list_t *decks);

void deck_number(linked_list_t *decks);

void shuffle_deck(unsigned int index_d, linked_list_t *decks);

#endif	// CARDS_H_