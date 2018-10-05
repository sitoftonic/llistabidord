#include "LlistaBidOrd.h"

void createNewList(LlistaBidOrd l) {
    char opcion[20];
    int error;

    if (l.cap == NULL && l.ult == NULL) {
        LLISTABIDORD_crea(&l);
        printf("A new list has been created.\n");
    }
    else {
        if (!LLISTABIDORD_buida(l)) {
            do {
                error = 0;
                printf("Do you want to delete your previous list? Type Y or N: ");
                scanf("%s", opcion);
                if (strlen(opcion) > 1 || (opcion[0] != 'y' && opcion[0] != 'n' && opcion[0] != 'Y' && opcion[0] != 'N')) {
                    printf("Error: Wrong option\n");
                    error = 1;
                }
                else {
                    if (opcion[0] == 'y' || opcion[0] == 'Y') {
                        LLISTABIDORD_destrueix(&l);
                        LLISTABIDORD_crea(&l);
                        printf("Previous list has been deleted.\nA new list has been created.\n");
                    }
                    else {
                        printf("Previous list has not been modified.\n");
                    }
                }
            } while (error);
        }
        else {
            printf("A new list has been created.\n");
        }
    }
}


void addElement(LlistaBidOrd *l) {
    char elemento_char[16];
    int elemento, error, i;

    if (l->ult == NULL && l->cap == NULL) {
        printf("Error: You must create a list first.\n");
    }
    else {
        do {
            error = 0;
            printf("Which integer do you want to add to the list? ");
            scanf("%s", elemento_char);
            for (i = 0; i < strlen(elemento_char); i++) {
                if (elemento_char[i] < '0' || elemento_char[i] > '9') {
                    error = 1;
                    printf("Error: Wrong input.\n");
                }
            }
        } while (error);
        elemento = atoi(elemento_char);
        error = LLISTABIDORD_insereixOrdenat(l, elemento);
        if (!error) {
            printf("The integer %d has been added to the list.\n", elemento);
        }
    }
}


void showList(LlistaBidOrd l) {
    if (l.ult == NULL && l.cap == NULL) {
        printf("Error: You must create a list first.\n");
    }
    else {
        if (!LLISTABIDORD_buida(l)) {
            LLISTABIDORD_mostra(l);
        }
        else {
            printf("The list is empty.\n");
        }
    }
}

void showElement(LlistaBidOrd l) {
    char posicion_char[10];
    int posicion, element = 0, error, i;

    if (l.ult == NULL && l.cap == NULL) {
        printf("Error: You must create a list first.\n");
    }
    else {
        if (!LLISTABIDORD_buida(l)) {
            do {
                error = 0;
                printf("Which position do you want to know? ");
                scanf("%s", posicion_char);
                for (i = 0; i < strlen(posicion_char); i++) {
                    if (posicion_char[i] < '1' || posicion_char[i] > '9') {
                        error = 1;
                        printf("Error: Wrong input.\n");
                    }
                }
            } while (error);
            posicion = atoi(posicion_char);
            error = LLISTABIDORD_consultaElement(l, posicion, &element);
            if (!error) {
                printf("The value of this position is: %d\n", element);
            }
            else {
                printf("Error: Reached the last item of the list\n");
            }
        }
        else {
            printf("The list is empty.\n");
        }
    }
}


void deleteElement(LlistaBidOrd *l) {
    char *posicion_char;
    int posicion, element = 0, error, i;

    if (l->ult == NULL && l->cap == NULL) {
        printf("Error: You must create a list first.\n");
    }
    else {
        if (!LLISTABIDORD_buida(*l)) {
            do {
                error = 0;
                posicion_char = (char*) malloc (sizeof(char) * 100);
                printf("Which position do you want to delete? ");
                scanf("%s\n", posicion_char);
                for (i = 0; i < strlen(posicion_char); i++) {
                    if (posicion_char[i] < '0' || posicion_char[i] > '9') {
                        error = 1;
                        printf("Error: Wrong input.\n");
                    }
                }
            } while (error);
            posicion = atoi(posicion_char);
            error = LLISTABIDORD_esborra(l, posicion);
            if (!error) {
                printf("The element from the %d position has been removed.\n", posicion);
            }
        }
        else {
            printf("The list is empty.\n");
        }
    }
}


void deleteList(LlistaBidOrd *l) {
    char *opcion;
    int error;

    if (LLISTABIDORD_buida(*l)) {
        printf("The list has been removed.\n");
    }
    else {
        do {
            error = 0;
            printf("The list will be removed. Are you sure? Type 'y' or 'n'\n");
            opcion = (char*) malloc (sizeof(char) * 3);
            if (opcion == NULL) {
                error = 1;
                printf("Error: Memory allocation denied.\n");
            }
            else {
                scanf("%s\n", opcion);
                if (strlen(opcion) > 1 || (opcion[0] != 'y' && opcion[0] != 'n' && opcion[0] != 'Y' && opcion[0] != 'N')) {
                    printf("Error: Wrong option\n");
                    error = 1;
                }
                else {
                    if (opcion[0] == 'y' || opcion[0] == 'Y') {
                        LLISTABIDORD_destrueix(l);
                        printf("The list has been deleted.\n");
                    }
                    else {
                        printf("The list has not been modified.\n");
                    }
                }
            }
        } while (error);
    }
}



void main() {
    char opcio_menu[5];
    int error;
    LlistaBidOrd l;

    LLISTABIDORD_crea(&l);
    printf("Welcome to the List v1.0\n");
    do {
        do {
            error = 0;
            printf("What do you want to do?\n");
            printf("\n\t1. Create a new list\n\t2. Add an element\n\t3. Show actual list\n\t4. Show an element from the list\n\t5. Delete an element from the list\n\t6. Delete the list\n\t7. Exit\n\n");
            printf("Option: ");
            scanf("%s", opcio_menu);
            if (strlen(opcio_menu) > 1 || (opcio_menu[0] < '1' || opcio_menu[0] > '7')) {
                printf("Error: Wrong option.\n");
                error = 1;
            }
        } while (error);
        switch (opcio_menu[0]) {
            case '1':
                createNewList(l);
                break;

            case '2':
                addElement(&l);
                break;

            case '3':
                showList(l);
                break;

            case '4':
                showElement(l);
                break;

            case '5':
                deleteElement(&l);
                break;

            case '6':
                deleteList(&l);
                break;
        }
    } while (opcio_menu[0] != '7');
    printf("Thank you for using List v1.0!\nBye.\n\n");
}