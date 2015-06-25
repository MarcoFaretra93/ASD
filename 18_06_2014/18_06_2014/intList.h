//
//  intList.h
//  18_06_2014
//
//  Created by Marco Faretra on 23/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef _8_06_2014_intList_h
#define _8_06_2014_intList_h
#include "charTree.h"

typedef struct nodoLista{
    int info;
    struct nodoLista* next;
}nodoLista;

typedef nodoLista* lista;

lista allocaLista(albero,char);

void allocaListaDaRadice(albero,int,lista*);

void stampaLista(lista);
#endif
