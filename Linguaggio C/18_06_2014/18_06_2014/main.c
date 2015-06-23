//
//  main.c
//  18_06_2014
//
//  Created by Marco Faretra on 23/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "intList.h"


int main(int argc, const char * argv[]) {
    lista l;
    albero a = malloc(sizeof(nodoAlbero));
    a->info='k';
    
    a->left=malloc(sizeof(nodoAlbero));
    a->left->info='e';
    
    a->left->left=malloc(sizeof(nodoAlbero));
    a->left->left->info='b';
    
    a->left->left->left=malloc(sizeof(nodoAlbero));
    a->left->left->left->info='a';
    a->left->left->left->right=NULL;
    a->left->left->left->left=NULL;
    
    a->left->left->right=malloc(sizeof(nodoAlbero));
    a->left->left->right->info='c';
    a->left->left->right->left=NULL;
    a->left->left->right->right=NULL;
    
    a->left->right=malloc(sizeof(nodoAlbero));
    a->left->right->info='f';
    a->left->right->left=NULL;
    a->left->right->right=NULL;
    
    a->right=malloc(sizeof(nodoAlbero));
    a->right->info='m';
    
    a->right->left=malloc(sizeof(nodoAlbero));
    a->right->left->info='l';
    a->right->left->right=NULL;
    a->right->left->left=NULL;
    
    a->right->right=malloc(sizeof(nodoAlbero));
    a->right->right->info='s';
    a->right->right->left=NULL;
    a->right->right->right=NULL;
    
   
    
    modificaFile(a);
  
    return 0;
}
