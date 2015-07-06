//
//  intTree.h
//  Esame-Luglio2015
//
//  Created by Marco Faretra on 06/07/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef Esame_Luglio2015_intTree_h
#define Esame_Luglio2015_intTree_h

typedef struct nodoAlbero {
    int info;
    struct nodoAlbero* sx;
    struct nodoAlbero* dx;
}nodoAlbero;

typedef nodoAlbero* albero;

int conta_livello(albero,int);

int* creaArray(albero,int);

void creaArrayAux(albero,int,int*,int*);

int confrontaArray(int*,int*,int,int);

int confronta_alberi(albero,albero);
int altezza(albero);
int max(int,int);
#endif
