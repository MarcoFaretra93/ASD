//
//  charTree.h
//  18_06_2014
//
//  Created by Marco Faretra on 23/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef _8_06_2014_charTree_h
#define _8_06_2014_charTree_h

typedef struct nodoAlbero{
    char info;
    struct nodoAlbero* left;
    struct nodoAlbero* right;
}nodoAlbero;

typedef nodoAlbero* albero;

int distanza(char,char,albero);
int distanzaRadice(albero,char);
#endif
