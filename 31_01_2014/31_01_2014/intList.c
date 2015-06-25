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

void addCoda(listaInteri* l, int n) {
    listaInteri temp=*l;
    listaInteri nodo=malloc(sizeof(nodoLista));
    nodo->info=n;
    nodo->next=NULL;
    if(temp==NULL) {
        *l=nodo;
    }
    else {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=nodo;
    }
}

listaInteri allocaLista(albero t,int v) {
    listaInteri l=NULL;
    if(t!=NULL) {
        allocaListaRic(t, v, 0, &l);
        return l;
    }
    else
        return NULL;
}

void allocaListaRic(albero t,int v, int i,listaInteri* l) {
    if(i==v) {
        addCoda(l,t->info);
    }
    if(t->left!=NULL)
        allocaListaRic(t->left, v, i+1,l);
    if(t->right!=NULL)
        allocaListaRic(t->right, v, i+1,l);
}

void stampaLista(listaInteri l) {
    while(l!=NULL) {
        printf("%d ",l->info);
        l=l->next;
    }
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
