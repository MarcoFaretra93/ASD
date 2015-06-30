//
//  alberi_comune.h
//  Esercitazione_Gennaio_2015
//
//  Created by Marco Faretra on 28/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef Esercitazione_Gennaio_2015_alberi_comune_h
#define Esercitazione_Gennaio_2015_alberi_comune_h
typedef struct elem{
    int info;
    struct elem* left;
    struct elem* right;
}nodo_albero;

typedef nodo_albero* albero;

int esiste_foglia(albero,int);

int altezza(albero);

int max(int ,int);

int num_nodi_livello(albero,int);

int esiste_nodo_al_livello(albero,int,int);

int* costruisci_livello_foglia(albero,int); //da vedere

int trovaLivello(albero,int);   //metodo di supporto per up

void riempi(albero,int,int*,int*);

int** livelli_nodo_comune(albero,albero);

void livelli_nodo_comune_aux(albero,albero,albero,int**,int);
#endif
