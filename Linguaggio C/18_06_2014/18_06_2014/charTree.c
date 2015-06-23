//
//  charTree.c
//  18_06_2014
//
//  Created by Marco Faretra on 23/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "charTree.h"
#include <stdio.h>
#include <stdlib.h>

int distanza(char v1, char v2, albero a) {
    if((v1<a->info && v2>a->info) || (v1>a->info && v2<a->info))
        return 0;
    if(a->info == v1)
        return distanzaRadice(a, v2);
    if(a->info == v2)
        return distanzaRadice(a, v1);
    if(a->left!=NULL)
        return distanza(v1, v2, a->left);
    if(a->right!=NULL)
        return distanza(v1, v2, a->right);
    return 0;
}

int distanzaRadice(albero a, char v) {
    if(a->info == v) {
        return 0;
    }
    if(a->info > v) {
        return 1+distanzaRadice(a->left, v);
    }
    if(a->info < v) {
        return 1+distanzaRadice(a->right, v);
    }
    return 0;
}
