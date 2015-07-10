//
//  alberi_comune.c
//  Esercitazione_Gennaio_2015
//
//  Created by Marco Faretra on 28/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "alberi_comune.h"
#include <stdio.h>
#include <stdlib.h>

int esiste_foglia(albero T, int f) {
    if(T==NULL) return 0;
    else {
        return (T->info==f) || (esiste_foglia(T->left, f)) || (esiste_foglia(T->right, f));
    }
}

int max(int v1,int v2) {
    if(v1>v2)
        return v1;
    else
        return v2;
}
int altezza(albero T) {
    if(T==NULL) return 0;
    else {
        if(T->left==NULL && T->right==NULL)
            return 0;
        return 1+max(altezza(T->left), altezza(T->right));
    }
}

int num_nodi_livello(albero T, int v) {
    int i=0;
    if(T!=NULL) {
        if(v==0)
            i++;
        return i+num_nodi_livello(T->left, v-1)+num_nodi_livello(T->right, v-1);
    }
    else
        return 0;
}

//mi piace particolarmente com'è venuta questa funzione
int esiste_nodo_al_livello(albero T,int n, int v) {
    if(T!=NULL) {
        if(v==0)
            return (T->info==n);
        return (esiste_nodo_al_livello(T->left, n, v-1)) || (esiste_nodo_al_livello(T->right, n, v-1));
    }
    else
        return 0;
}

int trovaLivello(albero T, int v) {
    int h=altezza(T);
    for(int i=0;i<=h;i++) {
        if(esiste_nodo_al_livello(T, v, i)) return i;
    }
    return -1;
}

int* costruisci_livello_foglia(albero T,int v) {
    int n=trovaLivello(T, v);
    int i=0;
    int* result=calloc(num_nodi_livello(T, n),sizeof(int));
    riempi(T, n, result,&i);
    return result;
}

void riempi(albero T,int v,int* result,int* i) {
    if(T!=NULL) {
        if(v==0) {
            result[*i]=T->info;
            *i=*i+1;
        }
        else {
            riempi(T->left, v-1, result,i);
            riempi(T->right, v-1, result,i);
        }
    }
}

int** livelli_nodo_comune(albero T1,albero T2) {
    int h = altezza(T1);
    int** A=NULL;
    A=calloc(h+1, sizeof(int*));
    int i = 0;
    for(i=0;i<h;i++)
        A[i]=NULL;
    livelli_nodo_comune_aux(T1, T1, T2, A, 0);
    return A;
}

void livelli_nodo_comune_aux(albero principale,albero T1,albero T2,int** A, int l) {
    if(T1!=NULL) {
        if(esiste_nodo_al_livello(T2, T1->info, l)) {
            if(A[l]==NULL) {
                int n = num_nodi_livello(principale, l);
                int* B=calloc(n, sizeof(int));
                int i = 0;
                riempi(principale, l, B, &i);
                A[l]=B;
            }
        }
        livelli_nodo_comune_aux(principale, T1->left, T2, A, l+1);
        livelli_nodo_comune_aux(principale, T1->right, T2, A, l+1);
    }
}




