//
//  centriCommerciali.h
//  Centri Commeciali
//
//  Created by Marco Faretra on 22/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef Centri_Commeciali_centriCommerciali_h
#define Centri_Commeciali_centriCommerciali_h
#include "prodotti.h"

typedef struct {
    int ID;
    string nome;
    string luogo;
    listaProdotti prodotti;
}centro;

typedef struct nodoCentro {
    centro info;
    struct nodoCentro* next;
}nodoCentro;

typedef nodoCentro* listaCentri;

int contaProdottiCentri(listaCentri,string);

void inserisciProdottoOrd(listaCentri*,int,int,string,string,int);

int prodottiCentroComuni(listaCentri,int,int);

listaProdotti* getProdotti(listaCentri);

void addTesta(listaCentri*,int,string,string,listaProdotti); //per testare

void stampaCentri(listaCentri);

#endif
