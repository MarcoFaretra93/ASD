#include <stdio.h>
#include <stdlib.h>
#include "DNA.h"

void addNodo(DNA* l, char c) {
    nodoDNA* nuovoNodo=malloc(sizeof(nodoDNA));
    nuovoNodo->info=c;
    nuovoNodo->next=*l;
    *l=nuovoNodo;
}

int nodoValido(nodoDNA n) {
    int dev;
    switch (n.info) {
        case 'T':
        case 'A':
        case 'G':
        case 'C':
            dev=1;
            break;
        default:
            dev=0;
            break;
    }
    
    return dev;
}

void DNAGen(DNA* l, int DIM) {
    int i;
    char c;
    for(i=0; i<DIM; i++) {
        switch (rand()%4) {
            case 0:
                c='A';
                break;
            
            case 1:
                c='G';
                break;
                
            case 2:
                c='C';
                break;
                
            default:
                c='T';
                break;
        }
        addNodo(l, c);
    }
}

int DNATest(DNA l) {
    int dev=1;
    while(l!=NULL && dev==1) {
        dev=nodoValido(*l);
        l=l->next;
    }
    
    return dev;
}

void rimuoviInTesta(DNA* l) {
    nodoDNA* tmp=*l;
    *l=tmp->next;
    free(tmp);
}

int lunghezzaDNA(DNA l) {
    int i=0;
    while(l!=NULL) {
        i++;
        l=l->next;
    }
    return i;
}

void rimuoviInPosizionePrecisa(DNA* l, int p) {
    nodoDNA *prev, *curr;
    int i;
    
    if(*l!=NULL) {
        if(p>0 && p<=lunghezzaDNA(*l)) {
            switch (p) {
                case 1:
                    rimuoviInTesta(l);
                    break;
                    
                default:
                    i=2;
                    prev=*l;
                    curr=prev->next;
                    while(i<p) {
                        prev=curr;
                        curr=curr->next;
                        i++;
                    }
                    prev->next=curr->next;
                    free(curr);
                    break;
            }
        }
        else
            printf("Inserisci una posizione valida.\n");
    }
    else
        printf("La lista e' vuota.\n");
}

void deleteDNA(DNA* l, char c) {
    DNA tmp=*l;
    int i=1;
    while(tmp!=NULL) {
        if(tmp->info==c)
            rimuoviInPosizionePrecisa(l, i);
        else
            i++;
        tmp=tmp->next;
    }
}

void invertiNodiDNA(DNA* l, char c1, char c2) {
    DNA tmp=*l;
    while(tmp!=NULL) {
        if(tmp->info==c1)
            tmp->info=c2;
        tmp=tmp->next;
    }
}

int matchDNA(DNA l1, DNA l2) {
    int dev=1;
    
    if(lunghezzaDNA(l1)==lunghezzaDNA(l2)) {
        while(l1!=NULL && l2!=NULL && dev==1) {
            if(
               (l1->info=='A' && l2->info!='T') ||
               (l1->info=='T' && l2->info!='A') ||
               (l1->info=='G' && l2->info!='C') ||
               (l1->info=='C' && l2->info!='G'))
                dev=0;
            l1=l1->next;
            l2=l2->next;
        }
    }
    else
        dev=0;
    
    return dev;
}

int equalsDNA(DNA l1, DNA l2) {
    int dev=1;
    if(lunghezzaDNA(l1)==lunghezzaDNA(l2)) {
        while(l1!=NULL && l2!=NULL && dev==1) {
            if(l1->info!=l2->info)
                dev=0;
            l1=l1->next;
            l2=l2->next;
        }
    }
    else
        dev=0;
    
    return dev;
}

int windowDNA(DNA l1, DNA l2) {
    int dev;
    invertitoDNA(&l2);
    if(equalsDNA(l1, l2)==1)
        dev=1;
    else
        dev=0;
    
    return dev;
}

int palindromoDNA(DNA l) {
    DNA l1, l2;
    int lunghezza=lunghezzaDNA(l), dev=1, i;
    
    for(i=0; i<lunghezza/2; i++) {
        addNodo(&l1, l->info);
        rimuoviInTesta(&l);
    }
    
    if(lunghezza%2!=0)
        rimuoviInTesta(&l);
    
    for(i=0; i<lunghezza/2; i++) {
        addNodo(&l2, l->info);
        rimuoviInTesta(&l);
    }
    
    invertitoDNA(&l2);
    
    if(equalsDNA(l1, l2)==0)
        dev=0;
    
    return dev;
}

int confrontaDNA(DNA l1, DNA l2, int t) {
    int i=0;
    int dev;
    while(l1!=NULL && l2!=NULL && i<t) {
        if(l1->info==l2->info)
            i++;
        l1=l1->next;
        l2=l2->next;
    }
    
    if(i>=t)
        dev=1;
    else
        dev=0;
    
    return dev;
}

void commonDNA(DNA l1, DNA l2, DNA* l3) {
    while(l1!=NULL && l2!=NULL) {
        if(l1->info==l2->info)
            addNodo(l3, l1->info);
        l1=l1->next;
        l2=l2->next;
    }
}

void stampaDNA(DNA l) {
    printf("[ ");
    while(l!=NULL) {
        printf("%c ", l->info);
        l=l->next;
    }
    printf("]\n");
}

void invertitoDNA(DNA* l) {
    DNA invertito=malloc(sizeof(nodoDNA));
    invertito=NULL;
    DNA tmp=*l;
    
    while(tmp!=NULL) {
        addNodo(&invertito, tmp->info);
        tmp=tmp->next;
    }
    
    *l=invertito;
}