//
//  charTree.c
//  18_06_2014
//
//  Created by Marco Faretra on 23/06/15.
//  Copyright (c) 2015 Marco Faretra. All rights reserved.
//

#include "charTree.h"
#include "bloccoFile.h"
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

void modificaFile(albero a) {
    FILE *fp=fopen("/Users/marcofaretra/Desktop/distanze.dat", "rb+");
    bloccoFile bf[3];
    long pos=0;
    if(fp==NULL) {
        printf("Errore open");
    }
    else {
        while(fread(bf, sizeof(bloccoFile), 1, fp)>0) {
            if(distanza(bf[0].c1,bf[0].c2,a) != (bf[0].z-48)) {
                fseek(fp, pos, SEEK_SET);
                bf[0].z=distanza(bf[0].c1, bf[0].c2, a)+48;
                fwrite(bf, sizeof(bloccoFile), 1, fp);
            }
            pos=ftell(fp);
        }
    }
    fclose(fp);
}
