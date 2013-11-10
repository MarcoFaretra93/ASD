#include <stdio.h>
#include "stringhe.h"

void copia(char *s1, char *s2) {
    int i=0;
    while(s2[i]!='\0') {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
}

int lunghezza(char *s) {
    int i=0;
    while(s[i]!='\0') i++;
    return i;
}

int uguale(char *s1, char *s2) {
    int dev=0, i=0;
    
    if(lunghezza(s1)==lunghezza(s2)) {
        dev=1;
        while(s1[i]!='\0' && dev==1) {
            if(s1[i]!=s2[i])
                dev=0;
            i++;
        }
    }
    
    return dev;
}