//
// Created by Luis on 04/10/2018.
//

#ifndef LISTA_LLISTABIDORD_H
#define LISTA_LLISTABIDORD_H

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
    int element;
    struct n *ant;
    struct n *seg;
} Node;

typedef struct {
    Node *cap;
    Node *ult;
    Node *pdi;
} LlistaBidOrd;

void LLISTABIDORD_crea(LlistaBidOrd *l);
int LLISTABIDORD_insereixOrdenat(LlistaBidOrd *l, int element);
//void LLISTABIDORD_insereixOrdenatDarrera(LlistaBidOrd *l, int element);
int LLISTABIDORD_consultaElement(LlistaBidOrd l, int posicio, int *element);
int LLISTABIDORD_esborra(LlistaBidOrd *l, int posicio);
void LLISTABIDORD_mostra(LlistaBidOrd l);
void LLISTABIDORD_vesInici(LlistaBidOrd *l);
void LLISTABIDORD_vesFinal(LlistaBidOrd *l);
int LLISTABIDORD_buida(LlistaBidOrd l);
void LLISTABIDORD_destrueix(LlistaBidOrd *l);

#endif //LISTA_LLISTABIDORD_H
