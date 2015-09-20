#include <stdlib.h>
#include <stdio.h>
#include "llist.h"
#include "llist_op.h"

llist* list_diff(llist* diff1, llist* diff2)
{
    llist* result = NULL, *iter = NULL, *comp = NULL;
    short exists = 0; // Flag to check if a number of diff1 exists in diff2

    start_list(&result);

    for (iter = diff1; iter != NULL; iter = iter->next) {
        for (comp = diff2, exists = 0; comp != NULL; comp = comp->next) {
            if (iter->n == comp->n) {
                exists = 1;
                break;
            }
        }

        if (!exists) list_insert_ordered(&result, iter->n, DISALLOW_REPEAT);
    }

    return result;
}

llist* list_union(llist* union1, llist* union2)
{
    llist* result = NULL, *iter = NULL;

    start_list(&result);

    // Add the first list elements to result
    for (iter = union1; iter != NULL; iter = iter->next)
        list_insert_ordered(&result, iter->n, DISALLOW_REPEAT);

    // Union the seccond list elements to result
    for (iter = union2; iter != NULL; iter = iter->next)
        list_insert_ordered(&result, iter->n, DISALLOW_REPEAT);

    return result;
}

llist* list_intersect(llist* list1, llist* list2)
{
    llist* result = NULL, *iter = NULL, *comp = NULL;
    short exists = 0; // Flag to check if a number of list1 exists in list2

    start_list(&result);

    for (iter = list1; iter != NULL; iter = iter->next) {
        for (comp = list2, exists = 0; comp != NULL; comp = comp->next) {
            if (iter->n == comp->n) {
                exists = 1;
                break;
            }
        }

        if (exists) list_insert_ordered(&result, iter->n, DISALLOW_REPEAT);
    }

    return result;
}
