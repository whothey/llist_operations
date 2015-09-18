#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

void init_list(llist* list) { list = list->next = NULL; }

void list_insert_beg(llist** list, int n)
{
    llist *new = (llist *) malloc(sizeof(llist));

    if (new == NULL) return NULL; // Can't malloc!

    init_list(new);
    new->n = n;
    new->next = (*list);

    list = &new;
}

void list_insert_after(llist** list, int n, int v)
{
    llist *new = (llist *) malloc(sizeof(llist)), *iterator;

    // Can't malloc!
    if (new == NULL) return NULL;

    init_list(new);

    // Create the new list node
    new->n = n;
    iterator = *list;

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
    llist *new = (llist *) malloc(sizeof(llist));

    init_list(new);
    new->n = n;

    if (list == NULL) {
        *list = new;

        return;
    }

    while (aux->next != NULL && (aux = aux->next));

    aux->next = new;

    return;
}
