//
// Created by Luis Ribó on 04/10/2018.
//

#include "LlistaBidOrd.h"


/* This method creates a LlistaBidOrd element and creates 3 pointers to 2 Nodes,
   linking them together with seg and ant pointers from each Node. Returns the list */
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


/* This method inserts an element to the list. First, locates the position
   where the element has to be because it's ordered and then creates a new
   node with the element value and adds the node to the list. Returns if
   has been an error during this process */
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
        printf("Error: Memory reservation failed when creating the element\n");
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


/* This method puts the PDI pointer at the first element of the list */
void LLISTABIDORD_vesInici(LlistaBidOrd *l) {
    l->pdi = l->cap->seg;
}


/* This method puts the PDI pointer at the last element of the list */
void LLISTABIDORD_vesFinal(LlistaBidOrd *l) {
    l->pdi = l->ult->ant;
}


/* This method returns 1 if the list is empty */
int LLISTABIDORD_buida(LlistaBidOrd l) {
    return l.cap->seg == l.ult;
}


/* This method destroys every node from the list and then puts
   the 3 pointers from LlistaBidOrd to NULL */
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


/* This method returns the number of nodes of the list */
int LLISTABIDORD_getSize(LlistaBidOrd l) {
    int size = 0;

    LLISTABIDORD_vesInici(&l);
    while (!LLISTABIDORD_fi(l)) {
        LLISTABIDORD_avanca(&l);
        size++;
    }
    return size;
}


/* This method returns 1 if PDI is pointing to the ULT node */
int LLISTABIDORD_fi(LlistaBidOrd l) {
    return l.pdi == l.ult;
}


/* This method returns 1 if PDI is pointing to the CAP node */
int LLISTABIDORD_inici(LlistaBidOrd l) {
    return l.pdi == l.cap;
}


/* This method puts the PDI pointer to the PDI->SEG node (the next one to the right) */
void LLISTABIDORD_avanca(LlistaBidOrd *l) {
    l->pdi = l->pdi->seg;
}


/* This method puts the PDI pointer to the PDI->ANT node (the next one to the left) */
void LLISTABIDORD_retrocedeix(LlistaBidOrd *l) {
    l->pdi = l->pdi->ant;
}


/* This method returns the integer from the node which is pointed with PDI */
int LLISTABIDORD_consulta(LlistaBidOrd l) {
   return l.pdi->num;
}


