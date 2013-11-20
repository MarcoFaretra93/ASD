//
//  main.c
//  topic
//
//  Created by Marco Faretra on 19/11/13.
//  Copyright (c) 2013 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "persona.h"

int main(int argc, const char * argv[]) {
    listaTopic l1=NULL;
    listaTopic l2=NULL;
    string s1="Natura";
    string s2="Quiz";
    string s3="Ciao";
    string s4="Natura";
    string s5="Ciao";
    string s6="Computer";
    string nome1="Marco";
    string cognome1="Faretra";
    string nome2="Federico";
    string cognome2="Ginosa";
    listaPersone m1;
    persona p1;
    persona p2;
    p1.codice=444;
    strcpy(p1.nome, "Alessio");
    strcpy(p1.cognome, "Zoccoli");
    
    p2.codice=555;
    strcpy(p2.nome, "Gabriele");
    strcpy(p2.cognome, "Giannuzzi Mussolini");
    
    addTopic(&l1, s1, 2);
    addTopic(&l1, s2, 4);
    addTopic(&l1, s3, 6);
    
    addTopic(&l2, s4, 7);
    addTopic(&l2, s5, 2);
    addTopic(&l2, s6, 1);
    
    p1.iLike=l1;
    p2.iLike=l2;
    
    stampaTopic(l1);
    
    printf("la lunghezza della lista è %d\n",lengthListaTopic(l1));
    
    addPersona(&m1, 1, nome1, cognome1, l1);
    addPersona(&m1, 2, nome2, cognome2, l2);
    stampaPersone(m1);
    printf("%d\n",preferenzeTopic(m1, "Natura"));
    stampaTopic(l2);
    aggiungiTopicPreferenze(&m1, 2, 0, "Pluto");
    stampaPersone(m1);
    printf("%d\n",topicComune(p1, p2));
    printf("%d\n",topicPreferenzeComune(m1, 1, 2));
    
    
    return 0;
}

