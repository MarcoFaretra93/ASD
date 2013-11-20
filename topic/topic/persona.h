//
//  persona.h
//  topic
//
//  Created by Marco Faretra on 20/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef topic_persona_h
#define topic_persona_h
#include "topic.h"

typedef struct {
    int codice;
    string nome;
    string cognome;
    listaTopic iLike;
}persona;

typedef struct nodoPersone {
    persona info;
    struct nodoPersone* next;
}nodoPersone;

typedef nodoPersone* listaPersone;

int preferenzeTopic(listaPersone, string);

void aggiungiTopicPreferenze(listaPersone*, int, int,string);

int topicComune(persona,persona);

int topicPreferenzeComune(listaPersone , int, int);

void addPersona(listaPersone*, int , string , string , listaTopic);

void stampaPersone(listaPersone);

int lengthListaPersone(listaPersone);

listaTopic *getIlike(listaPersone,int);

#endif
