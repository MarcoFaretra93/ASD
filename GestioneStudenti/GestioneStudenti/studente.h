#ifndef GestioneStudenti_studente_h
#define GestioneStudenti_studente_h

#include "voti.h"
#include "stringhe.h"

typedef struct {
    char matricola[5];
    listaVoti lv;
} studente;

typedef struct nodoStudente {
    studente info;
    struct nodoStudente* next;
} nodoStudente;

typedef nodoStudente* listaStudenti;

#endif
