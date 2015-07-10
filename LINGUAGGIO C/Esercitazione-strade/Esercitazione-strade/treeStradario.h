//
//  treeStradario.h
//  Esercitazione-strade
//
//  Created by Marco Faretra on 27/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef Esercitazione_strade_treeStradario_h
#define Esercitazione_strade_treeStradario_h

typedef char string[50];

typedef struct nodoStradario {
    string info;
    struct nodoStradario* left;
    struct nodoStradario* right;
}nodoStradario;

typedef nodoStradario* alberoStradario;

int verificaStrada(alberoStradario,string,string);

int verificaStradaDaRadice(alberoStradario, string);

int verificaCiclo(alberoStradario, string);

int stradariConnessi(alberoStradario,alberoStradario);

int verificaQuartiere(alberoStradario,alberoStradario);

int contiene(alberoStradario,alberoStradario);

#endif
