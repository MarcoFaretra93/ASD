#include <stdio.h>
#include <stdlib.h>
#include "voti.h"

int isVotoValido(plist voto, plist listaCandidati) {
    int dev=0;
    string codice;
    
    copia(codice, voto->info.codice);
    while(listaCandidati!=NULL && dev==0) {
        if(uguale(listaCandidati->info.codice, codice)==1)
            dev=1;
        listaCandidati=listaCandidati->next;
    }
    
    return dev;
}

int votiValidi(plist listaVoti, plist listaCandidati) {
    int i=0;
    
    while(listaVoti!=NULL) {
        if(isVotoValido(listaVoti, listaCandidati)==1)
            i++;
        listaVoti=listaVoti->next;
    }
    
    return i;
}

char* getCodiceByNomeECognome(plist l, string nome, string cognome) {
    int dev=0;
    string codice=malloc(sizeof(char)*50);
    while(l!=NULL && dev==0) {
        if(uguale(l->info.nome, nome)==1 && uguale(l->info.cognome, cognome)==1)
            dev=1;
    }
    copia(codice, l->info.codice);
    
    return codice;
}


int votiCandidato(plist listaVoti, plist listaCandidati, string nome, string cognome) {
    
}