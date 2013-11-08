#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "portate.h"

void addPortata(listaPortate* lp, int prezzo, string descrizione) {
    nodoPortate* nodo=malloc(sizeof(nodoPortate));
    nodo->info.prezzo=prezzo;
    strcpy(nodo->info.descrizione, descrizione);
    nodo->next=*lp;
    *lp=nodo;
}

int mediaPortate(listaPortate lp) {
    int risultato=0;
    int i=0;
    while(lp!=NULL) {
        risultato+=lp->info.prezzo;
        i++;
        lp=lp->next;
    }
    risultato/=i;
    
    return risultato;
}

void stampaPortate(listaPortate lp) {
    printf("[");
    while(lp!=NULL) {
        printf("(%s - %d)", lp->info.descrizione, lp->info.prezzo);
        lp=lp->next;
    }
    printf("]\n");
}