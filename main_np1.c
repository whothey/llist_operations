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
            list_insert_ordered(&lists[i], aux);

            if (getchar() == '\n') break;
        }

        print_list(lists[i]);
    }

    return 0;
}
