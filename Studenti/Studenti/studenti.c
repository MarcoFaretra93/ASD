//
//  studenti.c
//  Studenti
//
//  Created by Marco Faretra on 13/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include "studenti.h"
#include <stdlib.h>
#include <string.h>

float mediaStudente(listaStudenti l, string matricola) {
    float temp=0;
    if(l!=NULL) {
        while(l!=NULL) {
            if(strcmp(l->info.matricola, matricola)==0)
                temp=mediaVoti(l->info.esami);
            l=l->next;
        }
    }
    else
        printf("la lista è vuota");
    return temp;
}

int lengthLista(listaStudenti l) {
    int i = 0;
    while(l!=NULL) {
        i++;
        l=l->next;
    }
    return i;
}

void deleteInTesta(listaStudenti* l) {
    listaStudenti temp;
    temp=*l;
    *l=temp->next;
    free(temp);
}

void deleteInPosizionePrecisa(listaStudenti* l,int pos) {
    listaStudenti prev;
    listaStudenti curr;
    int i=2;
    prev=*l;
    curr=prev->next;
    if(pos==1)
        deleteInTesta(l);
    else {
        while(i<pos) {
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=curr->next;
        free(curr);
    }
}

void deleteStudentePerMedia(listaStudenti* l, int voto) {
    listaStudenti temp;
    temp=*l;
    int i=0;
    while(temp!=NULL) {
        i++;
        if(mediaVoti(temp->info.esami)<voto) {
            deleteInPosizionePrecisa(l, i);
            i--;
        }

        temp=temp->next;
    }
}

void addStudente(listaStudenti* l, string matricola, listaVoti voti) {
    listaStudenti temp=malloc(sizeof(nodoStudente));
    strcpy(temp->info.matricola, matricola);
    temp->info.esami=voti;
    temp->next=*l;
    *l=temp;
}

void stampaStudente(listaStudenti l) {
    while(l!=NULL) {
        printf("La matricola è %s \n", l->info.matricola);
        stampaVoti(l->info.esami);
        l=l->next;
    }
}
