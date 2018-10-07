//
// Created by Luis Ribó on 04/10/2018.
//

#ifndef LISTA_LLISTABIDORD_H
#define LISTA_LLISTABIDORD_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition of the list */

typedef struct n {
    int num;
    struct n *ant;
    struct n *seg;
} Node;

typedef struct {
    Node *cap;
    Node *ult;
    Node *pdi;
} LlistaBidOrd;





// Method to create the list
LlistaBidOrd LLISTABIDORD_crea();

// Method to insert element into the list. Returns error
int LLISTABIDORD_insereixOrdenat(LlistaBidOrd *l, int element);

// Method to go to the first element of the list
void LLISTABIDORD_vesInici(LlistaBidOrd *l);

// Method to go to the last element of the list
void LLISTABIDORD_vesFinal(LlistaBidOrd *l);

// Method to establish if the list is empty. Returns 1 or 0
int LLISTABIDORD_buida(LlistaBidOrd l);

// Method to destroy every node and the list structure
void LLISTABIDORD_destrueix(LlistaBidOrd *l);

// Method to get the size of the list
int LLISTABIDORD_getSize(LlistaBidOrd l);

// Method to establish if pdi is pointing the last element of the list
int LLISTABIDORD_fi(LlistaBidOrd l);

// Method to establish if pdi is pointing the first element of the list
int LLISTABIDORD_inici(LlistaBidOrd l);

// Method to go forward inside the list
void LLISTABIDORD_avanca(LlistaBidOrd *l);

// Method to go back inside the list
void LLISTABIDORD_retrocedeix(LlistaBidOrd *l);

// Method to establish the number that is pointed by pdi. Returns the value
int LLISTABIDORD_consulta(LlistaBidOrd l);


#endif //LISTA_LLISTABIDORD_H
