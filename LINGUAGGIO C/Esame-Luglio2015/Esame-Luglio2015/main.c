//
//  main.c
//  Esame-Luglio2015
//
//  Created by Marco Faretra on 06/07/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "intTree.h"

int main(int argc, const char * argv[]) {
    albero a = malloc(sizeof(nodoAlbero));
    a->info=4;
    
    a->sx=malloc(sizeof(nodoAlbero));
    a->sx->info=3;
    
    a->sx->sx=malloc(sizeof(nodoAlbero));
    a->sx->sx->info=5;
    a->sx->sx->sx=NULL;
    a->sx->sx->dx=NULL;
    
    a->sx->dx=malloc(sizeof(nodoAlbero));
    a->sx->dx->info=7;
    a->sx->dx->sx=NULL;
    a->sx->dx->dx=NULL;
    
    a->dx=malloc(sizeof(nodoAlbero));
    a->dx->info=2;
    
    a->dx->sx=malloc(sizeof(nodoAlbero));
    a->dx->sx->info=9;
    a->dx->sx->sx=NULL;
    a->dx->sx->dx=NULL;

    a->dx->dx=malloc(sizeof(nodoAlbero));
    a->dx->dx->info=10;
    a->dx->dx->sx=NULL;
    a->dx->dx->dx=NULL;
    
    albero a2=malloc(sizeof(nodoAlbero));
    a2->info=18;
    
    a2->sx=malloc(sizeof(nodoAlbero));
    a2->sx->info=2;
    
    a2->sx->sx=malloc(sizeof(nodoAlbero));
    a2->sx->sx->info=10;
    a2->sx->sx->sx=NULL;
    a2->sx->sx->dx=NULL;
    
    a2->sx->dx=malloc(sizeof(nodoAlbero));
    a2->sx->dx->info=7;
    a2->sx->dx->sx=NULL;
    a2->sx->dx->dx=NULL;
    
    a2->dx=malloc(sizeof(nodoAlbero));
    a2->dx->info=3;
    
    a2->dx->sx=malloc(sizeof(nodoAlbero));
    a2->dx->sx->info=9;
    a2->dx->sx->sx=NULL;
    a2->dx->sx->dx=NULL;
    
    a2->dx->dx=malloc(sizeof(nodoAlbero));
    a2->dx->dx->info=5;
    a2->dx->dx->sx=NULL;
    a2->dx->dx->dx=NULL;
    modificaFile(a);
    
    return 0;
}
