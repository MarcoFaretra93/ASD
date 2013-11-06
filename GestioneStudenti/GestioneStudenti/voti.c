#include <stdio.h>
#include <stdlib.h>
#include "voti.h"

void addVoto(listaVoti* l, int v) {
    if(v>=18 && v<=31) {
        nodoVoto* nuovoNodo=malloc(sizeof(nodoVoto));
        nuovoNodo->info=v;
        nuovoNodo->next=*l;
        *l=nuovoNodo;
    }
    else
        printf("Inserisci un voto compreso tra 18 e 31");
}

void printVoti(listaVoti l) {
    printf("[");
    while(l->next!=NULL) {
        printf("(%d)", l->info);
        l=l->next;
    }
    printf("(%d)", l->info);
    printf("]\n");
}

float mediaVoti(listaVoti l) {
    float risultato=0;
    int i=0;
    while(l->next!=NULL) {
        risultato+=l->info;
        i++;
    }
    /*risultato+=l->info;
    i++;
    risultato/=i;*/
    
    return risultato;
}