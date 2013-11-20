//
//  topic.c
//  topic
//
//  Created by Marco Faretra on 19/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include "topic.h"
#include <stdlib.h>
#include <string.h>



void addTopic(listaTopic* l, string nomeAssociato, int codice) {
    nodoTopic* n=malloc(sizeof(nodoTopic));
    strcpy(n->info.nomeAssociato, nomeAssociato);
    n->info.codice=codice;
    n->next=*l;
    *l=n;
}

int lengthListaTopic(listaTopic l) {
    int cont=0;
    while(l!=NULL) {
        cont++;
        l=l->next;
    }
    return cont;
}