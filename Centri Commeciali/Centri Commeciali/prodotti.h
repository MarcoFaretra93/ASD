//
//  prodotti.h
//  Centri Commeciali
//
//  Created by Marco Faretra on 22/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef Centri_Commeciali_prodotti_h
#define Centri_Commeciali_prodotti_h

typedef char string[50];

typedef struct {
    int ID;
    string nome;
    string categoria;
    int prezzo;
}prodotto;

typedef struct nodoProdotto {
    prodotto info;
    struct nodoProdotto* next;
}nodoProdotto;

typedef nodoProdotto* listaProdotti;

void inserisciOrdinato(listaProdotti*,int,string,string,int);

void addProdottoTesta(listaProdotti*,int,string,string,int);

int lengthListaProdotti(listaProdotti);

int contaProdotti(listaProdotti,string);

int prodottiComuni(listaProdotti,listaProdotti);

void stampaProdotti(listaProdotti);

#endif
