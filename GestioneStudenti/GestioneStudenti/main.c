#include <stdio.h>
#include "studente.h"

int main(int argc, const char * argv[])
{
    listaVoti lv;
    float media;
    
    addVoto(&lv, 18);
    addVoto(&lv, 20);
    addVoto(&lv, 30);
    addVoto(&lv, 23);
    addVoto(&lv, 18);
    
    printVoti(lv);

    media=mediaVoti(lv);
    printf("Media: %f", media);
    return 0;
}

