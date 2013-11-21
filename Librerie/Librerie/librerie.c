//
//  librerie.c
//  Librerie
//
//  Created by Marco Faretra on 20/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include "librerie.h"
#include <stdlib.h>
#include <string.h>

void addLibreria(listaLibrerie* l, int id,string nome, string città, listaLibri libri) {
    nodoLibreria* n=malloc(sizeof(nodoLibreria));
    n->info.ID=id;
    n->info.libri=libri;
    strcpy(n->info.nome, nome);
    strcpy(n->info.città, città);
    n->next=*l;
    *l=n;
}

listaLibri getLibri(listaLibrerie l) {
    return l->info.libri;
}

void rimozioneLibroAutore(listaLibrerie* l, string autore) {
    listaLibri temp=getLibri(*l);
    listaLibri curr;
    listaLibri prev;
    int dev=0;
    if(lengthLibri(temp)==0)
        printf("La lista è vuota");
    else {
        if(strcmp(temp->info.autore, autore)==0) {
            rimuoviTesta(&temp);
        }
        else {
            prev=temp;
            curr=prev->next;
            while(curr!=NULL && dev==0) {
                if(strcmp(curr->info.autore, autore)==0) {
                    prev->next=curr->next;
                    free(curr);
                    dev=1;
                }
                prev=curr;
                curr=curr->next;
            }
        }
        (*l)->info.libri=temp;
    }
}

void inserisciCrescente(listaLibrerie* l, int id,int idAutore, string titolo,string autore,int prezzo) {
    listaLibri temp=getLibri(*l);
    listaLibrerie t=*l;
    int dev=0;
    while(t!=NULL && dev==0) {
        if(t->info.ID==id) {
            inserisciLibroCrescente(&temp, idAutore, titolo, autore, prezzo);
            dev=1;
        }
        t=t->next;
    }
    (*l)->info.libri=temp;
}

int libriComuniLibrerie(libreria l1,libreria l2) {
    return libriComune(l1.libri, l2.libri);
}

int libriComuniAutore(listaLibrerie l,string autore) {
    listaLibri temp;
    int risultato=0;
    while(l!=NULL) {
        temp=getLibri(l);
        while(temp!=NULL) {
            if(strcmp(temp->info.autore, autore)==0)
                risultato++;
            temp=temp->next;
        }
        l=l->next;
    }
    return risultato;
}

void stampaLibrerie(listaLibrerie l) {
    while(l!=NULL) {
        printf("l'id è: %d\nil nome della librerie è: %s\nla città della libreria è: %s\n",l->info.ID,l->info.nome,l->info.città);
        printf("e i libri sono:\n");
        stampaLibri(l->info.libri);
        l=l->next;
    }
}