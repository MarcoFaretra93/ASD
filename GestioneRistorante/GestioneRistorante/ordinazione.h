#ifndef GestioneRistorante_ordinazione_h
#define GestioneRistorante_ordinazione_h

#include "portate.h"

typedef struct {
    int codice;
    listaPortate portate;
} ordinazione;

typedef struct nodoOrdinazione {
    ordinazione info;
    struct nodoOrdinazione* next;
} nodoOrdinazione;

typedef nodoOrdinazione* listaOrdinazione;

void addOrdinazione(listaOrdinazione*, int, listaPortate);

int lengthLista(listaOrdinazione);
void rimuoviInTesta(listaOrdinazione*);
void rimuoviInPosizionePrecisa(listaOrdinazione*, int);
void rimuoviOrdinazionePerMedia(listaOrdinazione*, float);
int getMediaByCod(listaOrdinazione, int);

#endif