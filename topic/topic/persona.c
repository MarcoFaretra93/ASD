//
//  persona.c
//  topic
//
//  Created by Marco Faretra on 20/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include "persona.h"
#include <string.h>
#include <stdlib.h>

int preferenzeTopic(listaPersone l, string nomeTopic) {
    int cont=0;
    while(l!=NULL) {
        while(l->info.iLike!=NULL) {
            if(strcmp(l->info.iLike->info.nomeAssociato,nomeTopic)==0)
                cont++;
            l->info.iLike=l->info.iLike->next;
        }
        l=l->next;
    }
    return cont;
}

void aggiungiTopicPreferenze(listaPersone* l, int codiceCp, int codiceTp, string nomeTopic) {
    listaTopic *lt=getIlike(*l,codiceCp);
    nodoTopic* n=malloc(sizeof(nodoTopic));
    listaTopic prev;
    listaTopic curr;
    n->info.codice=codiceTp;
    strcpy(n->info.nomeAssociato, nomeTopic);
    
    if(lengthListaTopic(*lt)==0 || codiceTp<(*lt)->info.codice) {
        addTopic(lt, nomeTopic, codiceTp);
    }
    else {
        prev=*lt;
        curr=prev->next;

        while(curr!=NULL && codiceTp>curr->info.codice) {
            prev=curr;
            curr=curr->next;
        }
        n->next=curr;
        prev->next=n;
    }
}

listaTopic* getIlike(listaPersone l,int codice) {
    while(l->info.codice!=codice) {
        l=l->next;
    }
    return &(l->info.iLike);
}

int topicComune(persona p1,persona p2) {
    int risultato = 0;
    persona temp;
    while(p1.iLike!=NULL) {
        temp=p2;
        while(temp.iLike!=NULL) {
            if(p1.iLike->info.codice==temp.iLike->info.codice)
                risultato++;
            temp.iLike=temp.iLike->next;
        }
        p1.iLike=p1.iLike->next;
    }
    return risultato;
}

int topicPreferenzeComune(listaPersone l, int cp1, int cp2) {
    int cont=0;
    listaPersone x=l;
    while(l!=NULL && l->info.codice!=cp1)
        l=l->next;
    while(x!=NULL && x->info.codice!=cp2)
        x=x->next;
    cont=topicComune(l->info, x->info);
    return cont;
}

void stampaTopic(listaTopic l) {
    while(l!=NULL) {
        printf("Il codice del topic è %d e il nome del topic è %s\n",l->info.codice, l->info.nomeAssociato);
        l=l->next;
    }
}

void addPersona(listaPersone* l, int codice, string nome, string cognome, listaTopic iLike) {
    nodoPersone* n=malloc(sizeof(nodoPersone));
    n->info.codice=codice;
    strcpy(n->info.nome, nome);
    strcpy(n->info.cognome, cognome);
    n->info.iLike=iLike;
    n->next=*l;
    *l=n;
}

void stampaPersone(listaPersone l) {
    while(l!=NULL) {
        printf("l'id della persona è: %d \n il nome è: %s \n il cognome è: %s\n",l->info.codice, l->info.nome, l->info.cognome);
        printf(" e la lista è: ");
        stampaTopic(l->info.iLike);
        l=l->next;
    }
}

int lengthListaPersone(listaPersone l) {
    int risultato=0;
    while(l!=NULL) {
        risultato++;
        l=l->next;
    }
    return risultato;
}