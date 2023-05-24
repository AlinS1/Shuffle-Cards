#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cards.h"
#include "linked_list.h"
#include "utils.h"

int main(void)
{
	char *command, *number, line[BUF_SIZE];
	unsigned int num_cards, index_d, index_c, index_d1, index_d2, index_split;
	int exit = 0;

	linked_list_t *decks = list_create(sizeof(linked_list_t));

	while (!exit) {
		// seteaza linia la 0
		memset(line, 0, BUF_SIZE);
		// citeste linia de la stdin
		fgets(line, BUF_SIZE, stdin);

		// imparte linia in subsiruri separate de \n si slaveaza rez intr o var
		command = strtok(line, DELIM);
		// pentru comanda ADD_D
		if (strcmp(command, ADD_D) == 0) {
			number = strtok(NULL, DELIM);
			num_cards = string_to_int(number);
			// daca e null se apeleaza functia
			// daca nu se afisaza eroare
			if (strtok(NULL, DELIM) == NULL) {
				add_deck(num_cards, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, DEL_D) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				del_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, DEL_C) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);
			number = strtok(NULL, DELIM);
			index_c = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				del_card(index_d, index_c, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, ADD_C) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);
			number = strtok(NULL, DELIM);
			num_cards = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				add_cards(index_d, num_cards, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, DECK_NUMBER) == 0) {
			if (strtok(NULL, DELIM) == NULL) {
				deck_number(decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, DECK_LEN) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				deck_len(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, SHUFFLE) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				shuffle_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		}

		else if (strcmp(command, SHOW_D) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				show_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, SHOW_ALL) == 0) {
			if (strtok(NULL, DELIM) == NULL) {
				show_all(decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, REVERSE_D) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				reverse_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, MERGE_D) == 0) {
			number = strtok(NULL, DELIM);
			index_d1 = string_to_int(number);
			number = strtok(NULL, DELIM);
			index_d2 = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				merge_decks(index_d1, index_d2, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, SPLIT_D) == 0) {
			number = strtok(NULL, DELIM);
			index_d = string_to_int(number);
			number = strtok(NULL, DELIM);
			index_split = string_to_int(number);

			if (strtok(NULL, DELIM) == NULL) {
				split_deck(index_d, index_split, decks);
			} else {
				printf(INVALID_COMMAND);
			}
		} else if (strcmp(command, EXIT) == 0) {
			exit = 1;
		}

		else {
			printf(INVALID_COMMAND);
		}
	}

	// free_decks(decks);
	return 0;
}
