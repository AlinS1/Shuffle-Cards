#include "cards.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "utils.h"

void add_full_deck(unsigned int num_cards, linked_list_t *decks)
{
	unsigned int i = 0;
	int r, value;
	char line[BUF_SIZE], *symbol, *number;
	linked_list_t *deck = list_create(sizeof(card_t));
	card_t *my_card;
	FILE *in = fopen("basic_deck_of_cards.txt", "rt");
	if (!in) {
		printf("Can't open file with cards\n");
	}

	while (i < num_cards) {
		// citeste linia din fisierul in care se afla toate cartile dintr-un
		// pachet normal de carti
		fgets(line, BUF_SIZE, in);
		number = strtok(line, DELIM);
		// pentru ca fgets returneaza un string il transform in int
		value = atoi(number);
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
	fclose(in);
}

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
		value = atoi(number);
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

void deck_len(unsigned int index_d, linked_list_t *decks)
{
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;
	printf(DECK_LENGTH, index_d, list_get_size(deck));
}

void del_card(unsigned int index_d, unsigned int index_c, linked_list_t *decks)
{
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}
	// evidntiez nodul respectivului pachet
	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;

	if (index_c >= list_get_size(deck)) {
		printf(CARD_INDEX_OUT_OF_BOUNDS, index_d);
		return;
	}

	// sterg nodul corespunzator cartii
	node_t *node_c = list_remove_nth_node(deck, index_c);
	card_t *my_card = (card_t *)node_c->data;

	// eliberez memoria
	free(my_card);
	free(node_c);
	printf(REMOVED_CARD, index_d);

	// verific daca lista e goala
	if (list_get_size(deck) == 0) {
		node_d = list_remove_nth_node(decks, index_d);
		deck = (linked_list_t *)node_d->data;

		free(deck);
		free(node_d);
	}
}
void reverse_deck(unsigned int index_d, linked_list_t *decks)
{
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;
	node_t *tmp, *tmp_prev, *tmp_next;
	node_t *tmp_head = deck->head, *tmp_tail = deck->tail;
	node_t *it = deck->head;

	// iteram prin lista si schimbam legaturile
	while (it != NULL) {
		tmp = it;
		tmp_prev = tmp->prev;
		tmp_next = tmp->next;
		it = it->next;
		tmp->next = tmp_prev;
		tmp->prev = tmp_next;
	}

	deck->head = tmp_tail;
	deck->tail = tmp_head;

	printf(REVERSED, index_d);
}

