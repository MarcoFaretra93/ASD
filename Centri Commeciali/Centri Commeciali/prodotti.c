//
//  prodotti.c
//  Centri Commeciali
//
//  Created by Marco Faretra on 22/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prodotti.h"

void addProdottoTesta(listaProdotti* l, int id,string nome,string categoria,int prezzo) {
    nodoProdotto* n=malloc(sizeof(nodoProdotto));
    n->info.ID=id;
    n->info.prezzo=prezzo;
    strcpy(n->info.nome, nome);
    strcpy(n->info.categoria, categoria);
    n->next=*l;
    *l=n;
}

int lengthListaProdotti(listaProdotti l) {
    int i=0;
    while(l!=NULL) {
        i++;
        l=l->next;
    }
    return i;
}

void inserisciOrdinato(listaProdotti* l,int id,string nome,string categoria,int prezzo) {
    listaProdotti n=malloc(sizeof(nodoProdotto));
    listaProdotti prev;
    listaProdotti curr;
    int dev=0;
    if (lengthListaProdotti(*l)==0 || id<(*l)->info.ID)
        addProdottoTesta(l, id, nome, categoria, prezzo);
    else {
        n->info.ID=id;
        n->info.prezzo=prezzo;
        strcpy(n->info.nome, nome);
        strcpy(n->info.categoria, categoria);
        prev=*l;
        curr=prev->next;
        while(curr!=NULL && dev==0) {
            if(id<curr->info.ID) {
                n->next=curr;
                prev->next=n;
                dev=1;
            }
            prev=curr;
            curr=curr->next;
        }
        if(dev==0) {
            prev->next=n;
            n->next=NULL;
        }
    }
}

int contaProdotti(listaProdotti l, string categoria) {
    int i=0;
    while(l!=NULL) {
        if(strcmp(l->info.categoria,categoria)==0)
            i++;
        l=l->next;
    }
    return i;
}

int prodottiComuni(listaProdotti a,listaProdotti b) {
    int i=0;
    listaProdotti temp=b;
    while(a!=NULL) {
        temp=b;
        while(temp!=NULL) {
            if(temp->info.ID==a->info.ID)
                i++;
            temp=temp->next;
        }
        a=a->next;
    }
    return i;
}

void stampaProdotti(listaProdotti l) {
    while(l!=NULL) {
        printf("l'id del prodotto è: %d\nil nome del prodotto è: %s\nla categoria del prodotto è: %s\nil prezzo del prodotto è:%d\n",l->info.ID,l->info.nome,l->info.categoria,l->info.prezzo);
        l=l->next;
    }
}