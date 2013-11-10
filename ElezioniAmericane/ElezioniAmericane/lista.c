#include <stdio.h>
#include <stdlib.h>
#include "stringhe.h"
#include "lista.h"

int lunghezzaLista(plist l) {
    int i=0;
    while(l!=NULL) {
        l=l->next;
        i++;
    }
    return i;
}

void aggiungi(plist* lc, string cod, string nome, string cognome) {
    nodo* nuovoCandidato=malloc(sizeof(nodo));
    copia(nuovoCandidato->info.codice, cod);
    copia(nuovoCandidato->info.nome, cod);
    copia(nuovoCandidato->info.cognome, cod);
    nuovoCandidato->next=*lc;
    *lc=nuovoCandidato;
}

void rimuoviInTesta(plist* l) {
    plist tmp=*l;
    *l=tmp->next;
    free(tmp);
}

void rimuoviInPosizionePrecisa(plist* l, int p) {
    int i;
    plist prev, curr;
    if(p>0 && p<=lunghezzaLista(*l)) {
        if(p==1)
            rimuoviInTesta(l);
        else {
            prev=*l;
            curr=prev->next;
            i=2;
            while(i<2) {
                prev=curr;
                curr=curr->next;
                i++;
            }
            prev->next=curr->next;
            free(curr);
        }
    }
    else
        printf("Posizione inesistente.\n");
}
