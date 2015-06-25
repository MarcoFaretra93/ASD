//
//  tree.h
//  Febbraio2015
//
//  Created by Marco Faretra on 25/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef Febbraio2015_tree_h
#define Febbraio2015_tree_h

typedef struct elem {
    char info;
    struct elem* left;
    struct elem* right;
}nodo_albero;

typedef nodo_albero* albero;

void aggiungi(albero*,char,char);

int esiste_foglia(albero,char);

void stampaAlbero(albero);

void somma(albero*,albero);
#endif
