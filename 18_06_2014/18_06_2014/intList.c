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
    if(a->info==v)
        return allocaListaDaRadice(a, 0);
    if(a->left!=NULL && a->info>v)
        return allocaLista(a->left, v);
    if(a->right!=NULL && a->info<v)
        return allocaLista(a->right, v);
    return NULL;
}

lista allocaListaDaRadice(albero a,int i) {
    lista l=NULL;
    lista p=NULL;
    lista q=NULL;
    i++;
    if(a->left==NULL && a->right==NULL) {
        addTesta(&l, i-1);
    }
    if(a->left!=NULL)
        p=allocaListaDaRadice(a->left,i);
    if(a->right!=NULL)
        q=allocaListaDaRadice(a->right,i);
    return concat(concat(l, p),q);
}

lista concat(lista l1, lista l2) {
    while(l2!=NULL) {
        addTesta(&l1, l2->info);
        l2=l2->next;
    }
    return l1;
}