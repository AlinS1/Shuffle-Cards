CC = gcc
CFLAGS = -g -Wall -Wextra

build: main_prog

main.o: main.c
	$(CC) $(CFLAGS) -c $<	

cards.o: cards.c
	$(CC) $(CFLAGS) -c $<

linked_list.o: linked_list.c
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c
	$(CC) $(CFLAGS) -c $<	

main_prog: main.o cards.o linked_list.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean

clean:
	rm *.o main_prog
