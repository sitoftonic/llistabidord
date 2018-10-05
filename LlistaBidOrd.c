//
// Created by Luis Ribó on 04/10/2018.
//

#include "LlistaBidOrd.h"



void LLISTABIDORD_crea(LlistaBidOrd *l) {

    l->cap = (Node*) malloc (sizeof(Node));
    if (l->cap == NULL) {
        printf("Error: Memory reservation failed when created the list\n");
    }
    else {
        //l->cap->element = NULL;
        l->ult = (Node*) malloc (sizeof(Node));
        if (l->ult == NULL) {
            printf("Error: Memory reservation failed when created the list\n");
        }
        else {
            //l->ult->element = NULL;
            l->pdi = l->ult;
            l->cap->seg = l->ult;
            l->ult->ant = l->cap;
            l->cap->ant = NULL;
            l->ult->seg = NULL;
        }
    }
}


int LLISTABIDORD_insereixOrdenat(LlistaBidOrd *l, int element) {
    int trobat = 0, error = 0;
    Node *aux;

    if (!LLISTABIDORD_buida) {
        LLISTABIDORD_vesInici(l);
        while (!trobat) {
            if (l->pdi->seg->element > element) {
                l->pdi = l->pdi->seg;
            }
            else {
                trobat = 1;
            }
        }
        aux = (Node*) malloc (sizeof(Node));
        if (aux == NULL) {
            printf("Error: Memory reservation failed when inserted an element into the list\n");
            error = 1;
        }
        else {
            aux->element = element;
            aux->seg = l->pdi->seg;
            l->pdi->seg = aux;
            aux->ant = l->pdi;
            aux->seg->ant = aux;
        }
    }
    else {
        aux = (Node*) malloc (sizeof(Node));
        if (aux == NULL) {
            printf("Error: Memory reservation failed when inserted an element into the list\n");
            error = 1;
        }
        else {
            aux->element = element;
            aux->seg = l->cap->seg;
            l->cap->seg = aux;
            aux->ant = l->cap;
            aux->seg->ant = aux;
        }
    }
    return error;
}


int LLISTABIDORD_consultaElement(LlistaBidOrd l, int posicio, int *element) {
    int comptador = 1, error = 0;

    if (l.cap == l.ult) {
        printf("Error: Empty list\n");
    }
    else {
        LLISTABIDORD_vesInici(&l);
        while (comptador != posicio && !error) {
            if (l.pdi != l.ult) {
                l.pdi = l.pdi->seg;
                comptador++;
            }
            else {
                error = 1;
            }
        }
        if (!error) {
            if (l.pdi->seg == NULL) {
                error = 1;
            }
            else {
                (*element) = l.pdi->element;
            }
        }
    }
    return error;
}


int LLISTABIDORD_esborra(LlistaBidOrd *l, int posicio) {
    Node *aux;
    int comptador = 0, error = 0;

    if (l->cap == l->ult) {
        printf("Error: Empty list\n");
    }
    else {
        LLISTABIDORD_vesInici(l);
        while (comptador != posicio && !error) {
            if (l->pdi != l->ult) {
                l->pdi = l->pdi->seg;
                comptador++;
            }
            else {
                printf("Error: Reached the last item of the list\n");
                error = 1;
            }
        }
        if (!error) {
            aux = (Node*) malloc (sizeof(Node));
            if (aux == NULL) {
                printf("Error: Memory reservation failed when inserted an element into the list\n");
            }
            else {
                aux = l->pdi;
                aux->ant->seg = aux->seg;
                aux->seg->ant = aux->ant;
                l->pdi = l->pdi->seg;
                free(aux);
            }
        }
    }
    return error;
}


void LLISTABIDORD_mostra(LlistaBidOrd l) {
    int comptador = 1;

    printf("###########################################\n\tPOSICIO\t\tELEMENT\n");
    LLISTABIDORD_vesInici(&l);
    while (l.pdi != l.ult) {
        printf("\t%d\t\t%d\n", comptador, l.pdi->element);
        comptador++;
        l.pdi = l.pdi->seg;
    }
}


void LLISTABIDORD_vesInici(LlistaBidOrd *l) {
    l->pdi = l->cap->seg;
}


void LLISTABIDORD_vesFinal(LlistaBidOrd *l) {
    l->pdi = l->ult->ant;
}


int LLISTABIDORD_buida(LlistaBidOrd l) {
    return l.cap->seg == l.ult;
}


void LLISTABIDORD_destrueix(LlistaBidOrd *l) {
    Node *aux;

    while (l->cap != NULL) {
        aux = l->cap;
        l->cap = l->cap->seg;
        free(aux);
    }
    l->ult = NULL;
    l->pdi = NULL;
}
