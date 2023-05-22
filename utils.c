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

// transforma un string intr un int
int string_to_int(char *str) {
	int n = 0, i = 0;

	while (str[i] != 0) {
		n *= 10;
		n += str[i] - '0';
		i++;
	}

	return n;
}
