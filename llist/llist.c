#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

void start_list(llist** list) { *list = NULL; }

void init_list_node(llist** list) {
    *list = (llist *) malloc(sizeof(llist));
    (*list)->next = NULL;
}

llist* list_copy(llist *list)
{
    llist *copy, *iterator;

    start_list(&copy);

    for (iterator = list; iterator != NULL; iterator = iterator->next)
        list_insert_end(&copy, iterator->n);

    return copy;
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

void list_insert_ordered(llist** list, int n, short allow_repeat)
{
    llist *aux = *list;
    llist *new = NULL;
    short repeated = 0;

    // Create the element
    init_list_node(&new);
    new->n = n;

    if (*list == NULL) {
        *list = new;

        return;
    }

    // If the first number is higher than the one to be inserted
    // swap the list start
    if (aux->n > n) {
        new->next = aux;
        *list = new;

        return;
    }

    // While exists a next record and
    // its value is higher than the current value to be inserted
    while (aux != NULL) {
        // Checks if the number is repeated
        if (!allow_repeat && aux->n == n) { repeated = 1; break; }
        else if (aux->next != NULL && aux->next->n > n) {
            // Swap values if next number is higher than the current
            new->next = aux->next;
            aux->next = new;

            return;
        }

        // Mantain the aux pointer still valid to next operations
        if (aux->next == NULL) break;
        else aux = aux->next;
    }

    // Frees the created element and don't add it to the list
    if (repeated) {
        list_free_element(new);
        return;
    }

    // Appends to the list
    new->next = aux->next;
    aux->next = new;

    return;
}

void list_free_element(llist *elem) { free(elem); }

void list_free_all(llist** list)
{
    llist *aux = *list;

    while (*list != NULL) {
        aux   = *list;
        *list = (*list)->next;

        list_free_element(aux);
    }

    *list = NULL;
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

void print_list_as_numeric_set(llist *list)
{
    llist *aux = list;

    if (aux == NULL) {
        printf("{}\n");

        return;
    }

    printf("{ ");
    while (aux->next != NULL) {
        printf("%d, ", aux->n);

        aux = aux->next;
    }

    // Prints the last record
    printf("%d }\n", aux->n);
}
