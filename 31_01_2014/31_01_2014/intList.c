//
//  intList.c
//  31_01_2014
//
//  Created by Marco Faretra on 24/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "intList.h"
#include <stdio.h>
#include <stdlib.h>

void addTesta(listaInteri* l, int n) {
    listaInteri nodo=malloc(sizeof(nodoLista));
    nodo->info=n;
    nodo->next=*l;
    *l=nodo;
}

listaInteri allocaLista(albero t,int v) {
    return allocaListaRic(t, v, 0);
}

listaInteri allocaListaRic(albero t,int v, int i) {
    listaInteri l = NULL;
    if(i==v) {
        addTesta(&l,t->info);
    }
    if(t->left!=NULL)
        l=concat(l,allocaListaRic(t->left, v, i+1));
    if(t->right!=NULL)
        l=concat(l,allocaListaRic(t->right, v, i+1));
    return l;
}

void stampaLista(listaInteri l) {
    while(l!=NULL) {
        printf("%d ",l->info);
        l=l->next;
    }
}

listaInteri concat(listaInteri l1,listaInteri l2) {
    while(l2!=NULL) {
        addTesta(&l1, l2->info);
        l2=l2->next;
    }
    return l1;
}


int verificaLivelli(albero a1,albero a2,int v) {
    listaInteri l1 = allocaLista(a1, v);
    listaInteri l2 = allocaLista(a2, v);
    int result=0;
    while(l2!=NULL) {
        if(contain(l1,l2->info)) {
            result++;
        }
        l2=l2->next;
    }
    return result;
}

int contain(listaInteri l, int v) {
    while(l!=NULL) {
        if(l->info == v)
            return 1;
        l=l->next;
    }
    return 0;
}

int lungLista(listaInteri l) {
    int result=0;
    while(l!=NULL) {
        result++;
        l=l->next;
    }
    return result;
}


void modificaFile(albero t) {
    FILE *f;
    int x=0;
    int y=0;
    long pos=0;
    f=fopen("/Users/marcofaretra/Desktop/livello.txt", "r+");
    if(f==NULL) printf("Errore connessione");
    else {
        while(fscanf(f, "%d %d\n",&x,&y)!=EOF) {
            if(y!=lungLista(allocaLista(t, x))) {
                fseek(f, pos, SEEK_SET);
                fprintf(f, "%d %d\n",x,lungLista(allocaLista(t, x)));
            }
            pos=ftell(f);
        }
    }
}
