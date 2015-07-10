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
    if(temp!=NULL){
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
}

void stampaAlberoPreOrder(albero a) {
    if(a!=NULL) {
        printf("%c\t",a->info);
        if(a->left!=NULL)
            stampaAlberoPreOrder(a->left);
        if(a->right!=NULL)
            stampaAlberoPreOrder(a->right);
    }
    else printf("Albero vuoto");
}

void stampaAlberoPostOrder(albero a) {
    if(a!=NULL) {
        if(a->left!=NULL)
            stampaAlberoPostOrder(a->left);
        if(a->right!=NULL)
            stampaAlberoPostOrder(a->right);
        printf("%c\t",a->info);
    }
}

void stampaAlberoInOrder(albero a) {
    if(a!=NULL) {
        if(a->left!=NULL)
            stampaAlberoInOrder(a->left);
        printf("%c\t",a->info);
        if(a->right!=NULL)
            stampaAlberoInOrder(a->right);
    }
}

void somma(albero* t1,albero t2) {
    if(t2!=NULL) {
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
}

void modificaFile(albero a) {
    FILE *f;
    blocco b;
    long pos=0;
    f=fopen("/Users/marcofaretra/Desktop/nodi.dat", "rb+");
    if(f==NULL) printf("Errore accesso file");
    else {
        while(fread(&b, sizeof(blocco), 1, f)>0) {
            if(esiste_foglia(a, b.x)!=b.y) {
                fseek(f, pos, SEEK_SET);
                b.y=esiste_foglia(a, b.x);
                fwrite(&b, sizeof(blocco), 1, f);
            }
            pos=ftell(f);
        }
    }
    fclose(f);
}
