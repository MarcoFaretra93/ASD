//
//  tree.c
//  Febbraio2015
//
//  Created by Marco Faretra on 25/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int esiste_foglia(albero t, char v) {
    if(t!=NULL) {
        if(t->left==NULL && t->right==NULL && t->info==v) {
            return 1;
        }
        return (esiste_foglia(t->left, v))||(esiste_foglia(t->right, v));
    }
    else return 0;
}

void aggiungi(albero* t, char v1, char v2) {
    albero temp=*t;
    albero nodo=malloc(sizeof(nodo_albero));
    nodo->info=v2;
    if(temp->info == v1) {
        if(temp->left==NULL) {
            temp->left=nodo;
            return;
        }
        if(temp->right==NULL) {
            temp->right=nodo;
            return;
        }
    }
    if(temp->left!=NULL)
        aggiungi(&temp->left, v1, v2);
    if(temp->right!=NULL)
        aggiungi(&temp->right, v1, v2);
}

void stampaAlbero(albero a) {
    printf("%c\t",a->info);
    if(a->left!=NULL)
        stampaAlbero(a->left);
    if(a->right!=NULL)
        stampaAlbero(a->right);
}

void somma(albero* t1,albero t2) {
    if(t2->left!=NULL)
        somma(t1, t2->left);
    
    if(t2->right!=NULL)
        somma(t1, t2->right);
    
    if(esiste_foglia(*t1, t2->info)) {
        if(t2->left!=NULL) {
            aggiungi(t1, t2->info, t2->left->info);
        }
        if(t2->right!=NULL) {
            aggiungi(t1, t2->info, t2->right->info);
        }
    }
}
