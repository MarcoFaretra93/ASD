//
//  main.c
//  31_01_2014
//
//  Created by Marco Faretra on 24/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "intList.h"

int main(int argc, const char * argv[]) {
    albero a =malloc(sizeof(nodoAlbero));
    a->info=15;
    
    a->left=malloc(sizeof(nodoAlbero));
    a->left->info=10;
    a->left->right=NULL;
    
    a->left->left=malloc(sizeof(nodoAlbero));
    a->left->left->info=8;
    
    a->left->left->left=malloc(sizeof(nodoAlbero));
    a->left->left->left->info=5;
    a->left->left->left->left=NULL;
    a->left->left->left->right=NULL;
    
    a->left->left->right=malloc(sizeof(nodoAlbero));
    a->left->left->right->info=9;
    a->left->left->right->left=NULL;
    a->left->left->right->right=NULL;
    
    a->right=malloc(sizeof(nodoAlbero));
    a->right->info=25;
    
    a->right->left=malloc(sizeof(nodoAlbero));
    a->right->left->info=19;
    a->right->left->left=NULL;
    a->right->left->right=NULL;
    
    a->right->right=malloc(sizeof(nodoAlbero));
    a->right->right->info=29;
    a->right->right->left=NULL;
    a->right->right->right=NULL;
    
    albero a2 =malloc(sizeof(nodoAlbero));
    a2->info=15;
    
    a2->left=malloc(sizeof(nodoAlbero));
    a2->left->info=10;
    a2->left->right=NULL;
    
    a2->left->left=malloc(sizeof(nodoAlbero));
    a2->left->left->info=8;
    
    a2->left->left->left=malloc(sizeof(nodoAlbero));
    a2->left->left->left->info=5;
    a2->left->left->left->left=NULL;
    a2->left->left->left->right=NULL;
    
    a2->left->left->right=malloc(sizeof(nodoAlbero));
    a2->left->left->right->info=9;
    a2->left->left->right->left=NULL;
    a2->left->left->right->right=NULL;
    
    a2->right=malloc(sizeof(nodoAlbero));
    a2->right->info=25;
    
    a2->right->left=malloc(sizeof(nodoAlbero));
    a2->right->left->info=19;
    a2->right->left->left=NULL;
    a2->right->left->right=NULL;
    
    a2->right->right=malloc(sizeof(nodoAlbero));
    a2->right->right->info=29;
    
    a2->right->right->left=malloc(sizeof(nodoAlbero));
    a2->right->right->left->info=28;
    a2->right->right->left->right=NULL;
    a2->right->right->left->left=NULL;
    
    a2->right->right->right=malloc(sizeof(nodoAlbero));
    a2->right->right->right->info=31;
    a2->right->right->right->left=NULL;
    a2->right->right->right->right=NULL;
    
    return 0;
}
