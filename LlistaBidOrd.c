//
// Created by Luis Ribó on 04/10/2018.
//

#include "LlistaBidOrd.h"


/* This method creates a LlistaBidOrd element and creates 3 pointers to 2 Nodes,
   linking them together with seg and ant pointers from each Node */
LlistaBidOrd LLISTABIDORD_crea() {
    LlistaBidOrd l;

    l.cap = (Node*) malloc (sizeof(Node));
    if (l.cap == NULL) {
        printf("Error: Memory reservation failed when created the list\n");
    }
    else {
        l.ult = (Node*) malloc (sizeof(Node));
        if (l.ult == NULL) {
            free(l.cap);
            printf("Error: Memory reservation failed when created the list\n");
        }
        else {
            l.pdi = l.cap;
            l.cap->seg = l.ult;
            l.cap->ant = NULL;
            l.ult->ant = l.cap;
            l.ult->seg = NULL;
        }
    }
    return l;
}


int LLISTABIDORD_insereixOrdenat(LlistaBidOrd *l, int element) {
    int trobat = 0, error = 0;
    Node *aux;

    l->pdi = l->cap->seg;
    while (!trobat && l->pdi->seg != NULL) {
        if (!LLISTABIDORD_buida(*l)) {
            if (l->pdi->num > element) {
                l->pdi = l->pdi->seg;
            }
            else {
                trobat = 1;
            }
        }
        else {
            trobat = 1;
        }
    }
    aux = (Node*) malloc (sizeof(Node));
    if (aux == NULL) {
        printf("ERROR");
    }
    else {
        aux->num = element;
        aux->seg = l->pdi;
        aux->ant = l->pdi->ant;
        l->pdi->ant->seg = aux;
        l->pdi->ant = aux;
    }

    return error;
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

int LLISTABIDORD_getSize(LlistaBidOrd l) {
    int size = 0;

    LLISTABIDORD_vesInici(&l);
    while (!LLISTABIDORD_fi(l)) {
        LLISTABIDORD_avanca(&l);
        size++;
    }
    return size;
}

int LLISTABIDORD_fi(LlistaBidOrd l) {
    return l.pdi == l.ult;
}

int LLISTABIDORD_inici(LlistaBidOrd l) {
    return l.pdi == l.cap;
}

void LLISTABIDORD_avanca(LlistaBidOrd *l) {
    l->pdi = l->pdi->seg;
}

void LLISTABIDORD_retrocedeix(LlistaBidOrd *l) {
    l->pdi = l->pdi->ant;
}

int LLISTABIDORD_consulta(LlistaBidOrd l) {
   return l.pdi->num;
}


