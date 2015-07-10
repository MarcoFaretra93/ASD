//
//  main.c
//  Esercitazione_Gennaio_2015
//
//  Created by Marco Faretra on 28/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "alberi_comune.h"

int main(int argc, const char * argv[]) {
    albero a=malloc(sizeof(nodo_albero));
    a->info=3;
    
    a->left=malloc(sizeof(nodo_albero));
    a->left->info=14;
    
    a->left->left=malloc(sizeof(nodo_albero));
    a->left->left->info=66;
    a->left->left->left=NULL;
    a->left->left->right=NULL;
    
    a->left->right=malloc(sizeof(nodo_albero));
    a->left->right->info=11;
    a->left->right->left=NULL;
    a->left->right->right=NULL;
    
    a->right=malloc(sizeof(nodo_albero));
    a->right->info=22;
    a->right->left=NULL;
    
    a->right->right=malloc(sizeof(nodo_albero));
    a->right->right->info=45;
    a->right->right->left=NULL;
    a->right->right->right=NULL;
    
    albero a2=malloc(sizeof(nodo_albero));
    a2->info=3;
    
    a2->left=malloc(sizeof(nodo_albero));
    a2->left->info=8;
    
    a2->left->left=malloc(sizeof(nodo_albero));
    a2->left->left->info=11;
    a2->left->left->left=NULL;
    a2->left->left->right=NULL;
    
    a2->left->right=malloc(sizeof(nodo_albero));
    a2->left->right->info=45;
    a2->left->right->left=NULL;
    a2->left->right->right=NULL;
    
    a2->right=malloc(sizeof(nodo_albero));
    a2->right->info=10;
    a2->right->left=NULL;
    a2->right->right=NULL;

    return 0;
}
