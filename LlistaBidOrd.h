//
// Created by Luis Ribó on 04/10/2018.
//

#ifndef LISTA_LLISTABIDORD_H
#define LISTA_LLISTABIDORD_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


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

LlistaBidOrd LLISTABIDORD_crea();
int LLISTABIDORD_insereixOrdenat(LlistaBidOrd *l, int element);
void LLISTABIDORD_vesInici(LlistaBidOrd *l);
void LLISTABIDORD_vesFinal(LlistaBidOrd *l);
int LLISTABIDORD_buida(LlistaBidOrd l);
void LLISTABIDORD_destrueix(LlistaBidOrd *l);
int LLISTABIDORD_getSize(LlistaBidOrd l);
int LLISTABIDORD_fi(LlistaBidOrd l);
void LLISTABIDORD_avanca(LlistaBidOrd *l);
void LLISTABIDORD_retrocedeix(LlistaBidOrd *l);
int LLISTABIDORD_inici(LlistaBidOrd l);
int LLISTABIDORD_consulta(LlistaBidOrd l);


#endif //LISTA_LLISTABIDORD_H