void add_cards(unsigned int index_d, unsigned int num_cards,
			   linked_list_t *decks)
{
	unsigned int i = 0;
	int r, value;
	char line[BUF_SIZE], *symbol, *number;

	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	// evidentiez pachetul respectiv
	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;

	while (i < num_cards) {
		fgets(line, BUF_SIZE, stdin);
		// imparte stringul linie in subsiruri spearate de \n
		number = strtok(line, DELIM);
		// transforma stringul in int
		value = atoi(number);
		symbol = strtok(NULL, DELIM);

		r = check_card(value, symbol);
		if (r == 0) {
			printf(INVALID_CARD);
		} else {
			card_t *my_card = (card_t *)malloc(sizeof(card_t));
			DIE(!my_card, "malloc failed");
			my_card->value = value;
			strcpy(my_card->symbol, symbol);

			list_add_nth_node(deck, list_get_size(deck), my_card);
			free(my_card);
			i++;
		}
	}

	printf(ADDED_CARD, index_d);
}
void merge_decks(unsigned int index_d1, unsigned int index_d2,
				 linked_list_t *decks)
{
	if (index_d1 >= list_get_size(decks) || index_d2 >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	// evidentiez cele doua pachete
	node_t *node_d1 = list_get_nth_node(decks, index_d1);
	linked_list_t *deck1 = (linked_list_t *)node_d1->data;

	node_t *node_d2 = list_get_nth_node(decks, index_d2);
	linked_list_t *deck2 = (linked_list_t *)node_d2->data;

	node_t *it1 = deck1->head;
	node_t *it2 = deck2->head;
	// creez noua pachet format
	linked_list_t *deck3 = list_create(sizeof(card_t));

	int i = 0;
	// parcurg pachetele simultan
	while (it1 != NULL || it2 != NULL) {
		// daca a doua lista nu mai are elemente se va adauga numai din prima
		if (it2 == NULL) {
			list_add_nth_node(deck3, i, it1->data);
			it1 = it1->next;
		} else if (it1 == NULL) {
			list_add_nth_node(deck3, i, it2->data);
			it2 = it2->next;
			// daca e pe pozitie para se adauga din prima lista
		} else if (i % 2 == 0) {
			list_add_nth_node(deck3, i, it1->data);
			it1 = it1->next;
		} else if (i % 2 == 1) {
			list_add_nth_node(deck3, i, it2->data);
			it2 = it2->next;
		}
		i++;
	}

	// se sterg cele doua pachete
	node_d1 = list_remove_nth_node(decks, index_d1);
	deck1 = (linked_list_t *)node_d1->data;
	list_free(&deck1);
	free(node_d1);

	node_d2 = list_remove_nth_node(
		decks, index_d1 > index_d2 ? index_d2 : index_d2 - 1);
	deck2 = (linked_list_t *)node_d2->data;
	list_free(&deck2);
	free(node_d2);

	// se adauga noul pachet la final
	list_add_nth_node(decks, list_get_size(decks), deck3);
	free(deck3);

	printf(MERGED, index_d1, index_d2);
}

void split_deck(unsigned int index_d, unsigned int index_split,
				linked_list_t *decks)
{
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;

	// verific indexul
	if (index_split >= list_get_size(deck)) {
		printf(CARD_INDEX_OUT_OF_BOUNDS, index_d);
		return;
	}

	// daca e 0 se pastreaza pachetul cu carti
	if (index_split == 0) {
		printf(SPLIT, index_d, index_split);
		return;
	}

	node_t *it = deck->head;
	linked_list_t *deck1 = list_create(sizeof(card_t));
	linked_list_t *deck2 = list_create(sizeof(card_t));
	unsigned int i = 0;

	// mergem prin lista cu it pornind de la head
	while (it != NULL) {
		// daca e mai mic decat indexul se aflta in prima parte deci se ia din
		// primul pachet
		if (i < index_split) {
			list_add_nth_node(deck1, list_get_size(deck1), it->data);
		} else {
			list_add_nth_node(deck2, list_get_size(deck2), it->data);
		}

		it = it->next;
		i++;
	}

	node_d = list_remove_nth_node(decks, index_d);
	deck = (linked_list_t *)node_d->data;
	list_free(&deck);
	free(node_d);

	// se adauga pachetele noi, primul pe pozitia celui vechi
	// iar al doilea pe pozitia urmatoare
	list_add_nth_node(decks, index_d, deck1);
	list_add_nth_node(decks, index_d + 1, deck2);
	free(deck1);
	free(deck2);

	printf(SPLIT, index_d, index_split);
}

void deck_number(linked_list_t *decks)
{
	printf(DECKS_NUM, list_get_size(decks));
}

void shuffle_deck(unsigned int index_d, linked_list_t *decks)
{
	if (index_d >= list_get_size(decks)) {
		printf(DECK_INDEX_OUT_OF_BOUNDS);
		return;
	}

	node_t *node_d = list_get_nth_node(decks, index_d);
	linked_list_t *deck = (linked_list_t *)node_d->data;
	if (list_get_size(deck) <= 1) {
		printf(SHUFFLED, index_d);
		return;
	}

	linked_list_t *new_deck = list_create(sizeof(card_t));

	node_t *current_card_node = deck->head;
	while (current_card_node) {
		card_t *current_card = (card_t *)current_card_node->data;

		printf("s:%s|v:%d ", current_card->symbol, current_card->value);

		unsigned int idx = rand() % (new_deck->size + 1);

		printf("idx:%d | ", idx);

		list_add_nth_node(new_deck, idx, current_card);
		current_card_node = current_card_node->next;
	}

	list_free(&deck);
	node_d->data = new_deck;

	printf(SHUFFLED, index_d);
}

// parcurg toata lista si eliberez memoria folosita
// de fiecare nod si apoi memoria folosita de lista
void free_decks(linked_list_t *decks)
{
	while (list_get_size(decks) > 0) {
		node_t *node_d = list_remove_nth_node(decks, list_get_size(decks) - 1);
		linked_list_t *deck = (linked_list_t *)node_d->data;

		list_free(&deck);
		free(node_d);
	}

	list_free(&decks);
}