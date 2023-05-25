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
		int nr_command = command_string_to_number(command);

		switch (nr_command) {
		case 1:	 // ADD_DECK
			number = strtok(NULL, DELIM);
			if (!number)
				add_full_deck(56, decks);
			else {
				num_cards = atoi(number);
				// daca e null se apeleaza functia
				// daca nu se afisaza eroare
				if (strtok(NULL, DELIM) == NULL) {
					add_deck(num_cards, decks);
				} else {
					printf(INVALID_COMMAND);
				}
			}
			break;
		case 2:	 // DELETE_DECK
			number = strtok(NULL, DELIM);
			index_d = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				del_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 3:	 // DELETE_CARD
			number = strtok(NULL, DELIM);
			index_d = atoi(number);
			number = strtok(NULL, DELIM);
			index_c = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				del_card(index_d, index_c, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 4:	 // ADD_CARD
			number = strtok(NULL, DELIM);
			index_d = atoi(number);
			number = strtok(NULL, DELIM);
			num_cards = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				add_cards(index_d, num_cards, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 5:	 // DECK_NUMBER
			if (strtok(NULL, DELIM) == NULL) {
				deck_number(decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 6:	 // DECK_LENGTH
			number = strtok(NULL, DELIM);
			index_d = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				deck_len(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 7:	 // SHUFFLE_DECK
			number = strtok(NULL, DELIM);
			index_d = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				shuffle_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 8:	 // SHOW_DECK
			number = strtok(NULL, DELIM);
			index_d = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				show_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 9:	 // SHOW_ALL
			if (strtok(NULL, DELIM) == NULL) {
				show_all(decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 10:  // REVERSE_DECK
			number = strtok(NULL, DELIM);
			index_d = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				reverse_deck(index_d, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 11:  // MERGE_DECK
			number = strtok(NULL, DELIM);
			index_d1 = atoi(number);
			number = strtok(NULL, DELIM);
			index_d2 = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				merge_decks(index_d1, index_d2, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 12:  // SPLIT_DECK
			number = strtok(NULL, DELIM);
			index_d = atoi(number);
			number = strtok(NULL, DELIM);
			index_split = atoi(number);

			if (strtok(NULL, DELIM) == NULL) {
				split_deck(index_d, index_split, decks);
			} else {
				printf(INVALID_COMMAND);
			}
			break;
		case 13:  // EXIT
			exit = 1;
			break;
		default:
			printf(INVALID_COMMAND);
		}

	}

	free_decks(decks);
	return 0;
}
