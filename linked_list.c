
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 64

linked_list_t *list_create(unsigned int data_size)
{
	linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
	list->head = NULL;
	list->tail = NULL;
	list->data_size = data_size;
	list->size = 0;
	return list;
}

node_t *list_get_nth_node(linked_list_t *list, unsigned int n)
{
	node_t *tmp;
	unsigned int i;

	if (!list || !list->size)
		return NULL;

	tmp = list->head;

	n %= list->size;

	for (i = 0; i < n; i++)
		tmp = tmp->next;

	return tmp;
}

void list_add_nth_node(linked_list_t *list, unsigned int n, const void *data)
{
	node_t *it, *new_next, *new_prev;
	unsigned int i;
	if (list == NULL)
		return;

	if (n > list->size)
		n = list->size;

	node_t *tmp = (node_t *)malloc(sizeof(node_t));
	tmp->data = malloc(list->data_size);
	memcpy(tmp->data, data, list->data_size);
	tmp->next = NULL;
	tmp->prev = NULL;

	it = list->head;
	if (list->size == 0) {
		list->head = tmp;
		list->tail = tmp;
	} else if (n == 0) {
		new_next = list->head;
		tmp->next = new_next;
		new_next->prev = tmp;
		list->head = tmp;
	} else if (n == list->size) {
		it = list->tail;
		it->next = tmp;
		tmp->prev = it;
		list->tail = tmp;
	} else {
		it = list->head;
		for (i = 0; i < n - 1; i++)
			it = it->next;

		new_next = it->next;
		new_prev = it;
		tmp->next = new_next;
		tmp->prev = new_prev;
		new_next->prev = tmp;
		new_prev->next = tmp;
	}

	list->size++;
}

node_t *list_remove_nth_node(linked_list_t *list, unsigned int n)
{
	node_t *tmp, *new_next, *new_prev;
	unsigned int i;

	if (list == NULL || list->size == 0)
		return NULL;

	if (n >= list->size - 1)
		n = list->size - 1;

	if (list->size == 1) {
		tmp = list->head;
		list->head = NULL;
		list->tail = NULL;
	} else if (n == 0) {
		tmp = list->head;
		new_next = list->head->next;
		new_next->prev = NULL;
		list->head = new_next;
	} else if (n == list->size - 1) {
		tmp = list->tail;
		new_prev = list->tail->prev;
		new_prev->next = NULL;
		list->tail = new_prev;
	} else {
		tmp = list->head;
		for (i = 0; i < n; i++)
			tmp = tmp->next;

		new_next = tmp->next;
		new_prev = tmp->prev;
		new_prev->next = new_next;
		new_next->prev = new_prev;
	}

	if (!list->size)
		list->head = NULL;

	list->size--;
	return tmp;
}

unsigned int list_get_size(linked_list_t *list)
{
	return list->size;
}

void list_free(linked_list_t **pp_list)
{
	node_t *it, *tmp;
	it = (*pp_list)->head;

	while (it != NULL) {
		tmp = it;
		it = it->next;
		free(tmp->data);
		free(tmp);
	}

	free(*pp_list);
}
