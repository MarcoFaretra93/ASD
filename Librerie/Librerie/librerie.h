//
//  librerie.h
//  Librerie
//
//  Created by Marco Faretra on 20/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef Librerie_librerie_h
#define Librerie_librerie_h
#include "libri.h"

typedef struct {
    int ID;
    string nome;
    string città;
    listaLibri libri;
}libreria;

typedef struct nodoLibreria {
    libreria info;
    struct nodoLibreria* next;
}nodoLibreria;

typedef nodoLibreria* listaLibrerie;

void addLibreria(listaLibrerie*, int, string, string, listaLibri);

listaLibri* getLibri(listaLibrerie);

void rimozioneLibroAutore(listaLibrerie*, string);

void inserisciCrescente(listaLibrerie*,int,int,string,string,int);

int libriComuniLibrerie(libreria,libreria);

int libriComuniAutore(listaLibrerie,string);

void stampaLibrerie(listaLibrerie);
#endif
