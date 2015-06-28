//
//  treeStradario.c
//  Esercitazione-strade
//
//  Created by Marco Faretra on 27/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "treeStradario.h"
#include <string.h>
#include <stdio.h>

int verificaStrada(alberoStradario a, string strada1, string strada2) {
    if(a!=NULL) {
        if(strcmp(a->info, strada1)==0)
            return verificaStradaDaRadice(a->left, strada2)||verificaStradaDaRadice(a->right, strada2);
        else {
            return verificaStrada(a->left, strada1, strada2) || verificaStrada(a->right, strada1, strada2);
        }
    }
    else
        return 0;
}

int verificaStradaDaRadice(alberoStradario a, string strada) {
    if(a!=NULL) {
        if(strcmp(a->info, strada)==0)
            return 1;
        return verificaStradaDaRadice(a->left, strada) || verificaStradaDaRadice(a->right, strada);
    }
    else
        return 0;
}

int verificaCiclo(alberoStradario a, string strada) {
    return verificaStrada(a, strada, strada);
}

int stradariConnessi(alberoStradario a1,alberoStradario a2) {
    if(a1!=NULL) {
        if(a1->left==NULL && a1->right==NULL)
            return verificaStradaDaRadice(a2, a1->info);
        return stradariConnessi(a1->left, a2)||stradariConnessi(a1->right, a2);
    }
    else
        return 0;
}


int contiene(alberoStradario a1,alberoStradario a2) {
    if(a2==NULL) return 1;
    if(a1!=NULL) {
        return strcmp(a1->info, a2->info)==0 && contiene(a1->left, a2->left) && contiene(a1->right, a2->right);
    }
    else
        return 0;
}

int verificaQuartiere(alberoStradario a1, alberoStradario a2) {
    if(a1==NULL) return 0;
    if(a2==NULL) return 1;
    else {
        if(strcmp(a1->info, a2->info)==0) {
            if(contiene(a1, a2))
                return 1;
        }
        return verificaQuartiere(a1->left, a2)||verificaQuartiere(a1->right, a2);
    }
}

