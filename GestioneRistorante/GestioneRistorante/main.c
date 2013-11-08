#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordinazione.h"


int main(int argc, const char * argv[])
{
    listaOrdinazione l;
    listaPortate a=NULL, b=NULL, c=NULL, d=NULL, e=NULL;
    
    char risposta;
    int codiceO, codiceP, media, i=1;
    string descrizione;
    
    addPortata(&a, 100, "spaghetti");
    addPortata(&a, 50, "pasta");
    addOrdinazione(&l, 1, a);
    
    addPortata(&b, 10, "pizza");
    addPortata(&b, 5, "pane");
    addOrdinazione(&l, 2, b);
    
    addPortata(&c, 20, "carne");
    addPortata(&c, 30, "bistecca");
    addOrdinazione(&l, 3, c);
    
    addPortata(&d, 500, "focaccia");
    addPortata(&d, 100, "tonno");
    addPortata(&d, 100, "tonno");
    addOrdinazione(&l, 4, d);
    
    printf("Inserire il codice dell'ordinazione: ");
    scanf("%d", &codiceO);
    
    do {
        printf("\nInserire prezzo portata numero %d: ", i);
        scanf("%d", &codiceP);
        
        
        printf("\nInserire descrizione portata: ");
        scanf("%s", descrizione);
        
        addPortata(&e, codiceP, descrizione);
        i++;
        
        addPortata(&e, codiceP, descrizione);
        
        printf("\nVuoi continuare ad inserire le portate? (Y/N): ");
        scanf(" %c", &risposta);
    }
    while(risposta=='y' || risposta=='Y');
    
    addOrdinazione(&l, codiceO, e);
    
    printf("Inserire il codice di cui si vuole conoscere la media: ");
    scanf("%d", &codiceO);
    printf("La media e' %d.\n", getMediaByCod(l, codiceO));
    
    printf("Inserire la media al di sotto del quale si vuole rimuovere: ");
    scanf("%d", &media);
    rimuoviOrdinazionePerMedia(&l, media);
    
    stampaOrdinazioni(l);
    
    free(l);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    
    return 0;
}