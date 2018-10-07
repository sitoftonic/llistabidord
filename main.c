//
// Created by Luis Ribó on 05/10/2018.
//

#include "LlistaBidOrd.h"

#define LIST_SIZE 40

int main() {
    LlistaBidOrd l;
    int i, num, error, size;
    char option[3];

    do {
        printf("\nInitializing list...\n");
        l = LLISTABIDORD_crea();
        printf("List succesfully created OK\n");
        printf("Starting test...\n");
        for (i = 0; i < LIST_SIZE; i++) {
            num = rand() % 100;
            error = LLISTABIDORD_insereixOrdenat(&l, num);
            if (!error) {
                printf("Added %d to the list\n", num);
            }
        }
        printf("Descendent mode\n");
        LLISTABIDORD_vesInici(&l);
        while (!LLISTABIDORD_fi(l)) {
            printf("%d\t", LLISTABIDORD_consulta(l));
            LLISTABIDORD_avanca(&l);
        }
        printf("\nAscendent mode\n");
        LLISTABIDORD_vesFinal(&l);
        while (!LLISTABIDORD_inici(l)) {
            printf("%d\t", LLISTABIDORD_consulta(l));
            LLISTABIDORD_retrocedeix(&l);
        }
        size = LLISTABIDORD_getSize(l);
        printf("\nList size: %d", size);
        printf("\nList succesfully tested\n");
        printf("Destroying List...\n");
        LLISTABIDORD_destrueix(&l);
        printf("Press y to repeat or n to exit...");
        scanf("%s", option);
    } while (option[0] == 'y');
    printf("\nExecution is over\n");

    return 0;
}
