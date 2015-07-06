//
//  intTree.c
//  Esame-Luglio2015
//
//  Created by Marco Faretra on 06/07/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "intTree.h"
#include <stdio.h>
#include <stdlib.h>
int conta_livello(albero T, int m) {
    if(T==NULL) return 0;
    else {
        if(m==0)
            return 1;
        return conta_livello(T->sx, m-1)+conta_livello(T->dx, m-1);
    }
}

int* creaArray(albero T, int v) {
    int* result=calloc(conta_livello(T, v), sizeof(int));
    int i=0;
    creaArrayAux(T, v,result,&i);
    return result;
}

void creaArrayAux(albero T, int m,int* result,int* i) {
    if(T!=NULL) {
        if(m==0) {
            result[*i]=T->info;
            *i=*i+1;
        }
        creaArrayAux(T->sx, m-1,result,i);
        creaArrayAux(T->dx, m-1,result,i);
    }
}

int confrontaArray(int* A1,int* A2,int v1,int v2) {
    int i=0;
    int j=0;
    int trovato=0;
    if(v1!=v2)
        return 0;
    else {
        for(i=0;i<v1;i++) {
            for(j=0;j<v2;j++) {
                if(A1[i]==A2[j])
                    trovato=1;
            }
            if(!trovato) return 0;
        }
        return 1;
    }
}

int confronta_alberi(albero T1,albero T2) {
    int* A1=NULL;
    int* A2=NULL;
    int cont=0;
    int h=altezza(T1);
    int i=0;
    for(i=0;i<=h;i++) {
        A1=creaArray(T1, i);
        A2=creaArray(T2, i);
        if(confrontaArray(A1, A2, conta_livello(T1, i), conta_livello(T2, i)))
            cont++;
    }
    return cont;
}

int altezza(albero T) {
    if(T==NULL) return 0;
    else {
        if(T->sx == NULL && T->dx==NULL)
            return 0;
        return 1+max(altezza(T->sx),altezza(T->dx));
    }
}

int max(int a1,int a2) {
    if(a1>a2)
        return a1;
    else
        return a2;
}

