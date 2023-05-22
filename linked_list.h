
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node {
	void *data;
	struct node *prev, *next;
} node_t;

typedef struct linked_list {
	node_t *head, *tail;
	unsigned int data_size;
	unsigned int size;
} linked_list_t;

linked_list_t *list_create(unsigned int data_size);

node_t *list_get_nth_node(linked_list_t *list, unsigned int n);

void list_add_nth_node(linked_list_t *list, unsigned int n, const void *data);

node_t *list_remove_nth_node(linked_list_t *list, unsigned int n);

unsigned int list_get_size(linked_list_t *list);

void list_free(linked_list_t **pp_list);

#endif	// LINKED_LIST_H_
