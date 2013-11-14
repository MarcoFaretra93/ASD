//
//  studenti.h
//  Studenti
//
//  Created by Marco Faretra on 13/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef Studenti_studenti_h
#define Studenti_studenti_h
#include <stdio.h>
#include <string.h>
#include "Voti.h"

typedef char string[50];

typedef struct  {
    string matricola;
    listaVoti esami;
}studente;

typedef struct nodoStudente {
    studente info;
    struct nodoStudente* next;
}nodoStudente;

typedef nodoStudente* listaStudenti;

int lengthLista(listaStudenti);

float mediaStudente(listaStudenti, string);

void deleteInTesta(listaStudenti*);

void deleteInPosizionePrecisa(listaStudenti*,int);

void deleteStudentePerMedia(listaStudenti*, int);

void addStudente(listaStudenti*, string, listaVoti);

void stampaStudente(listaStudenti);


#endif
