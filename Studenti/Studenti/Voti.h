//
//  Voti.h
//  Studenti
//
//  Created by Marco Faretra on 13/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef Studenti_Voti_h
#define Studenti_Voti_h
#include <stdio.h>

typedef struct nodoVoto {
    int info;
    struct nodoVoto* next;
}nodoVoto;

typedef nodoVoto* listaVoti;

float mediaVoti(listaVoti);

void addVoto(listaVoti*, int);

void stampaVoti(listaVoti);


#endif
