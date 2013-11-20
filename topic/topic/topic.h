//
//  topic.h
//  topic
//
//  Created by Marco Faretra on 19/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#ifndef topic_topic_h
#define topic_topic_h

typedef char string[50];

typedef struct  {
    int codice;
    string nomeAssociato;
}topic;

typedef struct nodoTopic {
    topic info;
    struct nodoTopic* next;
}nodoTopic;

typedef nodoTopic* listaTopic;

int lengthListaTopic(listaTopic);

void addTopic(listaTopic*, string, int);

void stampaTopic(listaTopic);

#endif
