#include <stdio.h>
#include "DNA.h"

int main(int argc, const char * argv[])
{

    DNA l1  =   NULL,
        l2  =   NULL,
        l3  =   NULL,
        l4  =   NULL,
        l5  =   NULL,
        l6  =   NULL,
        l7  =   NULL,
        l8  =   NULL,
        l9  =   pippo,
        l10 =   NULL,
        l11 =   NULL;
    
    printf("\n\n\nTEST DNAGen()\n");
    DNAGen(&l1, 30);
    stampaDNA(l1);
    
    
    printf("\n\n\nTEST DNATest() 1\n");
    addNodo(&l2, 'A');
    addNodo(&l2, 'G');
    addNodo(&l2, 'T');
    addNodo(&l2, 'C');
    stampaDNA(l2);
    if(DNATest(l2)==1) {
        printf("Il DNA e' valido.\n");
    }
    else
        printf("Il DNA non e' valido.\n");
    
    
    printf("\n\n\nTEST DNATest() 2\n");
    addNodo(&l2, 'A');
    addNodo(&l2, 'G');
    addNodo(&l2, 'T');
    addNodo(&l2, 'Z');
    stampaDNA(l2);
    if(DNATest(l2)==1) {
        printf("Il DNA e' valido.\n");
    }
    else
        printf("Il DNA non e' valido.\n");
    
    
    printf("\n\n\nTEST lunghezzaDNA()\n");
    addNodo(&l3, 'A');
    addNodo(&l3, 'G');
    addNodo(&l3, 'T');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    addNodo(&l3, 'A');
    stampaDNA(l3);
    printf("Questo DNA e' lungo %d.\n", lunghezzaDNA(l3));
    

    printf("\n\n\nTEST rimuoviInTesta()\n");
    stampaDNA(l1);
    rimuoviInTesta(&l1);
    stampaDNA(l1);
    
    printf("\n\n\nTEST rimuoviInPosizionePrecisa() nella posizione 1\n");
    stampaDNA(l1);
    rimuoviInPosizionePrecisa(&l1, 1);
    stampaDNA(l1);
    
    printf("\n\n\nTEST rimuoviInPosizionePrecisa() nella posizione 4\n");
    stampaDNA(l1);
    rimuoviInPosizionePrecisa(&l1, 4);
    stampaDNA(l1);
    
    printf("\n\n\nTEST rimuoviInPosizionePrecisa() nell'ultima posizione\n");
    stampaDNA(l1);
    rimuoviInPosizionePrecisa(&l1, lunghezzaDNA(l1));
    stampaDNA(l1);
    
    printf("\n\n\nTEST deleteDNA() cancella carattere 'A'\n");
    stampaDNA(l1);
    deleteDNA(&l1, 'A');
    stampaDNA(l1);
    
    printf("\n\n\nTEST invertitoDNA()\n");
    addNodo(&l4, 'A');
    addNodo(&l4, 'G');
    addNodo(&l4, 'G');
    addNodo(&l4, 'A');
    addNodo(&l4, 'G');
    addNodo(&l4, 'T');
    addNodo(&l4, 'C');
    stampaDNA(l4);
    invertitoDNA(&l4);
    stampaDNA(l4);
    
    
    printf("\n\n\nTEST invertiNodiDNA() sostituisci G con T\n");
    stampaDNA(l4);
    invertiNodiDNA(&l4, 'G', 'T');
    stampaDNA(l4);
    

    printf("\n\n\nTEST matchDNA() controlla che siano a coppia AT e GC\n");
    addNodo(&l5, 'A');
    addNodo(&l6, 'T');
    
    addNodo(&l5, 'G');
    addNodo(&l6, 'C');
    
    addNodo(&l5, 'A');
    addNodo(&l6, 'T');
    
    addNodo(&l5, 'A');
    addNodo(&l6, 'T');
    stampaDNA(l5);
    stampaDNA(l6);
    
    if(matchDNA(l5, l6)==1)
        printf("I DNA sono t-dipendenti.\n");
    else
        printf("I DNA non sono t-dipendenti.\n");
    
    
    printf("\n\n\nTEST windowDNA() controlla che le due liste siano a specchio.\n");
    addNodo(&l7, 'A');
    addNodo(&l7, 'G');
    addNodo(&l7, 'C');
    addNodo(&l7, 'T');
    addNodo(&l8, 'T');
    addNodo(&l8, 'C');
    addNodo(&l8, 'G');
    addNodo(&l8, 'A');
    stampaDNA(l7);
    stampaDNA(l8);
    
    if(windowDNA(l7, l8)==1)
        printf("Ok, sono due liste a specchio.\n");
    else
        printf("Le due liste NON sono a specchio.\n");
    
    printf("\n\n\nTEST windowDNA() controlla che le due liste siano a specchio.\n");
    addNodo(&l8, 'T');
    
    stampaDNA(l7);
    stampaDNA(l8);
    
    if(windowDNA(l7, l8)==1)
        printf("Ok, sono due liste a specchio.\n");
    else
        printf("Le due liste NON sono a specchio.\n");
    
    
    printf("\n\n\nTEST confrontaDNA() confronta che ci siano almeno 2 caratteri che coincidono per posizione.\n");
    addNodo(&l9, 'T');
    addNodo(&l10, 'T');
    
    addNodo(&l9, 'A');
    addNodo(&l10, 'A');
    
    stampaDNA(l9);
    stampaDNA(l10);
    
    if(confrontaDNA(l9, l10, 2)==1)
        printf("Le due sequenze hanno almeno due caratteri che combaciano.\n");
    else
        printf("Non combacia almeno due caratteri.\n");
    
    
    printf("\n\n\nTEST commonDNA() crea una terza lista che contiene i nodi uguali nelle prime due liste.\n");
    addNodo(&l9, 'T');
    addNodo(&l10, 'A');
    
    addNodo(&l9, 'A');
    addNodo(&l10, 'A');
    
    addNodo(&l9, 'A');
    addNodo(&l10, 'T');
    
    stampaDNA(l9);
    stampaDNA(l10);
    
    commonDNA(l9, l10, &l11);
    
    stampaDNA(l11);
    

    return 0;
}

