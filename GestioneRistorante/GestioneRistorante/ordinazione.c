#include <stdio.h>
#include <stdlib.h>
#include "ordinazione.h"

void addOrdinazione(listaOrdinazione* lo, int codice, listaPortate lp) {
    nodoOrdinazione* nuovaOrdinazione=malloc(sizeof(nodoOrdinazione));
    nuovaOrdinazione->info.codice=codice;
    nuovaOrdinazione->info.portate=lp;
    nuovaOrdinazione->next=*lo;
    *lo=nuovaOrdinazione;
}

int lengthLista(listaOrdinazione lo) {
    int risultato=0;
    while(lo!=NULL) {
        lo=lo->next;
        risultato++;
    }
    return risultato;
}

void rimuoviInTesta(listaOrdinazione* lo) {
    listaOrdinazione tmp=*lo;
    *lo=tmp->next;
    free(tmp);
}

void rimuoviInPosizionePrecisa(listaOrdinazione* lo, int posizione) {
    int length=lengthLista(*lo);
    int i;
    nodoOrdinazione *prev, *curr;
    if(*lo!=NULL) {
        if(posizione>0 && posizione<=length) {
            if(posizione!=1) {
                i=2;
                prev=*lo;
                curr=prev->next;
                while(i<posizione) {
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=curr->next;
                free(curr);
            }
            else
                rimuoviInTesta(lo);
        }
        else
            printf("Inserisci una posizione valida.\n");
    }
    else
        printf("La lista e' vuota.\n");
}

void rimuoviOrdinazionePerMedia(listaOrdinazione* lo, int media) {
    listaOrdinazione tmp=*lo;
    int i=1;
    
    while(tmp!=NULL) {
        if(mediaPortate(tmp->info.portate)<media)
            rimuoviInPosizionePrecisa(lo, i);
        else
            i++;
        tmp=tmp->next;
    }
}

int getMediaByCod(listaOrdinazione lo, int codice) {
    int dev=0;
    float risultato=0;
    
    if(lo!=NULL) {
        while(lo!=NULL && dev!=1) {
            if(lo->info.codice==codice) {
                risultato=mediaPortate(lo->info.portate);
                dev=1;
            }
            lo=lo->next;
        }
        if(dev==0)
            printf("Inserire un codice valido.\n");
    }
    else
        printf("La lista e' vuota.\n");
    
    return risultato;
}

void stampaOrdinazioni(listaOrdinazione l) {
    while (l!=NULL) {
        printf("{ %d - ", l->info.codice);
        stampaPortate(l->info.portate);
        printf("}\n");
        l=l->next;
    }
}