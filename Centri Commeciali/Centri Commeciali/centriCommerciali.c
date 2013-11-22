//
//  centriCommerciali.c
//  Centri Commeciali
//
//  Created by Marco Faretra on 22/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "centriCommerciali.h"

listaProdotti* getProdotti(listaCentri l) {
    return &l->info.prodotti;
}

int contaProdottiCentri(listaCentri l,string categoria) {
    listaProdotti temp;
    int i=0;
    while(l!=NULL) {
        temp=*getProdotti(l);
        i+=contaProdotti(temp, categoria);
        l=l->next;
    }
    return i;
}

void inserisciProdottoOrd(listaCentri* l, int idPar, int id, string nome, string categoria,int prezzo) {
    int dev=0;
    listaCentri p=*l;
    listaProdotti temp;
    while(p!=NULL && dev==0) {
        if(p->info.ID==idPar) {
            temp=*getProdotti(*l);
            dev=1;
            inserisciOrdinato(&temp, id, nome, categoria, prezzo);
            p->info.prodotti=temp;
        }
        p=p->next;
    }
}

int prodottiCentroComuni(listaCentri l, int id1, int id2) {
    int dev=0;
    listaCentri l2=l;
    listaProdotti p1 = NULL,p2 = NULL;
    int result=0;
    while(l!=NULL && dev==0) {
        if(l->info.ID==id1) {
            dev=1;
            p1=*getProdotti(l);
        }
        l=l->next;
    }
    dev=0;
    while(l2!=NULL && dev==0) {
        if(l2->info.ID==id2) {
            dev=1;
            p2=*getProdotti(l2);
        }
        l2=l2->next;
    }
    result=prodottiComuni(p1, p2);
    return result;
}

void addTesta(listaCentri* l,int id, string nome, string luogo,listaProdotti prodotti) {
    nodoCentro* n=malloc(sizeof(nodoCentro));
    n->info.ID=id;
    n->info.prodotti=prodotti;
    strcpy(n->info.nome, nome);
    strcpy(n->info.luogo, luogo);
    n->next=*l;
    *l=n;
}

void stampaCentri(listaCentri l) {
    while(l!=NULL) {
        printf("l'id del centro commerciale è: %d\nil nome del centro commerciale è: %s\nil luogo del centro commerciale è: %s\n",l->info.ID,l->info.nome,l->info.luogo);
        printf("Ed i prodotti sono: \n");
        stampaProdotti(l->info.prodotti);
        l=l->next;
    }
}