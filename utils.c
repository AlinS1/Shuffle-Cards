#include <string.h>
#include "utils.h"

// verifica validitatea unei carti
int check_card(int value, char symbol[SYM_SIZE]) {
	if (value < 1 || value > 14)
		return 0;

	if (strcmp(symbol, HEART) != 0 && strcmp(symbol, DIAMOND) != 0 &&
		strcmp(symbol, CLUB) != 0 && strcmp(symbol, SPADE) != 0)
		return 0;

	return 1;
}

// Fiecarei comenzi i se atribuie un numar pentru a putea folosi switch case
int command_string_to_number(char *command)
{
	if (strcmp(command, ADD_D) == 0)
		return 1;
	if (strcmp(command, DEL_D) == 0)
		return 2;
	if (strcmp(command, DEL_C) == 0)
		return 3;
	if (strcmp(command, ADD_C) == 0)
		return 4;
	if (strcmp(command, DECK_NUMBER) == 0)
		return 5;
	if (strcmp(command, DECK_LEN) == 0)
		return 6;
	if (strcmp(command, SHUFFLE) == 0)
		return 7;
	if (strcmp(command, SHOW_D) == 0)
		return 8;
	if (strcmp(command, SHOW_ALL) == 0)
		return 9;
	if (strcmp(command, REVERSE_D) == 0)
		return 10;
	if (strcmp(command, MERGE_D) == 0)
		return 11;
	if (strcmp(command, SPLIT_D) == 0)
		return 12;
	if (strcmp(command, EXIT) == 0)
		return 13;

	return 0;
}