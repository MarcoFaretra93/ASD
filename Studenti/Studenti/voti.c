//
//  voti.c
//  Studenti
//
//  Created by Marco Faretra on 13/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include "voti.h"
#include <stdlib.h>
#include <stdio.h>

float mediaVoti(listaVoti l) {
    float media = 0.0;
    int i = 0;
    while(l!=NULL) {
        media=media+l->info;
        i++;
        l=l->next;
    }
    media=media/i;
    return media;
}

void addVoto(listaVoti* l, int voto) {
    listaVoti temp=malloc(sizeof(nodoVoto));
    temp->info=voto;
    temp->next=*l;
    *l=temp;
}

void stampaVoti(listaVoti l) {
    while(l!=NULL) {
        printf("i voti dello studente sono %d \n", l->info);
        l=l->next;
    }
}