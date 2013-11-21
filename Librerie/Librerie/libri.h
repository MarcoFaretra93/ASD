//
//  libri.h
//  Librerie
//
//  Created by Marco Faretra on 20/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef Librerie_libri_h
#define Librerie_libri_h
#include <stdio.h>

typedef char string[50];

typedef struct {
    int ID;
    string titolo;
    string autore;
    int prezzo;
}libro;

typedef struct nodoLibro {
    libro info;
    struct nodoLibro* next;
}nodoLibro;

typedef nodoLibro* listaLibri;

void addLibro(listaLibri*,int,string,string,int);

int lengthLibri(listaLibri);

void rimuoviTesta(listaLibri*);

int libriComune(listaLibri,listaLibri);

void stampaLibri(listaLibri);

void inserisciLibroCrescente(listaLibri*,int,string,string,int);
#endif
