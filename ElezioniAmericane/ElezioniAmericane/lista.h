#ifndef ElezioniAmericane_lista_h
#define ElezioniAmericane_lista_h

#include "stringhe.h"

typedef struct {
    string codice;
    string nome;
    string cognome;
} persona;

typedef struct nodo {
    persona info;
    struct nodo* next;
} nodo;

typedef nodo* plist;

/*  Le seguenti funzioni sono da considerare utilizzabili
    sia per la lista relativa agli elettori sia per
    quella dei candidati */

int lunghezzaLista(plist);
void aggiungi(plist*, string, string, string);
void rimuoviInTesta(plist*);
void rimuoviInPosizionePrecisa(plist*, int);

#endif
