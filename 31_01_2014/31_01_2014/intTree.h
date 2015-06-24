//
//  intTree.h
//  31_01_2014
//
//  Created by Marco Faretra on 24/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#ifndef _1_01_2014_intTree_h
#define _1_01_2014_intTree_h
typedef struct nodoAlbero {
    int info;
    struct nodoAlbero* left;
    struct nodoAlbero* right;
}nodoAlbero;

typedef nodoAlbero* albero;

#endif
