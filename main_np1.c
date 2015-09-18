#include <stdio.h>
#include <stdlib.h>
#include "llist/llist.h"

int main()
{
    int unsigned qtd, read_terms;
    int i, aux;
    llist *list;

    printf("Informe a quantidade de conjuntos para alocação: ");
    scanf("%u", &qtd);

    list = (llist *) malloc(sizeof(llist) * qtd);
    for (i = 0; i < qtd; i++) init_list(&list[i]);

    printf("**Separe os números por espaços!**\n");

    for (i = 0; i < qtd; i++) {
        printf("Informe o %dº conjunto: ", i + 1);

        while ((read_terms = scanf("%d", &aux)) > 0) {
            list_insert_end(&list + i, aux);

            if (getchar() == '\n') break;
        }

    }

    return 0;
}
