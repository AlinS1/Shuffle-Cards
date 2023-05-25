#ifndef UTILS_H_
#define UTILS_H_

#include <errno.h>

/* macro pentru alocare defensiva */
#define DIE(assertion, call_description)                       \
	do {                                                       \
		if (assertion) {                                       \
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__); \
			perror(call_description);                          \
			exit(errno);                                       \
		}                                                      \
	} while (0)

// pentru simboluri
#define SPADE "SPADE"
#define CLUB "CLUB"
#define DIAMOND "DIAMOND"
#define HEART "HEART"

#define BUF_SIZE 256
#define SYM_SIZE 10

#define DELIM " \n"

// pentru comenzi
#define ADD_D "ADD_DECK"
#define DEL_D "DEL_DECK"
#define DEL_C "DEL_CARD"
#define ADD_C "ADD_CARDS"
#define DECK_NUMBER "DECK_NUMBER"
#define DECK_LEN "DECK_LEN"
#define SHUFFLE "SHUFFLE_DECK"
#define SHOW_D "SHOW_DECK"
#define SHOW_ALL "SHOW_ALL"
#define REVERSE_D "REVERSE_DECK"
#define MERGE_D "MERGE_DECKS"
#define SPLIT_D "SPLIT_DECK"
#define EXIT "EXIT"

// pentru erori
#define INVALID_CARD "The provided card is not a valid one.\n"
#define ADDED_DECK "The deck was successfully created with %u cards.\n"
#define DECK_INDEX_OUT_OF_BOUNDS "The provided index is out of bounds " \
                                 "for the deck list.\n"
#define REMOVED_DECK "The deck %u was successfully deleted.\n"
#define CARD_INDEX_OUT_OF_BOUNDS "The provided index is out of bounds " \
                                 "for deck %u.\n"
#define INVALID_COMMAND "Invalid command. Please try again.\n"
#define REMOVED_CARD "The card was successfully deleted from deck %u.\n"
#define ADDED_CARD "The cards were successfully added to deck %u.\n"
#define DECKS_NUM "The number of decks is %u.\n"
#define DECK_LENGTH "The length of deck %u is %u.\n"
#define SHUFFLED "The deck %u was successfully shuffled.\n"
#define REVERSED "The deck %u was successfully reversed.\n"
#define MERGED "The deck %u and the deck %u were successfully merged.\n"
#define SPLIT "The deck %u was successfully split by index %u.\n"

int check_card(int value, char symbol[SYM_SIZE]);

int string_to_int(char *str);

#endif  // UTILS_H_
