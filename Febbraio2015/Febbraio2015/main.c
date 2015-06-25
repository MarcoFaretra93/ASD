//
//  main.c
//  Febbraio2015
//
//  Created by Marco Faretra on 25/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
    albero a = malloc(sizeof(nodo_albero));
    a->info='a';
    
    a->left=malloc(sizeof(nodo_albero));
    a->left->info='b';
    a->left->left=NULL;
    a->left->right=NULL;
    
    a->right=malloc(sizeof(nodo_albero));
    a->right->info='c';
    
    a->right->left=malloc(sizeof(nodo_albero));
    a->right->left->info='e';
    a->right->left->left=NULL;
    a->right->left->right=NULL;
    
    a->right->right=malloc(sizeof(nodo_albero));
    a->right->right->info='g';
    a->right->right->left=NULL;
    a->right->right->right=NULL;
    
    albero a2=malloc(sizeof(nodo_albero));
    a2->info='g';
    
    a2->left=malloc(sizeof(nodo_albero));
    a2->left->info='d';
    a2->left->left=NULL;
    a2->left->right=NULL;
    
    a2->right=malloc(sizeof(nodo_albero));
    a2->right->info='h';
    a2->right->left=NULL;
    
    a2->right->right=malloc(sizeof(nodo_albero));
    a2->right->right->info='e';
    a2->right->right->right=NULL;
    
    a2->right->right->left=malloc(sizeof(nodo_albero));
    a2->right->right->left->info='f';
    a2->right->right->left->left=NULL;
    a2->right->right->left->right=NULL;
    
    somma(&a, a2);
    
    stampaAlbero(a);
    
    return 0;
}
