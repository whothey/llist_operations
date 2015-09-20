#include <stdio.h>
#include <stdlib.h>
#include "llist/llist.h"

int main()
{
    int unsigned qtd, read_terms;
    int i, aux;
    llist **lists = NULL;

    printf("Informe a quantidade de conjuntos para alocação: ");
    scanf("%u", &qtd);

    lists = (llist **) malloc(sizeof(llist *) * qtd);
    for (i = 0; i < qtd; i++) start_list(&lists[i]);

    printf("**Separe os números por espaços!**\n");

    for (i = 0; i < qtd; i++) {
        printf("Informe o %dº conjunto: ", i + 1);

        while ((read_terms = scanf(" %d", &aux)) > 0) {
            list_insert_ordered(&lists[i], aux, DISALLOW_REPEAT);

            if (getchar() == '\n') break;
        }

        print_list_as_numeric_set(lists[i]);
    }

    // Free alloc'd bytes
    for (i = 0; i < qtd; i++) list_free_all(&lists[i]);
    free(lists);

    return 0;
}
