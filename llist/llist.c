#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

void start_list(llist** list) { *list = NULL; }

void init_list_node(llist** list) {
    *list = (llist *) malloc(sizeof(llist));
    (*list)->next = NULL;
}

void list_insert_beg(llist** list, int n)
{
    llist *new = NULL;

    init_list_node(&new);

    new->n = n;
    new->next = *list;

    *list = new;
}

void list_insert_after(llist** list, int n, int v)
{
    llist *new = NULL, *iterator = *list;

    // Create the new list node
    init_list_node(&new);
    new->n = n;

    do {
        if (iterator->next == NULL || iterator->n == v) {
            new->next      = iterator->next;
            iterator->next = new;

            return;
        }

        iterator = iterator->next;
    } while (1);
}

void list_insert_end(llist** list, int n)
{
    llist *aux = *list;
    llist *new = NULL;

    init_list_node(&new);
    new->n = n;

    if (*list == NULL) {
        *list = new;

        return;
    }

    while (aux->next != NULL && (aux = aux->next));
    aux->next = new;

    return;
}

void print_list(llist *list)
{
    llist *aux = list;

    while (aux->next != NULL) {
        printf("%d\n", aux->n);

        aux = aux->next;
    }

    // Prints the last record
    printf("%d\n", aux->n);
}
