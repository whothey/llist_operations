#include <stdio.h>
#include <stdlib.h>
#include "llist/llist.h"
#include "llist/llist_op.h"

#define CLEAR_NEWLINE() while(getchar() != '\n');

int say_goodbye()
{
    printf("Done for now. Bye!\n");

    return 0;
}

int main()
{
    int unsigned qtd;
    int i, term;
    char c;
    llist **lists = NULL; // Main lists pointers
    // Result pointers
    llist *result_diff = NULL, *result_inters, *result_union = NULL;
    llist *aux = NULL; // Auxiliar pointer

    printf("Informe a quantidade de conjuntos para alocação: ");
    scanf("%u", &qtd);
    CLEAR_NEWLINE();

    if (qtd == 0) return say_goodbye();

    lists = (llist **) malloc(sizeof(llist *) * qtd);
    for (i = 0; i < qtd; i++) start_list(&lists[i]);

    printf("**Separe os números por espaços!**\n");

    for (i = 0; i < qtd; i++) {
        printf("Informe o %dº conjunto: ", i + 1);

        while ((c = getchar()) != '\n') {
            ungetc(c, stdin);
            scanf(" %d", &term);
            list_insert_ordered(&lists[i], term, DISALLOW_REPEAT);

            if (getchar() == '\n') break;
        }

        printf("O conjunto inserido foi: ");
        print_list_as_numeric_set(lists[i]);

        if (i == 0) {
            result_diff   = list_copy(lists[i]);
            result_inters = list_copy(lists[i]);
            result_union  = list_copy(lists[i]);
        } else {
            aux = list_diff(result_diff, lists[i]);
            list_free_all(&result_diff);
            result_diff = aux;
            aux = NULL;

            aux = list_intersect(result_inters, lists[i]);
            list_free_all(&result_inters);
            result_inters = aux;
            aux = NULL;

            aux = list_union(result_union, lists[i]);
            list_free_all(&result_union);
            result_union = aux;
            aux = NULL;
        }
    }

    printf("O conjunto diferença é: ");
    print_list_as_numeric_set(result_diff);

    printf("O conjunto união é: ");
    print_list_as_numeric_set(result_union);

    printf("O conjunto intersecção é: ");
    print_list_as_numeric_set(result_inters);

    // Free alloc'd bytes
    for (i = 0; i < qtd; i++) list_free_all(&lists[i]);
    free(lists);
    list_free_all(&result_diff);
    list_free_all(&result_inters);
    list_free_all(&result_union);

    return say_goodbye();
}
