//
//  intList.h
//  31_01_2014
//
//  Created by Marco Faretra on 24/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef _1_01_2014_intList_h
#define _1_01_2014_intList_h
#include "intTree.h"

typedef struct nodoLista{
    int info;
    struct nodoLista* next;
}nodoLista;

typedef nodoLista* listaInteri;

listaInteri allocaLista(albero,int);

void addCoda(listaInteri* , int);

void allocaListaRic(albero,int, int,listaInteri*);

void stampaLista(listaInteri);

int verificaLivelli(albero ,albero,int);

int contain(listaInteri, int);

int lungLista(listaInteri);

void modificaFile(albero);
#endif
