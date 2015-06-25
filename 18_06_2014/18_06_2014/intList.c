//
//  intList.c
//  18_06_2014
//
//  Created by Marco Faretra on 23/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "intList.h"
#include <stdio.h>
#include <stdlib.h>


void addTesta(lista* l, int i) {
    lista nodo=malloc(sizeof(nodoLista));
    nodo->info=i;
    nodo->next=*l;
    *l=nodo;
}

lista allocaLista(albero a, char v) {
    lista l=NULL;
    if(a!=NULL) {
        if(a->info==v) {
            allocaListaDaRadice(a, 0, &l);
            return l;
        }
        if(a->left!=NULL && a->info>v)
            return allocaLista(a->left, v);
        if(a->right!=NULL && a->info<v)
            return allocaLista(a->right, v);
        return NULL;
    }
    else return NULL;
}

void allocaListaDaRadice(albero a,int i,lista* l) {
    i++;
    if(a->left==NULL && a->right==NULL) {
        addTesta(l, i-1);
    }
    if(a->left!=NULL)
        allocaListaDaRadice(a->left,i,l);
    if(a->right!=NULL)
        allocaListaDaRadice(a->right,i,l);
}

void stampaLista(lista l) {
    while(l!=NULL) {
        printf("%d\t",l->info);
        l=l->next;
    }
}