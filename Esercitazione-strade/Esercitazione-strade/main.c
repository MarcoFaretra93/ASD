//
//  main.c
//  Esercitazione-strade
//
//  Created by Marco Faretra on 27/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treeStradario.h"


int main(int argc, const char * argv[]) {
    alberoStradario a = malloc(sizeof(nodoStradario));
    strcpy(a->info, "Piazza Fontana");
    
    a->left=malloc(sizeof(nodoStradario));
    strcpy(a->left->info, "Corso Umberto I");
    a->left->right=NULL;
    
    a->left->left=malloc(sizeof(nodoStradario));
    strcpy(a->left->left->info, "Piazza Castello");
    a->left->left->right=NULL;
    
    a->left->left->left=malloc(sizeof(nodoStradario));
    strcpy(a->left->left->left->info, "Via Roma");
    a->left->left->left->left=NULL;
    a->left->left->left->right=NULL;
    
    a->right=malloc(sizeof(nodoStradario));
    strcpy(a->right->info, "Corso Mazzini");
    a->right->right=NULL;
    
    a->right->left=malloc(sizeof(nodoStradario));
    strcpy(a->right->left->info, "Via Galilei");
    a->right->left->left=NULL;
    
    a->right->left->right=malloc(sizeof(nodoStradario));
    strcpy(a->right->left->right->info, "Corso Mazzini");
    a->right->left->right->left=NULL;
    a->right->left->right->right=NULL;
    
    alberoStradario a2=malloc(sizeof(nodoStradario));
    strcpy(a2->info, "Corso Umberto I");
    a2->right=NULL;
    
    a2->left=malloc(sizeof(nodoStradario));
    strcpy(a2->left->info, "Piazza Castello");
    a2->left->right=NULL;
    
    a2->left->left=malloc(sizeof(nodoStradario));
    strcpy(a2->left->left->info, "Corso Mazzini");
    a2->left->left->left=NULL;
    a2->left->left->right=NULL;
    
    
    return 0;
}
