//
//  libri.c
//  Librerie
//
//  Created by Marco Faretra on 20/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include "libri.h"
#include <stdlib.h>
#include <string.h>

void addLibro(listaLibri* l,int id, string titolo, string autore, int prezzo) {
    nodoLibro* n=malloc(sizeof(nodoLibro));
    n->info.ID=id;
    n->info.prezzo=prezzo;
    strcpy(n->info.titolo, titolo);
    strcpy(n->info.autore, autore);
    n->next=*l;
    *l=n;
}

int lengthLibri(listaLibri l) {
    int risultato=0;
    while(l!=NULL) {
        l=l->next;
        risultato++;
    }
    return risultato;
}

void rimuoviTesta(listaLibri* l) {
    listaLibri temp=*l;
    *l=temp->next;
    free(temp);
}

int libriComune(listaLibri l1,listaLibri l2) {
    int risultato=0;
    listaLibri temp=l2;
    while(l1!=NULL) {
        temp=l2;
        while(temp!=NULL) {
            if(l1->info.ID==temp->info.ID)
                risultato++;
            temp=temp->next;
        }
        l1=l1->next;
    }
    return risultato;
}

void stampaLibri(listaLibri l) {
    while(l!=NULL) {
        printf("l'id del libro è: %d\n il titolo del libro è %s\n l'autore del libro è %s\n il prezzo del libro è %d\n",l->info.ID,l->info.titolo,l->info.autore,l->info.prezzo);
        l=l->next;
    }
}

void inserisciLibroCrescente(listaLibri* l,int id,string titolo,string autore,int prezzo) {
    nodoLibro* n=malloc(sizeof(nodoLibro));
    listaLibri temp=*l;
    listaLibri prev;
    listaLibri curr;
    int dev=0;
    n->info.ID=id;
    n->info.prezzo=prezzo;
    strcpy(n->info.autore, autore);
    strcpy(n->info.titolo, titolo);
    if(lengthLibri(temp)==0 || id<temp->info.ID)
        addLibro(l, id, titolo, autore, prezzo);
    else {
        prev=*l;
        curr=prev->next;
        while(curr!=NULL && dev==0) {
            if(id<curr->info.ID) {
                prev->next=n;
                n->next=curr;
                dev=1;
            }
            else
                curr=curr->next;
        }
    }
}
