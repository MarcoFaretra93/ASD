#include <stdio.h>
#include <stdlib.h>
#include "voti.h"
#include "studente.h"

void addStudente(listaStudenti* l, string matricola, listaVoti lv) {
    listaStudenti nuovoStudente=malloc(sizeof(nodoStudente));
    
    strcpy(nuovoStudente->info.matricola, matricola);
    nuovoStudente->info.lv=lv;
    nuovoStudente->next=*l;
    
    *l=nuovoStudente;
}

int isEmpty(listaStudenti ls) {
    if(ls==NULL)
        return 1;
    else
        return 0;
}

int lunghezzaStudente(listaStudenti l) {
    int i=0;
    if(isEmpty(l)==0) {
        while(l->next!=NULL) {
            i++;
            l=l->next;
        }
        i++;
    }
    return i;
}

void rimuoviInTesta(listaStudenti* l) {
    if(*l!=NULL) {
        listaStudenti tmp=*l;
        *l=tmp->next;
        free(tmp);
    }
    else
        printf("La lista e' vuota.");
}

void rimuoviInCoda(listaStudenti* l) {
    listaStudenti tmp=*l;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    free(tmp);
}

void rimuoviInPosizionePrecisa(listaStudenti* l, int posizione) {
    
    int lunghezzaLista=lunghezzaStudente(*l);
    listaStudenti prev, cur;
    
    if(posizione<=lunghezzaLista && posizione>0) {
        switch (posizione) {
            case 1:
                rimuoviInTesta(l);
                break;
            
            default:
                prev=*l;
                cur=prev->next;
                int i=2;
                while(i<posizione) {
                    prev=cur;
                    cur=cur->next;
                    i++;
                }
                prev->next=cur->next;
                free(cur);
                break;
        }
    }
    else
        printf("Inserisci una posizione valida.\n");
}

void printStudenti(listaStudenti ls) {
    if(isEmpty(ls)==0) {
        printf("[");
        while (ls->next!=NULL) {
            printf("(%s)", ls->info.matricola);
            ls=ls->next;
        }
        printf("(%s)", ls->info.matricola);
        printf("]\n");
    }
    else
        printf("La lista e' vuota.\n");
}

void rimuoviMedia(listaStudenti* ls, float media) {
    listaStudenti tmp=*ls;
    int i=1;
    float mediaS;
    while(i<=lunghezzaStudente(*ls)) {
        mediaS=mediaVoti(tmp->info.lv);
        tmp=tmp->next;
        if(mediaS<=media) {
            rimuoviInPosizionePrecisa(ls, i);
        }
        else
            i++;
    }
    
}

studente getStudenteByMatricola(listaStudenti ls, string matricola) {
    studente s;
    if(isEmpty(ls)==0) {
        while (ls->next!=NULL) {
            if(strcmp(ls->info.matricola, matricola)==0) {
                s=ls->info;
                break;
            }
            ls=ls->next;
        }
        if(strcmp(ls->info.matricola, matricola)==0)
            s=ls->info;
    }
    else
        printf("La lista e' vuota.\n");
    
    return s;
}